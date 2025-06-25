// 1926. 迷宫中离入口最近的出口
// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/
// tags: 广度优先搜索

#include "common.h"

class Solution {

    vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        while (!q.empty()) {
            step += 1;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();

                for (auto dir: dirs) {
                    int x = cur.first + dir.first;
                    int y = cur.second + dir.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if (x == 0 || x == m-1 || y == 0 || y == n-1) {
                            return step;
                        }
                        maze[x][y] = '+';
                        q.push({x, y});
                    }
                }
            }
        }
        return -1;
    }
};
