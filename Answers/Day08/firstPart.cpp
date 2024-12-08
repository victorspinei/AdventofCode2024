#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define F first
#define S second
#define endl '\n' 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long ll;

int main() {
    freopen("data.in", "r", stdin);

    vector<string> grid;
    string line;
    while (cin >> line) {
        if (line.empty()) break;
        grid.pb(line);
    }

    unordered_set<char> symbols;
    unordered_map<char, vector<ii>> mp;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != '.') {
                symbols.insert(grid[i][j]);
                mp[grid[i][j]].pb({i, j});
            }
        }
    }

    ll ans = 0;
    set<ii> vis;

    for (auto key : symbols) {
        vector<ii> arr = mp[key];

        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int dx = arr[j].F - arr[i].F;
                int dy = arr[j].S - arr[i].S;

                // Extend in all four directions
                vector<ii> directions = {
                    {arr[j].F + dx, arr[j].S + dy}, // Case 1
                    {arr[i].F - dx, arr[i].S - dy}, // Case 2
                    {arr[j].F - dx, arr[j].S - dy}, // Case 3
                    {arr[i].F + dx, arr[i].S + dy}  // Case 4
                };

                for (auto [nx, ny] : directions) {
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (grid[nx][ny] != key && vis.count({nx, ny}) == 0) {
                            vis.insert({nx, ny});
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;;

}
