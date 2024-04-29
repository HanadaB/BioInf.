#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include "horspool.hpp"

using namespace std;

void Horspool::setPattern( const std::string& pat){

    pattern = pat;
    patt_leng = pat.length();

    for(int i = 0; i < 128; i++){
        lookupTable[i] = patt_leng;
    }

    for(size_t j = 0; j < patt_leng - 1; j++){
        lookupTable[static_cast<int>(pat[j])] = patt_leng -1 -j;
    }

} 

const std::string& Horspool::getPattern() const{
    return pattern;
}


std::vector<size_t> Horspool::getHits(const std::string& text) const{

    std::vector<size_t>indices;
    int pos = -1;
    size_t t_leng = text.length();

    while(pos < ((static_cast<int>(t_leng)) - (static_cast<int>(patt_leng)))){

        int j = patt_leng;
        alignCheck_(pos + 1);

        while((j > 0) && (text[pos + j] == pattern [j - 1])){
            j--;
        }

        if (j == 0) indices.push_back(pos + 1);

        pos+= getShift_(text [pos + patt_leng]);
        
    }

    return indices;
}

uint32_t Horspool::getShift_(const char last_char) const {

    return lookupTable[static_cast<int>(last_char)];
}