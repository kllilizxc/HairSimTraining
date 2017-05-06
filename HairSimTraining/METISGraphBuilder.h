#pragma once

#include <metis.h>

namespace HairSim
{
	class METISGraphBuilder
	{
	public:
		METISGraphBuilder();
		~METISGraphBuilder();
	private:
		idx_t nvtxs;
	};
}

