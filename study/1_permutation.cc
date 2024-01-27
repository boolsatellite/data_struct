//
// Created by bools on 6/01/2024.
//

#include <vector>
#include <iostream>

int arr[] = {1, 2, 3};
const int length = sizeof(arr) / sizeof(arr[0]);
std::vector<int> x;
bool state[length];

void func(int i) {
    if(i == length) {
        for(auto v : x) {
            std::cout << v <<" ";
        }
        std::cout << std::endl;
    } else {
        for(int j=0 ; j < length ; ++j) {
            if(!state[j]) {
                x.push_back(arr[j]);
                state[j] = true;
                func(i+1);
                x.pop_back();
                state[j] = false;
            }
        }
    }
}

int main() {
    func(0);
}