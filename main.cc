#include <fmt/base.h>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
using namespace std;

std::vector<std::vector<int>> result;
std::vector<int> path;
void backtracking(std::vector<int>& num , std::vector<bool>& used) {
  if(path.size() == num.size()) {
    result.push_back(path);
    return;
  }
  for(int i=0 ; i<num.size() ; ++i) {
    if(used[i] == true) continue;
    used[i] = true;
    path.push_back(num[i]);
    backtracking(num, used);
    path.pop_back();
    used[i] = false;
  }
}