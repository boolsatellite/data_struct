//
// Created by bools on 19/03/2024.
//


string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

std::vector<string> vec{};
string tem{};

void func(const string& digits , int index) {
    if(index == digits.size()) {
        vec.push_back(tem);
        return;
    }
    int num = digits[index] - '0';
    string s = MAPPING[num];
    for(int i=0 ; i<s.size() ; ++i) {
        tem.push_back(s[i]);
        func(digits , index+1);
        tem.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits == "") return {};
    func(digits , 0);
    return vec;
}