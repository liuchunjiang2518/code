// 给你一个整数x，
// 如果x是一个回文整数，
// 返回true；否则，返回false 。
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if ((x % 10 == 0 && x != 0) || x < 0) {
            return false;
        }
        int revertedNumber = 0;
        while (revertedNumber < x) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main() {
    int x = 123321;
    Solution s;
    if (s.isPalindrome(x)) {
        std::cout << x << "是回文数" << std::endl;
    }
    else {
        std::cout << x << "不是回文数" << std::endl;
    }
    return 0;
}