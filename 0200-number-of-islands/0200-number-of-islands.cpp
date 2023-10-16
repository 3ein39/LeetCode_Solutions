#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

class Solution {
    vector<vector<bool>> vis;
    int n, m;
    vector<vector<char>> grid;

public:
    bool valid(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '0')
            return false;
        return true;
    }

    void dfs(int i, int j) {
        if (!valid(i,j))
            return;
            
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            dfs(ni,nj);
        }
    }

    int numIslands(vector<vector<char>>& grid_) {
        grid = grid_;
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));

        int cc = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (valid(i,j)) {
                    ++cc;
                    dfs(i,j);
                }
            }
        }
        return cc;
    }
};