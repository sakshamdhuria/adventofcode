#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string addStrings(const string &a, const string &b) {
    string x = a, y = b;
    if (x.size() < y.size()) swap(x, y);

    int carry = 0;
    int i = x.size() - 1, j = y.size() - 1;
    string res;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += x[i--] - '0';
        if (j >= 0) sum += y[j--] - '0';
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

string best12Digits(const string &line) {
    int n = 100;
    int k = 12;

    string output;
    output.reserve(12);

    int start = 0;
    int remaining = k;

    while (remaining > 0) {
        int end = n - remaining;
        char best = '0';
        int bestPos = start;

        for (int i = start; i <= end; i++) {
            if (line[i] > best) {
                best = line[i];
                bestPos = i;
            }
        }

        output.push_back(best);
        start = bestPos + 1;
        remaining--;
    }

    int pos = 0;
    while (pos < output.size() && output[pos] == '0') pos++;
    if (pos == output.size()) return "0";

    return output.substr(pos);
}


int32_t main() {
    ifstream inputFile("adventOfCodeInput.txt");
    if (!inputFile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    string ans = "0";
    string line;

    while (getline(inputFile, line)) {
        string largest = best12Digits(line);
        ans = addStrings(ans, largest);
    }

    cout << ans << endl;
    return 0;
}
