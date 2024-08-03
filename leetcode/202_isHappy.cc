#include <iostream>
#include <set>

int option_num(int n) {
  int tmp = 0;
  while (n > 0) {
    tmp += (n % 10) * (n % 10);
    n = n / 10;
  }
  return tmp;
}

std::set<int> hash_set{};
bool isHappy(int n) {
  while (n != 1) {
    hash_set.insert(n);
    n = option_num(n);
    auto it = hash_set.find(n);
    if(it != hash_set.end()) return false;
  }
  return true;
}
