#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n,1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream inputFile("adventOfCodeInput.txt");
    if (!inputFile) {
        cerr << "File error\n";
        return 1;
    }

    vector<array<long long,3>> points;
    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        array<long long,3> p;
        for (int i = 0; i < 3; i++) {
            string v;
            getline(ss, v, ',');
            p[i] = stoll(v);
        }
        points.push_back(p);
    }

    int n = points.size();

    struct Edge {
        long long d;
        int u, v;
    };

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = points[i][0] - points[j][0];
            long long dy = points[i][1] - points[j][1];
            long long dz = points[i][2] - points[j][2];
            long long d = dx*dx + dy*dy + dz*dz;
            edges.push_back({d, i, j});
        }
    }

    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a.d < b.d; });

    DSU dsu(n);
    int components = n;
    int temp=1000;
    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            components--;
            if (components == 1) {
                long long x1 = points[e.u][0];
                long long x2 = points[e.v][0];
                break;
            }
        }
    }

    return 0;
}
