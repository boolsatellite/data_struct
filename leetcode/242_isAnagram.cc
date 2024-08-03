#include <string>
#include <iostream>
#include <map>

bool isAnagram(std::string s, std::string t) {
  std::map<int, int> hash_map;
  for(const auto& i : s) {
    hash_map[i]++;
  }
  for(const auto& i : t) {
    hash_map[i]--;
  }
  for(auto it = hash_map.begin() ; it != hash_map.end() ; ++it) {
    if(it->second != 0) return false;
  }
  return true;
}

int main() {
  std::cout << isAnagram("zlap", "kcqx") << std::endl;
}