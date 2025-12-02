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
                string temp=to_string(i);
                if(temp.size()%2==0 && temp.substr(0,temp.size()/2)==temp.substr(temp.size()/2)) {
                    ans+=i;
                }
            }
            std::cout << "Interval: " << a << " to " << b << "\n";
        }
    }
    cout<<ans<<endl;
    return 0;
}
