#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include "sufarr.hpp"
using namespace std;

//Function to build a suffix array and sort it
void construct(vector<uint32_t>& sa, const string& text){

    sa.clear(); //clears the existing suffix array
    sa.resize(text.size()); //set the size of the suffix array according to the text length
    for( size_t i = 0; i < text.size(); ++i){
        sa[i] = i;
    } // fills the suffix array with the starting indices of suffixes

    sort(sa.begin(), sa.end(), [&text](const uint32_t a, const uint32_t b ){

        return strcmp(text.c_str() + a , text.c_str() + b) < 0;
        //compare the suffixes starting at indices a and b by using strcmp
        //strcmp compares the two suffixes and returns a value less than o
        //if the first suffix (at a) is lexicographically smaller than the second (at b)

    });
}

// Helper function to determine the left boundary in binary search

int findLp(const string& query, const vector<uint32_t>& sa, const string& text){

    int l = 0, r = sa.size(); //start and the end points of search

    while (l < r){
        
        int mid = l +(r-l) / 2; //midpoint of the current search

        //compares the midpoint with the query
        if(text.compare(sa[mid], query.size(), query) < 0){ 

            l = mid + 1; //moves the starting point if the midpoint is greater or equal
        }else{
            r =  mid; //moves the ending point if the midpoint is smaller
        }

    }
    return l; // return the left boundary
}

// Helper function to determine the right boundary in binary search

int findRp(const string& query, const vector<uint32_t>& sa, const string& text){

    int l = 0, r = sa.size(); //start and the end points of search

    while (l < r){
        
        int mid = l +(r-l) / 2; //midpoint of the current search

        //compares the midpoint with the query
        if(text.compare(sa[mid], query.size(), query) <= 0){ 

            l = mid + 1; //moves the starting point if the midpoint is greater or equal
        }else{
            r =  mid; //moves the ending point if the midpoint is smaller
        }

    }
    return r; // return the right boundary
}


// function for searching a query string in the text using a suffix array 
void find(const string& query, const vector<uint32_t>& sa, const string& text, vector<uint32_t>& hits){

hits.clear(); //clears the previous search results
if (query.empty()) return; //end if the query is empty

int Lp = findLp(query, sa, text); // determines the left boundary of the match
int Rp = findRp(query, sa, text); // determines the right boundry of the match

for (int i = Lp; i < Rp; ++i){
    hits.push_back(sa[i]); //adds all the matches between Lp and Rp to the hits vecotr as a result
}

sort(hits.begin(), hits.end()); //sorts the hit indices in ascending order

}