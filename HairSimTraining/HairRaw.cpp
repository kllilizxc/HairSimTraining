#include "HairRaw.h"



HairRaw::HairRaw()
{
}


HairRaw::~HairRaw()
{
	for (auto frame : frames)
	{
		delete frame;
	}
}

Strand & HairRaw::getStrandByParticleIndex(int index)
{
	for (auto strand : strands)
	{
		if (strand.inStrand(index))
			return strand;
	}

	throw "index is not in any strand";
}

void HairRaw::build(std::string filename)
{
	std::ifstream is(filename, std::ifstream::binary);

	int totalParticleSize;
	is.read(reinterpret_cast<char *>(&totalParticleSize), sizeof(int));

	frames.push_back(new HairFrame());
	restState = frames.at(0);
	for (auto i = 0; i < totalParticleSize; i++)
	{
		vec position(3);
		is.read(reinterpret_cast<char *>(&position.at(0)), sizeof(double));
		is.read(reinterpret_cast<char *>(&position.at(1)), sizeof(double));
		is.read(reinterpret_cast<char *>(&position.at(2)), sizeof(double));
		restState->getParticles().at(i).setPosition(position);
	}

	int totalStrandSize;
	is.read(reinterpret_cast<char *>(&totalStrandSize), sizeof(int));

	int index = 0;
	for (auto i = 0; i < totalStrandSize; i++)
	{
		int particleSize;
		is.read(reinterpret_cast<char *>(&particleSize), sizeof(int));

		strands.at(i).setBegin(index);
		strands.at(i).setEnd(index + particleSize);

		index += particleSize;
	}
}

const std::vector<HairFrame*>& HairRaw::getFrames() const
{
	return frames;
}

const std::vector<Strand>& HairRaw::getStrands() const
{
	return strands;
}

HairFrame* const& HairRaw::getRestState() const
{
	return restState;
}
