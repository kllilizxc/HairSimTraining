#pragma once
class Edge
{
public:
	Edge();
	Edge(int count, double weight);
	~Edge();
	const int getCount() const;
	void setCount(int count);
	void increment();
	const double getWeight() const;
	void setWeight(double weight);
	void incrementWeight(double value);
private:
	int count;
	double weight;
};

