#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define int long long

int32_t main() {
    string filename = "adventOfCodeInput.txt";
    ifstream inputFile(filename);

    string s;
    int ans = 0, curr = 50;

    while (getline(inputFile, s)) {
        int num = stoll(s.substr(1));
        while (num--) {
            if (s[0] == 'R') curr++;
            else curr--;

            curr = (curr + 100) % 100; 
            ans += (curr == 0);      
        }
    }

    cout << "ANS: " << ans << endl;
    return 0;
}
