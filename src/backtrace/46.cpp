// 46. 全排列
// https://leetcode.cn/problems/permutations/
// tags: 回溯

#include "common.h"

class Solution {

private:
    vector<vector<int>> ans;
    vector<int> path;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false); // 标记哪些元素已经使用
        backtrace(nums, used);
        return ans;
    }

    void backtrace(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 跳过已经选择的元素
            if (used[i]) {
                continue;
            }
            // 做选择
            path.push_back(nums[i]);
            used[i] = true;
            // 进入下一层决策树
            backtrace(nums, used);
            // 撤销选择
            path.pop_back();
            used[i] = false;
        }
    }
};
