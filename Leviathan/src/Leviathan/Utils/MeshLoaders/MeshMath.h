#pragma once

#include <glm/glm.hpp>
#include "Leviathan/Core/Log.h"

namespace algo {

	uint32_t* triangulateFace(uint32_t* indices) //Assumes all polgons are convex
	{

		const int length = sizeof(indices) / sizeof(uint32_t);
		if (length <= 3) 
		{
			if (length != 3) {
				LE_CORE_ERROR("INVALID FACE: {0} VERTICES");
			}
			return indices;
		}

		uint32_t output[length] = {};

		// n-gon can be divided into n - 2 triangles
		// 0 1 2  3 4 5
		uint32_t offset = 0;
		for(int i = 0; i < length - 2; i++) 
		{
			
			output[offset++] = indices[0];
			output[offset++] = indices[i + 1];
			output[offset++] = indices[i + 2];
			
		}

		return output;

	}


}