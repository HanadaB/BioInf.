#pragma once
#include <string>
#include <vector>

//Build a sorted suffix array from text

void construct(std::vector<uint32_t>& sa, const std::string& text);

//Search a query string in a text via suffix array, which was constructed and sorted previously
//Query is pattern we look for. Hits is a vector of Indices of hits for query in text, sorted ascending by position in text.

void find(const std::string& query, const std::vector<uint32_t>& sa, const std::string& text, std::vector<uint32_t>& hits);

