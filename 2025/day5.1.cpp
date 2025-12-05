#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
    #define int long long 
    ifstream inputFile("adventOfCodeInput.txt");
    if (!inputFile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    int ans = 0;
    string line;
    vector<vector<int>> ranges;
    vector<int> queries;

    while (getline(inputFile, line)) {
        if (line.empty()) continue;
        size_t dash = line.find('-');

        if (dash != string::npos) {
            int start = stoll(line.substr(0, dash));
            int end   = stoll(line.substr(dash + 1));
            ranges.push_back({start, end});
        } 
        else {
            queries.push_back(stoll(line));
        }
    }
    for(int i: queries){
        for(size_t j = 0; j < ranges.size(); j++){
            if(i >= ranges[j][0] && i <= ranges[j][1]){
                ans++;
                break;
            }
        }
    }
    #undef int
    cout << ans<< endl;
    return (int)0;
}
