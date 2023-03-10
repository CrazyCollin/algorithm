//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

class Solution {
    int row_length=0;
    int column_length=0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        row_length=grid.size();
        column_length=grid[0].size();
        for (int i = 0; i < row_length; ++i) {
            for (int j = 0; j < column_length; ++j) {
                if (grid[i][j]=='1'){
                    result+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& grid,int i,int j){
        if (i<0||j>=column_length||j<0||i>=row_length){
            return;
        }
        if (grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};