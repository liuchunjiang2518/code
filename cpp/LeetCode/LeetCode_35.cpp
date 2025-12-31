// 给定一个排序数组和一个目标值，
// 在数组中找到目标值，
// 并返回其索引。
// 如果目标值不存在于数组中，
// 返回它将会被按顺序插入的位置。
#include <iostream>
#include <vector>

class Solution {
public:
    int BinarySearch(std::vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1, pos = nums.size();
        while (left < right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return pos;
    }
};

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    Solution s;
    std::cout << s.BinarySearch(nums, 2) << std::endl;
    return 0;
}