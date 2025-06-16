#include "common.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << "Input: nums = ";
    printVector(nums);
    std::cout << "target = " << target << std::endl;
    std::cout << "Output: ";
    printVector(result);

    return 0;
}
