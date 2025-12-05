#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
#define int long long 

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1], intervals[i][1]);
        }else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
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
    vector<vector<int>> ranges;
    vector<int> queries;

    while (getline(inputFile, line)) {
        size_t dash = line.find('-');

        if (dash != string::npos) {
            int start = stoll(line.substr(0, dash));
            int end   = stoll(line.substr(dash + 1));
            ranges.push_back({start, end});
        } 
    }
    vector<vector<int>> merged = merge(ranges);
    for(auto x: merged){
        ans += x[1]-x[0]+1;
    }
    #undef int
    cout << ans<< endl;
    return (int)0;
}
