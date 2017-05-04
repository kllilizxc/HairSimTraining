#include "HairTransform.h"



HairTransform::HairTransform()
{
}


HairTransform::~HairTransform()
{
}

void HairTransform::build(HairFrame& from, HairFrame& to)
{
	for (int i = 0; i < from.getParticles().size(); i++)
	{
		ParticleTransform transform;
		transform.build(from.getParticles().at(i).getPosition(), to.getParticles().at(i).getPosition());
		transforms.push_back(transform);
	}
}

const std::vector<ParticleTransform>& HairTransform::getTransforms() const
{
	return transforms;
}
