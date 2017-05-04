#pragma once

#include "Particle.h"

class HairFrame
{
public:
	HairFrame();
	~HairFrame();
	std::vector<Particle>& getParticles();
private:
	std::vector<Particle> particles;
};

