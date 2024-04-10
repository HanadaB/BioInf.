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

    for(int i = 0; i < 128; ++i){
        lookupTable[i] = patt_leng;
    }

    for(size_t j = 0; j < patt_leng)


} 

