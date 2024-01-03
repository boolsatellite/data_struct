//
// Created by bools on 2024-01-03.
//

/* 0 - 1 背包问题：有一组物品，其重量分别为 w1 ， w2 ， w3 .。。 其价值分别为 v1 ， v2  v3 ..。
 * 现有一个背包，其容量为 C , 问：怎样将物品装入背包才能使价值最大化

 */

#include <vector>
#include <iostream>

int w[] = { 12 , 5 , 8 , 9 , 6};        //物品重量
int v[] = { 9 , 11 , 4 , 7 , 8};        //物品价值
const int length = sizeof(w) / sizeof(w[0]);
int c = 20;                             //背包的容量
int cw = 0;                             //记录已选择物品的重量
int cv = 0;                             //记录已选择物品的价值
int r;                                  //未处理物品的总价值
int bestv = 0;
std::vector<int> x;
std::vector<int> bestx;


void func(int i) {
    if(i == length) {
        if(bestv < cv) {
            bestv = cv;
            bestx = x;
        }
    } else {
        r -= v[i];
        if(cw + w[i] <= c) {
            cw += w[i];
            cv += v[i];
            x.push_back(v[i]);
            func(i + 1);

            cw -= w[i];
            cv -= v[i];
            x.pop_back();
        }

        if(cv + r > bestv) {
            func(i + 1);
        }
        r += v[i];
    }
}

int main() {
    for(auto vi : v) {
        r += vi;
    }
    func(0);
    for(int vi : bestx) {
        std::cout << vi << " ";
    }
}
