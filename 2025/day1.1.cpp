#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define int long long 
#define PRINT_VECTOR(vec) do { \
    for (size_t i = 0; i < vec.size(); ++i) { \
        cout << vec[i] << (i + 1 < vec.size() ? " " : "\n"); \
    } \
} while(0)

int32_t main() {
    string filename = "adventOfCodeInput.txt"; // Name of the input file
    ifstream inputFile(filename);

    string s;
    int ans=0, curr=50; 
    while(getline(inputFile, s)){
        int num = stoll(s.substr(1));
        if(s[0]=='L') curr=((curr-num)+100)%100;
        else curr=((curr+num)+100)%100;
        if(curr==0) ans++;

    }
    
    cout << "ANS: " << ans << endl;
    return 0;
}
