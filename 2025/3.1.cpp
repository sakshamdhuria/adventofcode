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
    int ans = 0;

    while (std::getline(inputFile, line)) {
        int largest=0;
        for(int i=0; i<line.size(); i++){
            for(int j=i+1; j<line.size(); j++){
                int temp=10*(line[i]-'0')+line[j]-'0';
                largest=max(largest,temp);
            }
        }
        ans+=largest;
    }
    cout<<ans<<endl;
    return 0;
}
