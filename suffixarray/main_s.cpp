#include <iostream>
#include <string>
#include <vector>
#include "sufarr.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    vector<uint32_t> sa;  // Vector to store the suffix array
    vector<uint32_t> hits;  // Vector to store the indices where the query matches

    if (argc == 2) {
        // If there's exactly one argument (the text), construct the suffix array
        construct(sa, argv[1]);
        // Output each element of the suffix array on a new line
        for (const auto& elem : sa) {
            cout << elem << endl;
        }
        return 0;
    } else if (argc >= 3) {
        // If there's one text argument and one or more query arguments
        construct(sa, argv[1]);  // Construct the suffix array for the text
        hits.clear();  // Clear the hits vector for the next query
        // Iterate over each query argument starting from argv[2]
        for (int i = 2; i < argc; ++i) {
            find(argv[i], sa, argv[1], hits);  // Search for the current query in the text
            cout << argv[i] << ": ";
            // Output each matching index for the query
            for (const auto& hit: hits) {
                cout << hit << " ";
            }
            cout << endl;
            
        }
        return 0;
    } else {
        // Handle unexpected input case
        cout << "Unexpected input" << endl;
        return -1; // Return error code if the input arguments are not as expected
    }
}
