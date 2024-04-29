#include <iostream>
#include <string>
#include <vector>
#include "sufarr.hpp"

using namespace std;

int main(int argc, const char* argv[]){ //checks the number of arguments passed

    //initializes the suffix array and the vector for hits
    vector<uint32_t> sa;
    vector<uint32_t> hits;

    //if only one argument (the text) is given 
    if(argc == 2){

        construct(sa, argv[1]); //only construct the suffix array for the given text

        for (const auto& elem : sa){ //outputs the indexes of suffix array line by line
             cout << elem << endl;
        }
        reutrn o;
    }


    //if text and one or more queries are given
    if(argc >=3 ){

        construct(sa, argv[1]); 

        find(argv[i], sa, argv[1], hits); // search for the current query in the text

        cout << argv[i] << ": ";
        for(const auto& elem : hits){
             cout << elem << " ";
         }
        cout << endl; //outputs the hits
    }   
    return 0;

    }else{
    cout << "Unexpected input" << endl;
    return -1; // return error code
}