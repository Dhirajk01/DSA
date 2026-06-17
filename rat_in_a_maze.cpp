#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &visited)
{
    int n = maze.size();

    // BASE CASE
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || visited[row][col] == true)
    {
        return;
    }

    // Base case for ans
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[row][col] = true;

    helper(maze, row + 1, col, path + 'D', ans, visited); // Down
    helper(maze, row - 1, col, path + 'U', ans, visited); // Up
    helper(maze, row, col - 1, path + 'L', ans, visited); // left
    helper(maze, row, col + 1, path + 'R', ans, visited); // right

    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(false));
    helper(maze, 0, 0, path, ans, visited);
    return ans;
}

int main()
{
    vector<vector<int>> maze{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(maze);

    for (string path : ans)
    {
        cout << path << endl;
    }
}