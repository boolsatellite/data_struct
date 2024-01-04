//
// Created by bools on 2024-01-04.
//

#include <vector>
#include <iostream>

int arr[] = {1 , 2 ,3 ,4};
int length = sizeof(arr) / sizeof(arr[0]);
std::vector<int> x;


void func(int i) {
    if(i == length) {
        for(auto v : x) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    } else {
        for(int k=i; k<length ; ++k) {
            std::swap(arr[i] , arr[k]);
            x.push_back(arr[i]);
            func(i+1);
            x.pop_back();
            std::swap(arr[i] , arr[k]);
        }
    }
}

int main() {
    func(0);
}


