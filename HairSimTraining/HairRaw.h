#pragma once

#include "HairFrame.h"
#include "Strand.h"

class HairRaw
{
public:
	HairRaw();
	~HairRaw();
	Strand& getStrandByParticleIndex(int index);
	void build(std::string filename);
	const std::vector<HairFrame*>& getFrames() const;
	const std::vector<Strand>& getStrands() const;
private:
	std::vector<HairFrame *> frames;
	std::vector<Strand> strands;
	HairFrame *restState;
public:
	HairFrame* const& getRestState() const;
};

