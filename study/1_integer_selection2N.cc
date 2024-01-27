//
// Created by bools on 2023-12-29.
//

/*
 * 给定 2n 个整数，从里面挑选出 n 个整数，让选择的整数的和，和剩下的整数的和差值最小
 *
 */

#include <iostream>
#include <vector>

int arr[] = {12, 6, 7, 11, 16, 3, 8, 9};
const int length = sizeof(arr) / sizeof(arr[0]);
std::vector<int> x;                 //记录子集中所选数字的和
std::vector<int> bestx;             //记录最优解
unsigned int min = 0xffffffff;
int sum = 0;                        //记录子集中所选数字的和
int r = 0;                          //记录未选择数字的和
int left = length;


void func(int i) {
    if (i == length) {               //到达叶子节点
        if (x.size() != length / 2) return;

        int result = abs(sum - r);
        if (result < min) {
            min = result;
            for(int j=0 ; j<length ;++j) {
                bestx = x;
            }
        }

    } else {
        left--;                         //用于表示可被选择的节点个数
        if(x.size() < length / 2) {     //减左枝,当选择节点数大于 n 时将不会继续遍历左枝
            x.push_back(arr[i]);
            sum += arr[i];
            r -= arr[i];
            func(i + 1);
            sum -= arr[i];
            r += arr[i];
            x.pop_back();

        }

        if(x.size() + left >= length / 2) {      //当已选择的 + 可以被选择 的节点个数 任然小于 n 就不需要继续向右枝寻找了
            func(i + 1);
        }
        left++;
    }

}


int main() {
    for (int v: arr) {
        r += v;
    }

    func(0);

    std::cout << "min: " << min << std::endl;
    for(auto v : bestx) {
        std::cout << v <<" ";
    }

}

