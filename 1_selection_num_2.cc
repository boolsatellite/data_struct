//
// Created by bools on 31/12/2023.
//
#include <vector>
#include <iostream>


int arr[] = {4, 8, 12, 16, 7, 9 , 3};
int length = sizeof(arr) / sizeof(arr[0]);
int sum = 18;
std::vector<int> vec;       //存放选择的数字

void func(int i , int number) {
    if(number == 0) {
         for(auto v : vec) {
             std::cout << v << " ";
         }
         std::cout << std::endl;
    } else {
        for(int k=i ; k<length ; ++k) {
            if(number >= arr[k]) {
                vec.push_back(arr[k]);
                func(k+1 , number - arr[k]);        //不可重复选择
                //func(k , number - arr[k]);        //数字可以重复选择
                vec.pop_back();
            }
        }
    }
}

int main() {
    func(0 , 4);
}


