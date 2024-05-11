#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string str) {
    int n = str.length();
    if (n > 3)
        return false;
    if (str[0] == '0' && n > 1)
        return false;
    int num = stoi(str);
    return num >= 0 && num <= 255;
}

void generateIP(string S, int pos, vector<string>& result, vector<string>& current) {
    if (current.size() == 4 && pos == S.length()) {
        result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]);
        return;
    }
    if (current.size() == 4 || pos == S.length())
        return;

    for (int len = 1; len <= 3 && pos + len <= S.length(); ++len) {
        string part = S.substr(pos, len);
        if (isValid(part)) {
            current.push_back(part);
            generateIP(S, pos + len, result, current);
            current.pop_back();
        }
    }
}

vector<string> genIp(string &S) {
    vector<string> result;
    if (S.length() < 4 || S.length() > 12)
        return {"-1"};
    vector<string> current;
    generateIP(S, 0, result, current);
    if (result.empty())
        return {"-1"};
    return result;
}

int main() {
    string S = "99999999999";
    vector<string> result = genIp(S);
    if (result.size() == 1 && result[0] == "-1")
        cout << "Output: -1" << endl;
    else {
        cout << "Output:";
        for (auto ip : result)
            cout << " " << ip;
        cout << endl;
    }

    return 0;
}
