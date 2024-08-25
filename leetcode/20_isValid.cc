#include <string>
#include <deque>
#include <stack>
#include <map>
#include <iostream>

std::map<char,char> m = {{'(' , ')'} , {'[' , ']'} , {'{' , '}'}};

bool is_left(char c) {
  if(c == '(' || c == '[' || c == '{') {
    return true;
  } else {
    return false;
  }
}

std::stack<unsigned char> st;

bool isValid(std::string s) {
  for(auto c : s) {
    if(is_left(c)) {
      st.push(c);
    } else {
      if(s.empty()) return false;
      auto i = st.top();
      auto other = m.find(i)->second;
      if(other == c) {
        st.pop();
        continue;
      } else {
        return false;
      }
    }
  }
  if(!st.empty()) return false;
  return true;
}

int main() {
  std::cout << isValid("([])");
}