#pragma once
class Strand
{
public:
	Strand(int begin, int end);
	~Strand();
	int getBegin() const;
	void setBegin(int begin);
	int getEnd() const;
	void setEnd(int end);
	bool inStrand(int index) const;
private:
	int begin;
	int end;
};

