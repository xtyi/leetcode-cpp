// 课程表
// 拓扑排序

#include "common.h"

// class Solution {
//     vector<vector<int>> edges;
//     vector<int> indegrees;
//     int visited = 0;
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         edges.resize(numCourses);
//         indegrees.resize(numCourses);

//         for (auto& info: prerequisites) {
//             int from = info[1];
//             int to = info[0];
//             edges[from].push_back(to);
//             indegrees[to] += 1;
//         }

//         bfs(numCourses);

//         return visited == numCourses;
//     }

//     void bfs(int numCourses) {
//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (indegrees[i] == 0) {
//                 q.push(i);
//             }
//         }
//         while (!q.empty()) {
//             int u = q.front();
//             q.pop();
//             visited += 1;

//             for (int v: edges[u]) {
//                 indegrees[v]--;
//                 if (indegrees[v] == 0) {
//                     q.push(v);
//                 }
//             }
//         }
//     }
// };


class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);

        for (auto& info: prerequisites) {
            int from = info[1];
            int to = info[0];
            edges[from].push_back(to);
        }

        for (int i = 0; i < numCourses && valid; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }

        return valid;
    }

    void dfs(int u) {
        if (!valid) return;
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 1) {
                valid = false;
                return;
            } else if (visited[v] == 0) {
                dfs(v);
            }
        }
        visited[u] = 2;
    }
};
