#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pair {
    int x, y;
};

void findPaths(vector<vector<int>>& m, int x, int y, vector<string>& paths, string path, int N) {
    if (x < 0 || x >= N || y < 0 || y >= N || m[x][y] == 0) return;
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    m[x][y] = 0; 
    if (x < N - 1) { 
        findPaths(m, x + 1, y, paths, path + 'D', N);
    }
    if (y < N - 1) {
        findPaths(m, x, y + 1, paths, path + 'R', N);
    }
    if (x > 0) {
        findPaths(m, x - 1, y, paths, path + 'U', N);
    }
    if (y > 0) {
        findPaths(m, x, y - 1, paths, path + 'L', N);
    }
    m[x][y] = 1;
}

vector<string> printThePath(int N, vector<vector<int>>& m) {
    vector<string> paths;
    if (m[0][0] == 1 && m[N - 1][N - 1] == 1) {
        findPaths(m, 0, 0, paths, "", N);
    }
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    int N1 = 4;
    vector<vector<int>> m1 = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<string> result1 = printThePath(N1, m1);
    if (result1.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& s : result1) {
            cout << s << " ";
        }
        cout << endl;
    }

    int N2 = 2;
    vector<vector<int>> m2 = { {1, 0}, {1, 0} };
    vector<string> result2 = printThePath(N2, m2);
    if (result2.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& s : result2) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}