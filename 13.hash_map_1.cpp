// 线性探测哈希表的实现
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// 桶的状态
enum State
{
    STATE_UNUSE, // 从未被使用
    STATE_USING, // 正在被使用
    STATE_DEL    // 元素被删除了的桶
};

struct Bucket
{
    Bucket(int key = 0, State state = STATE_UNUSE)
        : key_(key), state_(state)
    {
    }
    int key_;        //桶内存放的值
    State state_;    //这个桶的状态
};

class HashTable
{
public:
    HashTable(int size = primes_[0], double load = 0.75)
        : useBuckerNum_(0), loadFactor_(load), primeIdx_(0)
    {
        if (primeIdx_ != 0)
        {
            // 将用户传入的size与素数表中的进行匹配
            for (; primeIdx_ < tableSize_; primeIdx_++)
            {
                if (primes_[primeIdx_] > size)
                    break;
            }
            if (primeIdx_ == tableSize_) // 传入的参数过大以至大于素数表中最后一个元素
                primeIdx_--;             // 为了维护稳定就以素数表中最大的元素作为size
        }
        tableSize_ = primes_[primeIdx_];
        table_ = (Bucket*)new Bucket[tableSize_];
    }
    ~HashTable()
    {
        delete[] table_;
        table_ = nullptr;
    }

public:
    void insert(int key)
    {
        double factor = (double)useBuckerNum_ / tableSize_;
        cout<<"装载因子为 : "<<factor<<endl<<"useBuckerNum : "<<useBuckerNum_<<endl;
        if(factor > loadFactor_)   //扩容
        {
            expand();
        }

        int idx = key % tableSize_;

        /*
        if(table_[idx].state_ != STATE_USING)
        {
            table_[idx].state_ = STATE_USING; 
            table_[idx].key_ = key;
            useBuckerNum_++;
            //如果这个桶的状态为未被使用就将状态标记为被使用，并为则合格桶赋值
            return;
        }
        
        //这个桶正在被使用
        for(int i=(idx+1)%tableSize_;i<idx;i=(i+1)%tableSize_) 
        //从hash函数算出来的下标的下一个位置开始，到idx本身结束
        //由于存在装载因子，不可能遍历到idx
        {
            if(table_[i].state_ != STATE_USING)
            {
                table_[i].state_ = STATE_USING;
                table_[i].key_ = key;
                useBuckerNum_++;
                return;
            }
        }
        */
   
       //注释中的写法不够简练，用这种写法比较好
       int i = idx;
       do
       {
            if(table_[i].state_ != STATE_USING)
            {
                table_[i].state_ = STATE_USING;
                table_[i].key_ = key;
                useBuckerNum_++;
                return;
            }
            i = (i+1)%tableSize_;
       } while (i != idx);
    }

    void erase(int key)  //删除元素
    {
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if(table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                table_[i].state_ = STATE_DEL;
                useBuckerNum_--;
            }
            i = (i+1)%tableSize_;
        } while (i != idx && table_[i].state_ != STATE_UNUSE);
    }

    bool find(int key)
    {
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if(table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                return true;
            }
            i = (i+1)%tableSize_;
        } while (i != idx && table_[i].state_ != STATE_UNUSE);
        return false;
    }

private:

    void expand()
    {
        primeIdx_++;
        if(primeIdx_ == PEIME_SIZE)
            throw "HashTable is MAX";
        Bucket* newTable = new Bucket[primes_[primeIdx_]];
        for(int i=0;i<tableSize_;i++)
        {
            if(table_[i].state_ == STATE_USING)  //旧表中的有效数据重新Hash放入新表
            {
                int idx = table_[i].key_ % primes_[primeIdx_];
                int j = idx;
                do
                {
                    if(newTable[j].state_ != STATE_USING)
                    {
                        newTable[j].state_ = STATE_USING;
                        newTable[j].key_ = table_[i].key_;
                        break;
                    }
                    j = (j+1)%primes_[primeIdx_];
                } while (i != idx);
            }
        }
        delete[] table_;
        table_ = newTable;
        tableSize_ = primes_[primeIdx_];
    }

private:
    Bucket *table_;     // 指向动态开辟的哈希表的指针
    int tableSize_;     // 哈希表当前的长度
    int useBuckerNum_;  // 已经使用的桶的个数
    double loadFactor_; // 装载因子

    static const int PEIME_SIZE = 10;
    static int primes_[PEIME_SIZE];
    int primeIdx_; // 当前使用的素数在素数表中的下标
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
    htable.erase(31);
    cout<<htable.find(31);
}