// 733. 图像渲染
// https://leetcode.cn/problems/flood-fill/
// tags: 深度优先搜索

#include "common.h"

class Solution {
    int n{0};
    int m{0};
    int oldColor{0};
    int newColor{0};
    vector<vector<bool>> visited;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        visited.resize(n, vector<bool>(m, false));
        oldColor = image[sr][sc];
        newColor = color;
        dfs(image, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (image[i][j] != oldColor) {
            return;
        }
        image[i][j] = newColor;
        dfs(image, i+1, j);
        dfs(image, i-1, j);
        dfs(image, i, j+1);
        dfs(image, i, j-1);
    }
};
