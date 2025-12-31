// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
// 判断字符串是否有效。
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        std::stack<char> stk;
        std::unordered_map<char, char> ht = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        for (char ch: s) {
            if (ht.count(ch)) {
                if (stk.empty() || stk.top() != ht[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

int main() {
    std::string str = "{[()]}";
    Solution s;
    if (s.isValid(str)) {
        std::cout << "合法" << std::endl;
    }
    else {
        std::cout << "不合法" << std::endl;
    }
    return 0;
}