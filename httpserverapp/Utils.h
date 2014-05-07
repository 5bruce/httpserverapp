﻿#pragma once

#include "RawData.h"
#include "FileIncoming.h"

#include <locale>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>
#include <chrono>
#include <map>
#include <unordered_map>
#include <cctype>

namespace Utils
{
	inline void tolower(std::string &str, std::locale &loc)
	{
		for (auto &c : str)
		{
			c = std::tolower(c, loc);
		}
	}

	void trim(std::string &);

	inline std::string getUniqueName()
	{
		std::stringstream s;
		s << std::hex << std::chrono::high_resolution_clock::now().time_since_epoch().count();
		return s.str();
	}

	char *stlStringToPChar(const std::string &);

	void stlMapToRawPairs(Utils::raw_pair *[], const std::map<std::string, std::string> &);
	void stlMultimapToRawPairs(Utils::raw_pair *[], const std::multimap<std::string, std::string> &);
	void stlUnorderedMapToRawPairs(Utils::raw_pair *[], const std::unordered_map<std::string, std::string> &);
	void stlUnorderedMultimapToRawPairs(Utils::raw_pair *[], const std::unordered_multimap<std::string, std::string> &);
	void filesIncomingToRawFilesInfo(Utils::raw_fileinfo *[], const std::unordered_multimap<std::string, HttpServer::FileIncoming> &);
	void rawPairsToStlMap(std::map<std::string, std::string> &, const Utils::raw_pair [], const size_t);
	void rawPairsToStlMultimap(std::multimap<std::string, std::string> &, const Utils::raw_pair [], const size_t);
	void rawPairsToStlUnorderedMap(std::unordered_map<std::string, std::string> &, const Utils::raw_pair [], const size_t);
	void rawPairsToStlUnorderedMultimap(std::unordered_multimap<std::string, std::string> &, const Utils::raw_pair [], const size_t);
	void rawFilesInfoToFilesIncoming(std::unordered_multimap<std::string, HttpServer::FileIncoming> &, const Utils::raw_fileinfo [], const size_t);
	void destroyRawPairs(Utils::raw_pair [], const size_t);
	void destroyRawFilesInfo(Utils::raw_fileinfo [], const size_t);
};
