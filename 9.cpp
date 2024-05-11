#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Structure to represent a Trie node
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'A'; 
        if (!curr->children[index])
            curr->children[index] = new TrieNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

void searchWord(vector<vector<char>>& board, int row, int col, TrieNode* root, string path, unordered_set<string>& result, vector<vector<bool>>& visited) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col])
        return;

    int index = board[row][col] - 'A';
    if (!root->children[index])
        return;

    path += board[row][col];
    if (root->children[index]->isEndOfWord)
        result.insert(path);

    visited[row][col] = true;

    int rowMove[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colMove[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i)
        searchWord(board, row + rowMove[i], col + colMove[i], root->children[index], path, result, visited);

    visited[row][col] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    unordered_set<string> result;
    int rows = board.size();
    int cols = board[0].size();

    TrieNode* root = new TrieNode();
    for (string word : dictionary)
        insert(root, word);

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            string path = "";
            searchWord(board, i, j, root, path, result, visited);
        }
    }

    vector<string> res(result.begin(), result.end());
    return res;
}

int main() {
    int R = 3, C = 3;
    vector<vector<char>> board = {{'G','I','Z'}, {'U','E','K'}, {'Q','S','E'}};
    int N = 4;
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    vector<string> words = wordBoggle(board, dictionary);

    for (string word : words)
        cout << word << " ";
    cout << endl;

    return 0;
}
