#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <sstream>
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

    vector<vector<int>> vec;
    vector<char> oper;
    while (getline(inputFile, line)) {
        if(line.empty()) continue;
        bool hasNonSpace = false;
        for (char ch : line) {
            if (!isspace(static_cast<unsigned char>(ch))) {
                hasNonSpace = true;
                break;
            }
        }
        if (!hasNonSpace) continue;

        bool hasOperator = false;
        for (char ch : line) {
            if (ch == '*' || ch == '+') {
                hasOperator = true;
                break;
            }
        }
        if (hasOperator) {
            for (char ch : line) {
                if (ch == '*' || ch == '+') oper.push_back(ch);
            }
            continue;
        }

        istringstream iss(line);
        vector<int> row;
        int value;
        while (iss >> value) row.push_back(value);
        if (!row.empty()) vec.push_back(move(row));
    }
    for(int i=0; i<vec[0].size(); i++){
        int temp;
        if(oper[i]=='*'){
            temp=1;
        }else{
            temp=0;
        }
        for(int j=0; j<vec.size(); j++){
            if(oper[i]=='*') temp*=vec[j][i];
            else temp+=vec[j][i];
        }
        ans+=temp;
    }
    #undef int
    cout << ans<< endl;
    return (int)0;
}
