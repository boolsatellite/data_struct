#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
// 链式哈希表

/*线性探测法的缺点：
    1.当发生哈希冲突时，时间复杂度接近O(n),存储和删除变慢了
    2.多线程环境中，线性探测所用到的基于数组实现的哈希表，只能给全局的表上锁
        当使用链式哈希表时，可以用分段的锁，既保证了线程安全有提高了并发量，提高了效率
*/

class HashTable
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
            : useBucketNum_(0), loadFactor_(loadFactor), primeIdx_(0)
    {
        if (size > primes_[0])
        {
            for (; primeIdx_ < PEIME_SIZE; primeIdx_++)
            {
                if (primes_[primeIdx_] > size)
                    break;
            }
            if (primeIdx_ == PEIME_SIZE)
                primeIdx_--;
        }
        table_.resize(primes_[primeIdx_]);
    }

    void insert(int val)
    {
        double factor = useBucketNum_ * 1.0 / table_.size();
        cout << "factor : " << factor << endl;
        int idx = val % table_.size();
        if (factor >= loadFactor_)
        {
            expand();
        }
        if (table_[idx].empty())
        {
            useBucketNum_++;
            table_[idx].push_back(val);
        }
        else
        {
            auto it = ::find(table_[idx].begin(), table_[idx].end(), val);
            if (it == table_[idx].end())
            {
                table_[idx].emplace_front(val);
            }
        }
    }

    void erase(int val)
    {
        int idx = val % table_.size();
        auto it = ::find(table_[idx].begin(), table_[idx].end(), val);
        if(it != table_[idx].end())
        {
            table_[idx].erase(it);
        }
        if(table_[idx].empty()) useBucketNum_--;
    }

    bool find(int val)
    {
        int idx = val % table_.size();
        auto it = ::find(table_[idx].begin(), table_[idx].end(), val);
        if(it != table_[idx].end())
        {
            return true;
        }
        return false;

    }



private:
    vector<list<int>> table_;
    int useBucketNum_;  // 记录桶的个数
    double loadFactor_; // 装载因子
    static const int PEIME_SIZE = 10;
    static int primes_[PEIME_SIZE];
    int primeIdx_; // 当前使用的素数在素数表中的下标


    void expand()
    {
        if(primeIdx_+1 == PEIME_SIZE)
            throw "hashtable can not expand anymore";
        primeIdx_++;
        vector<list<int>> oldtable;
        oldtable.swap(table_);
        //swap的效率很高，
        //如果两个容器使用同一空间配置器allocater 只是交换了两个容器的成员变量(指向堆内存的指针)
        //如果两个容器使用不同的空间配置器allocater，就需要效率低的整个数据的交换
        table_.resize(primes_[primeIdx_]);
        useBucketNum_ = 0;

        for(auto list : oldtable)
        {
            for(auto key : list)
            {
                int idx = key % primes_[primeIdx_];
                if(table_[idx].empty())
                {
                    useBucketNum_++;
                    table_[idx].emplace_front(key);
                }
                else
                {
                    table_[idx].emplace_front(key);
                }
            }
        }

    }
};
int HashTable::primes_[PEIME_SIZE] = {3, 7, 23, 47, 251, 443, 911, 42773};

int main()
{
    HashTable htable;
    htable.insert(31);
    htable.insert(32);
    htable.insert(21);
    htable.insert(15);
    htable.insert(25);
    cout<<htable.find(31)<<endl;
    htable.erase(31);
    cout<<htable.find(31);
}