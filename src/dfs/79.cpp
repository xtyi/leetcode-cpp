// 79. 单词搜索
// https://leetcode.cn/problems/word-search/
// tags: 回溯

#include "common.h"

class Solution {
    bool found = false;

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, word, 0);
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    // 从 (i, j) 开始向四周搜索，试图匹配 word[p..]
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int p) {
        if (p == word.length()) {
            // 整个 word 已经被匹配完，找到了一个答案
            found = true;
            return;
        }
        if (found) {
            // 已经找到了一个答案，不用再搜索了
            return;
        }
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (board[i][j] != word[p]) {
            return;
        }

        // 已经匹配过的字符，我们给它添一个负号作为标记，避免走回头路
        board[i][j] = -board[i][j];
        // word[p] 被 board[i][j] 匹配，开始向四周搜索 word[p+1..]
        dfs(board, i + 1, j, word, p + 1);
        dfs(board, i, j + 1, word, p + 1);
        dfs(board, i - 1, j, word, p + 1);
        dfs(board, i, j - 1, word, p + 1);
        board[i][j] = -board[i][j];
    }
};
