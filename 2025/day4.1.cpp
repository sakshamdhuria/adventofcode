#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int32_t main() {
    ifstream inputFile("adventOfCodeInput.txt");
    if (!inputFile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    int ans = 0;
    string line;
    vector<string> vec;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec[i].size(); ++j) {

            if (vec[i][j] != '@') continue;  

            int count = 0;

            for (int k = max(0, (int)i - 1); k <= min((int)vec.size() - 1, (int)i + 1); ++k) {
                for (int l = max(0, (int)j - 1); l <= min((int)vec[k].size() - 1, (int)j + 1); ++l) {
                    if (k == (int)i && l == (int)j) continue;
                    if (vec[k][l] == '@') count++;
                }
            }

            if (count < 4) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
