// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串""。
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommmonPrefix(std::vector<std::string> strs) {
        if (!strs.size()) {
            return "";
        }
        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = compare(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

private:
    std::string compare(const std::string& str1, const std::string str2) {
        int length = std::min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            index++;
        }
        return str1.substr(0, index);
    }
};

int main() {
    std::vector<std::string> strs = {"flower", "flight", "flow"};
    Solution s;
    std::cout << s.longestCommmonPrefix(strs) << std::endl;
    return 0;
}