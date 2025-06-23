#include "common.h"

class Solution {

int n = 0;
int m = 0;

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>&grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
