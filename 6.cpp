#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findPathsUtil(vector<vector<int>>& matrix, int x, int y, string path, vector<string>& paths, vector<vector<bool>>& visited) {
    int N = matrix.size();
    if (x < 0 || y < 0 || x >= N || y >= N || matrix[x][y] == 0 || visited[x][y])
        return;

    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    if (x + 1 < N && !visited[x + 1][y] && matrix[x + 1][y] == 1)
        findPathsUtil(matrix, x + 1, y, path + 'D', paths, visited);

    if (y + 1 < N && !visited[x][y + 1] && matrix[x][y + 1] == 1)
        findPathsUtil(matrix, x, y + 1, path + 'R', paths, visited);

    if (y - 1 >= 0 && !visited[x][y - 1] && matrix[x][y - 1] == 1)
        findPathsUtil(matrix, x, y - 1, path + 'L', paths, visited);

    visited[x][y] = false;
}

vector<string> findPaths(vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<string> paths;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    if (matrix[0][0] == 0)
        return paths; 
    findPathsUtil(matrix, 0, 0, "", paths, visited);
    return paths;
}

int main() {
    vector<vector<int>> matrix1 = { {1, 0, 0, 0},
                                   {1, 1, 0, 1},
                                   {1, 1, 0, 0},
                                   {0, 1, 1, 1} };
    vector<string> paths1 = findPaths(matrix1);
    if (paths1.empty())
        cout << "-1" << endl;
    else {
        for (const string& path : paths1)
            cout << path << " ";
        cout << endl;
    }

    vector<vector<int>> matrix2 = { {1, 0},
                                   {1, 0} };
    vector<string> paths2 = findPaths(matrix2);
    if (paths2.empty())
        cout << "-1" << endl;
    else {
        for (const string& path : paths2)
            cout << path << " ";
        cout << endl;
    }

    return 0;
}
