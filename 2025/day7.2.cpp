#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define int long long

#undef int
int main() {
#define int long long

    ifstream inputFile("adventOfCodeInput.txt");
    if (!inputFile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    string line;
    int ans = 0;
    vector<string> vec;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;
        vec.push_back(line);
    }
    if (vec.empty()) {
        cout << 0 << endl;
        return (int)0;
    }
    int n = (int)vec.size();
    int m = (int)vec[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<m; i++) if(vec[0][i] == 'S') dp[0][i] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] != '^')  dp[i][j] += dp[i - 1][j];
            else {
                if (j - 1 >= 0) dp[i][j - 1] += dp[i - 1][j];
                if (j + 1 < m) dp[i][j + 1] += dp[i - 1][j];
            }
            if(i==n-1) ans+=dp[i][j];
        }
    }


    cout << ans << endl;
    return (int)0;
}
