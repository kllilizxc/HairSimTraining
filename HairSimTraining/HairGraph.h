#pragma once
#include <map>
#include "Edge.h"
#include "HairRaw.h"

class HairGraph
{
public:
	explicit HairGraph(HairRaw raw);
	~HairGraph();
	void build();
	void pruneEdges();
	void CalculateWeight();
private:
	std::map<std::pair<int, int>, Edge> edges;
public:
	const std::map<std::pair<int, int>, Edge>& getEdges() const;
private:
	HairRaw raw;

public:
	const HairRaw& getRaw() const;
private:
	const double DISTANCE_THRESHOLD = 0; //TODO
	const double PRUNE_RATIO = 0.2;
};

