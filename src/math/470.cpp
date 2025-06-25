// 470. 用 Rand7() 实现 Rand10()
// https://leetcode.cn/problems/implement-rand10-using-rand7/
// tags: 数学

#include "common.h"

int rand7();

class Solution {
public:
    int rand10() {
        while (true) {
            int row = rand7();
            int col = rand7();
            // 均匀地生成 1-49 的随机数
            int idx = (row-1)*7 + col;
            if (idx <= 40) {
                // 把 1-40 映射到 1-10
                return 1 + (idx-1)%10;
            }
        }
    }
};

