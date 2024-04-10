#pragma once
#include <string>
#include <vector>
#include <map>

class Horspool {

public:

//preprocess generate look up table
void setPattern (const std::string& pat);

//return currently set pattern 
const std::string& getPattern();

//get all hits of pattern in text
std::vector<size_t> getHits(const std::string& text) const;

protected:

//use the look up table from set pattern to obtain the maximum shift distance given the last character of the current alignment in text
uint32_t getShift (const char last_char) const;

//internal check for text_position
virtual void alignCheck_(const size_t text_pos) const{};

//members
std::string pattern;
int lookupTable[128];
size_t patt_leng;

};