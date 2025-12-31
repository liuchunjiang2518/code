#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    std::vector<int> result = s.twoSum(nums, target);
    for (int i: result) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}