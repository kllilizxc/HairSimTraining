#pragma once
#include <armadillo>

using namespace arma;

class ParticleTransform
{
public:
	ParticleTransform();
	~ParticleTransform();
	void build(vec from, vec to);
private:
	mat transform;
public:
	const mat& getTransform() const;
};

