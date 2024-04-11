#include<iostream>
#include<string>
#include<vector>
#include"horspool.hpp"

using namespace std;

int main(int argc, const char* argv[]){

    if(argc != 3){

        cout << argv[0] << "<TEXT> <PATTERN>" << endl;
    }

    Horspool h;

    h.setPattern(argv[2]);
    auto hits = h.getHits(argv[1]);

    cout << "Horspool search:\n-- Text is: --\n" << argv[1] << "\n-- Hits: --\n";

    for(const auto hit: hits){
        
        cout << std::string(hit,' ') << argv[2] <<endl;
        
    }

return 0;

}