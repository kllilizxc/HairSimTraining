#include "Edge.h"


Edge::Edge()
{
	Edge(0, 0);
}

Edge::Edge(int count = 0, double weight = 0) : count(count), weight(weight)
{
}

Edge::~Edge()
{
}

const int Edge::getCount() const
{
	return count;
}

void Edge::setCount(int count)
{
	this->count = count;
}

void Edge::increment()
{
	count++;
}

const double Edge::getWeight() const
{
	return weight;
}

void Edge::setWeight(double weight)
{
	this->weight = weight;
}

void Edge::incrementWeight(double value)
{
	weight += value;
}
