#include "Particle.h"



Particle::Particle()
{
	Particle(vec{ 0, 0, 0 });
}

Particle::Particle(vec position) : position(position)
{
}


Particle::~Particle()
{
}

const vec & Particle::getPosition() const
{
	return position;
}

void Particle::setPosition(vec position)
{
	this->position = position;
}
