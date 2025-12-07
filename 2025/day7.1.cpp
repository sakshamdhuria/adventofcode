#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    int ans = 0;
    string line;
    vector<string> vec;

    while (getline(inputFile, line)) {
        if (line.empty()) continue;
        vec.push_back(line);
    }

    int n = vec.size();
    int m = vec[0].size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 'S') {
                if (vec[i + 1][j] == '^') {
                    ans++; 
                    if (j > 0 && vec[i + 1][j - 1] == '.')
                        vec[i + 1][j - 1] = 'S';

                    if (j + 1 < m && vec[i + 1][j + 1] == '.')
                        vec[i + 1][j + 1] = 'S';
                }
                else if (vec[i + 1][j] == '.') {
                    vec[i + 1][j] = 'S';
                }
            }
        }
    }

    cout << ans << endl;
    return (int)0;
}
