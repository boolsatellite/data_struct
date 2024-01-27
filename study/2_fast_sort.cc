//
// Created by bools on 2024-01-07.
//


#include <vector>
#include <iostream>
#include <algorithm>

void quickSort(std::vector<int>& vec , int i , int j) {
    if(i <= j) return;

    int l = i;
    int r = j;

    int tem = vec[i];
    while(l < r) {
        while(l < r && vec[r] > tem) {
            r--;
        }
        if(l < r && vec[r] < tem) {
            vec[l++] = vec[r];
        }
        while(l < r && vec[l] < tem) {
            l++;
        }
        if(l < r && vec[l] > tem) {
            vec[r--] = vec[l];
        }
    }
    //l == r
    vec[l] = tem;

    quickSort(vec , i , l -1);
    quickSort(vec , l+1 , j);
}

int main() {
    std::vector<int> v;
    for(int i=0 ; i<10 ;i++) {
        v.push_back(rand() % 100);
    }
    quickSort(v , 0 , 10);
    for(auto i : v) {
        std::cout << i << " ";
    }
}