#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> strs) {
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; i++) {
            char c = strs[0][i];
            for (int j = 1; j < count; j++) {
                if (i > strs[j].size() || c != strs[j][i]) {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    std::vector<std::string> strs = {"flower", "flight", "flow"};
    Solution s;
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    return 0;
}