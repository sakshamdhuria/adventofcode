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

    vector<string> vec;
    vector<char> oper;
    while (getline(inputFile, line)) {
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

        vec.push_back(line);
    }
    int sz= oper.size();
    vector<int> vec2(sz);
    for(int i=0; i<sz; i++){
        if(oper[i]=='*') vec2[i]=1;
        else vec2[i]=0;
    }

    int opInd=0;
    for(int i=0; i<vec[0].size(); i++){
        bool seenSpace=0;
        int temp=0;
        for(int j=0; j<vec.size(); j++){
            if(vec[j][i]!=' '){
                seenSpace=1;
                temp=temp*10+vec[j][i]-'0';
            }
        }
        if(!seenSpace) {
            opInd++;
            temp=0;
            continue;
        }
        if(oper[opInd]=='*') vec2[opInd]*=temp;
        else vec2[opInd]+=temp;
    }
    for(int i: vec2) ans+=i;
    #undef int
    cout << ans<< endl;
    return (int)0;
}
