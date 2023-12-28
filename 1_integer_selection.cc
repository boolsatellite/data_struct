//
// Created by bools on 2023-12-28.
//

/*整数选择问题：
 * 给定一组整数，从里面挑选一组整数，让选择的整数的和，和剩下的整数的和差最小
 */

#include <cmath>
#include <iostream>


int arr[] = {12, 6, 7, 11, 16, 3, 9};
const int length = sizeof(arr) / sizeof(arr[0]);
int x[length] = {0};                //子集树辅助数组,用于记录节点走向左节点还是右节点，表示i节点是否被选择
int bestx[length] = {0};            //存放最优解
unsigned int min = 0xFFFFFFFF;      //记录最小值
int sum = 0;                        //记录已选择数字的和
int r;                              //记录未选择数字的和

void func(int i ) {       //生成子集树
    if( i == length) {          //递归结束条件,访问到子集树的叶子节点
        int result = abs(sum - r);
        if(result < min) {
            min = result;

            for(int j = 0 ; j < length ; ++j) {
                bestx[j] = x[j];
            }
        }

    } else {
        r -= arr[i];
        sum += arr[i];
        x[i] = 1;
        func(i+1);
        r += arr[i];
        sum -= arr[i];

        x[i] = 0;
        func(i+1);
    }
}

int main() {
    for(int v : arr) {
        r += v;
    }

    func(0);

    for(int j=0 ; j < length ; ++j) {
        if(bestx[j]) {
            std::cout << arr[j] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << min << std::endl;

}

