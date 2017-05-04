#pragma once
#include <map>
#include "Edge.h"
#include "HairGraph.h"

class ReducedHairGraph
{
public:
	ReducedHairGraph();
	~ReducedHairGraph();
	void build(HairGraph graph);
private:
	std::map<std::pair<int, int>, Edge> edges;
};

