#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
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
        if(s[0]=='L'){
            ans+=(num-curr)/100 + (num>=curr) - (curr==0);
            curr-=num;
        }else{
            ans+=(num-(100-curr))/100 + (num>=100-curr);
            curr+=num;
        }
        curr=((curr%100)+100)%100;

    }
    
    cout << "ANS: " << ans << endl;
    return 0;
}
