#pragma once

#include "Leviathan/Core/Core.h"
#include "Leviathan/Core/Log.h"
#include <fstream>

namespace Leviathan {

	class FileUtils {
	public:
		static std::string LoadFile(const std::string& filepath) {
			std::string result;
			std::ifstream in(filepath, std::ios::in, std::ios::binary);
			if (in)
			{
				in.seekg(0, std::ios::end);
				result.resize(in.tellg());
				in.seekg(0, std::ios::beg);
				in.read(&result[0], result.size());
				in.close();

			}
			else
			{
				LE_CORE_ERROR("Could not open file '{0}'", filepath);
			}

			return result;
		}


	};
}