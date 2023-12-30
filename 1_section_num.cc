//
// Created by bools on 2023-12-30.
//


/* 有一组整数，请挑选出一组数字，让他们的和等于指定值，存在解打印，不存在也打印
 * */

#include <vector>
#include <iostream>


int arr[] = {4, 8, 12, 16, 7, 9 , 3};
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
std::vector<int> x;
int sum = 0;                //记录所选数字的和
int count = 0;
int r = 0;                  //记录未操作过元素的总和

void func(int i) {

    if (i == length) {
        count++;
        if(sum == number) {
            std::cout << " sum == number " ;
            for(auto v : x) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    } else {
        r -= arr[i];
        if(sum <= number) {
            sum += arr[i];
            x.push_back(arr[i]);
            func(i + 1);

            sum -= arr[i];
            x.pop_back();
        }

        if(sum + r >= number) {
            func(i + 1);
        }
        r += arr[i];
    }
}


int main() {
    for(auto v : arr) {
        r += v;
    }
    func(0);
    std::cout << count << std::endl;
}


