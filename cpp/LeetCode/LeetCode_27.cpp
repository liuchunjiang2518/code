// 给你一个数组 nums 和一个值 val，
// 你需要 原地 移除所有数值等于 val 的元素。
// 元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return n;
        }
        int fast = 0, slow = 0;
        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main() {
    std::vector<int> nums = {3, 2, 2, 2, 3};
    Solution s;
    std::cout << s.removeElement(nums, 3) << std::endl;
    for (int item: nums) {
        std::cout << item << std::endl;
    }
    return 0;
}