//
// Created by bools on 21/03/2024.
//

#include "vector"
using namespace std;

void reverseString(vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;

    while(i < j) {
        swap(s[i++] , s[j--]);
    }
}