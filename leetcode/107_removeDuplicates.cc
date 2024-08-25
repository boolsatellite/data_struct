#include <string>
#include <stack>

std::string removeDuplicates(std::string s) {
  std::string result;
  for(auto&& c : s) {
    if(result.empty() || c!=result.back()) {
      result.push_back(c);
    } else {
      result.pop_back();
    }
  }
  return result;
}