#include "ReducedHairGraph.h"



ReducedHairGraph::ReducedHairGraph()
{
}


ReducedHairGraph::~ReducedHairGraph()
{
}

void ReducedHairGraph::build(HairGraph graph)
{
	auto& strands = graph.getRaw().getStrands();

	for(auto strand : strands)
	{
		for(auto i = strand.getBegin(); i <= strand.getEnd(); i++)
		{
			for(auto j = strand.getEnd() + 1; j < graph.getRaw().getRestState()->getParticles().size(); j++)
			{
				std::pair<int, int> key(i, j);
				auto& _edges = graph.getEdges();
				auto _weight = _edges.at(key).getWeight();
				if(_edges.find(key) != _edges.end())
				{
					if (edges.find(key) != edges.end())
						edges[key].incrementWeight(_weight);
					else
						edges[key] = Edge(0, _weight);
				}
			}
		}
	}
}
