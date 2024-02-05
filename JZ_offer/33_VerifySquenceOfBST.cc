//
// Created by bools on 5/02/2024.
//

#include <vector>



bool check(std::vector<int> sequence , int l , int r) {
    if(l >= r) return true;

    int headVal = sequence[r];
    //划分右子树
    int j = r - 1;
    while(j>=0 && sequence[j]>headVal) {
        j--;
    }
    //验证是否满足左子树
    for(int i=l ; i<=j ; ++i) {
        if(sequence[i] > headVal) {
            return false;
        }
    }

    return check(sequence , l , j) && check(sequence , j+1 , r-1);
}

bool VerifySquenceOfBST(std::vector<int> sequence) {
    if(sequence.size() == 0) return false;
    return check(sequence , 0 , sequence.size()-1);
}