#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

#define int long long 
#define PRINT_VECTOR(vec) do { \
    for (size_t i = 0; i < vec.size(); ++i) { \
        cout << vec[i] << (i + 1 < vec.size() ? " " : "\n"); \
    } \
} while(0)
bool help(int i){
    string s=to_string(i);
    int n=s.size();
    for(int len=1; len<=n/2; len++){
        if(n%len==0){
            string temp=s.substr(0,len);
            bool flag=1;
            for(int i=len; i<n; i+=len){
                if(s.substr(i,len)!=temp){
                    flag=0;
                }
            }
            if(flag){
                return true;
            }
        }
    }
    return false;
}
int32_t main() {
    std::string filename = "adventOfCodeInput.txt";
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::string line;
    int ans=0;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string interval;

        while (std::getline(ss, interval, ',')) {  
            int a, b;
            char dash;

            std::stringstream is(interval);
            is >> a >> dash >> b;
            for(int i=a; i<=b; i++) {
                if(help(i)){
                    ans+=i;
                }   
            }
            std::cout << "Interval: " << a << " to " << b << "\n";
        }
    }
    cout<<ans<<endl;
    return 0;
}
