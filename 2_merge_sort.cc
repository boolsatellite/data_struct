//
// Created by bools on 2024-01-11.
//
#include <vector>
#include <iostream>

void merge(std::vector<int>& x , int low , int mid , int high) {
    std::vector<int> tem;
    int i = low;
    int j = mid + 1;
    while(i <= mid && j <= high) {
        if(x[i] <=  x[j]) {
            tem.push_back(x[i++]);
        } else {
            tem.push_back(x[j++]);
        }
    }
    while(i <= mid) {
        tem.push_back(x[i++]);
    }
    while(j <= high) {
        tem.push_back(x[j++]);
    }

    for(int k=low ; k<=high ; ++k ) {
        x[k] = tem[k-low];
    }
}

void merge_sort(std::vector<int>& x , int i , int j) {
    if(i >= j) return;
    int mid = (i + j) / 2;
    merge_sort(x , i , mid);
    merge_sort(x , mid + 1 , j);

    //回溯时在[i , mid] 和 [mid+1 , j]上合并排序
    merge(x , i , mid , j);
}

int main() {
    std::vector<int> v;
    for(int i=0 ; i<10 ;i++) {
        v.push_back(rand() % 100);
    }
    for(auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    merge_sort(v , 0 , 9);
    for(auto i : v) {
        std::cout << i << " ";
    }
}