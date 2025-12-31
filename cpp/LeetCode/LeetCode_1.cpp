// 给定一个整数数组nums和一个整数目标值target，
// 请你在该数组中找出和为目标值target的那两个整数，
// 并返回它们的数组下标。
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> nums, int target) {
        std::unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++) {
            auto it = ht.find(target - nums[i]);
            if (it != ht.end()) {
                return {it->second, i};
            }
            ht[nums[i]] = i;
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