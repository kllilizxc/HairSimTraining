#include "HairGraph.h"
#include "HairTransform.h"
#include <armadillo>


HairGraph::HairGraph(HairRaw raw) : raw(raw)
{
}

HairGraph::~HairGraph()
{
}

double magnitute(vec v)
{
	vec _v = pow(v, 2);
	auto _sum = sum(_v);
	return sqrt(_sum);
}

void HairGraph::build()
{
	for(auto frame : raw.getFrames())
	{
		for(auto i = 0; i < frame->getParticles().size(); i++)
		{
			for(auto j = 0; j < frame->getParticles().size(); j++)
			{
				auto particleI = frame->getParticles().at(i);
				auto particleJ = frame->getParticles().at(j);

				if(magnitute(particleI.getPosition() - particleJ.getPosition()) > DISTANCE_THRESHOLD)
				{
					std::pair<int, int> key(i, j);
					if (edges.find(key) != edges.end())
						edges[key].increment();
					else
						edges[key] = Edge(1, 0);
				}
			}
		}
	}

	pruneEdges();
	CalculateWeight();
}

void HairGraph::pruneEdges()
{
	for(auto edge : edges)
	{
		if (edge.second.getCount() < raw.getFrames().size() * PRUNE_RATIO)
			edges.erase(edge.first);
	}
}

void HairGraph::CalculateWeight()
{
	double maxWeight = 0;

	for(auto frame : raw.getFrames())
	{
		HairTransform B;
		B.build(*raw.getRestState(), *frame);

		for (auto item : edges)
		{
			int i = item.first.first;
			int j = item.first.second;
			Edge& edge = item.second;

			auto stateI = frame->getParticles().at(i);
			auto stateJ = frame->getParticles().at(j);

			auto _weight = magnitute(stateI.getPosition() - B.getTransforms().at(j).getTransform() * raw.getRestState()->getParticles().at(i).getPosition())
				+ magnitute(stateJ.getPosition() - B.getTransforms().at(i).getTransform() * raw.getRestState()->getParticles().at(j).getPosition());

			if (maxWeight < _weight) maxWeight = _weight;

			edge.setWeight(edge.getWeight() - _weight);
		}
	}

	for(auto item : edges)
	{
		auto& edge = item.second;
		edge.setWeight(edge.getWeight() + maxWeight);
	}
}

const std::map<std::pair<int, int>, Edge>& HairGraph::getEdges() const
{
	return edges;
}

const HairRaw& HairGraph::getRaw() const
{
	return raw;
}
