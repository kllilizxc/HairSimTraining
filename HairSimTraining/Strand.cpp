#include "Strand.h"

Strand::Strand(int begin = 0, int end = 0) : begin(begin), end(end)
{
}

Strand::~Strand()
{
}

int Strand::getBegin() const
{
	return begin;
}

void Strand::setBegin(int begin)
{
	this->begin = begin;
}

int Strand::getEnd() const
{
	return end;
}

void Strand::setEnd(int end)
{
	this->end = end;
}

bool Strand::inStrand(int index) const
{
	return index >= begin && index <= end;
}
