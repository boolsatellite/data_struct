//
// Created by bools on 2024-01-26.
//


#include <algorithm>
#include <iostream>

/*
 * m和柜台提供服务，每个柜台给一个用户提供服务的时间是t(用数组表示每一个退台提供服务的时间)
 * 问：应该怎么排列，使得柜台给所有用户提供服务的时间最少*/

struct Counter {
    bool operator<(Counter c) {
        return this->time < c.time;
    }
    int id;
    int time;
};

int main() {
    int arr[] = {3 , 2 , 4};
    const int m = sizeof arr / sizeof arr[0];
    int n = 15;             //办理业务的人数
    Counter cons[m];
    for(int i=0 ; i<m ; ++i) {
        cons[i].id = i;
        cons[i].time = arr[i];
    }
    std::sort(cons, cons+m,[&](const auto &a , const auto & b)->bool {return a.time < b.time;});

    int mintime = 0;
    int x[m] = {0};     //记录每一个柜台安排的用户数量

    for(int i=0 ; i<n ; ++i) {
        int time = cons[0].time * (x[0] + 1);       //排队到0号柜台直到被服务所需要的时间
        int j=1;
        for( ; j<m ;++j) {
            int t = cons[j].time * (x[j] + 1);
            if(t <= time) {                         //放在其他柜台整体速度更快
                x[j]++;
                if(x[j] * cons[j].time > mintime) {
                    mintime = x[j] * cons[j].time;
                }
                break;
            }
        }
        if(j == m) {                                //放在0号柜台速度更快
            x[0]++;
            mintime = cons[0].time * x[0];
        }
    }

    std::cout <<mintime <<std::endl;
    for(int i=0 ; i<m ; ++i) {
        std::cout << arr[cons[i].id] << " : " << x[i] << std::endl;
    }
}

