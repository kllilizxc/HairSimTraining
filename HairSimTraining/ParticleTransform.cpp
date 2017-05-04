#include "ParticleTransform.h"



ParticleTransform::ParticleTransform()
{
}


ParticleTransform::~ParticleTransform()
{
}

void ParticleTransform::build(vec from, vec to)
{
	Row<double> _to = to;

	Col<double> _from = from;

	transform = _to * _from;
}

const mat& ParticleTransform::getTransform() const
{
	return transform;
}
