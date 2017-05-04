#pragma once

#include "ParticleTransform.h"
#include "HairFrame.h"

class HairTransform
{
public:
	HairTransform();
	~HairTransform();
	void build(HairFrame &from, HairFrame &to);
private:
	std::vector<ParticleTransform> transforms;
public:
	const std::vector<ParticleTransform>& getTransforms() const;
};

