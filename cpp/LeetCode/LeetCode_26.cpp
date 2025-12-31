// 给你一个非严格递增排列的数组nums ，
// 请你原地删除重复出现的元素，
// 使每个元素只出现一次，
// 返回删除后数组的新长度。
// 元素的相对顺序应该保持一致 。
// 然后返回nums中唯一元素的个数。
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return n;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    } 
};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 5, 5};
    Solution s;
    std::cout << s.removeDuplicates(nums) << "个不重复元素" << std::endl;
    return 0;
}