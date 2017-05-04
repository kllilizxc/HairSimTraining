#pragma once

#include <armadillo>

using namespace arma;

class Particle
{
public:
	Particle();
	Particle(vec position);
	~Particle();
	const vec& getPosition() const;
	void setPosition(vec position);
private:
	vec position;
};

