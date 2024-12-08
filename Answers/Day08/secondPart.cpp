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
                
                if (vis.count(arr[i]) == 0) {
                    vis.insert(arr[i]);
                    ans++;
                }
                if (vis.count(arr[j]) == 0) {
                    vis.insert(arr[j]);
                    ans++;
                }

                int dx = arr[j].F - arr[i].F;
                int dy = arr[j].S - arr[i].S;

                // 1
                int nx = arr[i].F, ny = arr[i].S;
                while (true) {
                    nx += dx; ny += dy;
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (vis.count({nx, ny}) == 0) {
                            vis.insert({nx, ny});
                            ans++;
                        }
                    } else break;
                }
                // 2
                nx = arr[i].F, ny = arr[i].S;
                while (true) {
                    nx -= dx; ny -= dy;
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (vis.count({nx, ny}) == 0) {
                            vis.insert({nx, ny});
                            ans++;
                        }
                    } else break;
                }
                // 3
                nx = arr[j].F, ny = arr[j].S;
                while (true) {
                    nx += dx; ny += dy;
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (vis.count({nx, ny}) == 0) {
                            vis.insert({nx, ny});
                            ans++;
                        }
                    } else break;
                }
                // 4
                nx = arr[j].F, ny = arr[j].S;
                while (true) {
                    nx -= dx; ny -= dy;
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (vis.count({nx, ny}) == 0) {
                            vis.insert({nx, ny});
                            ans++;
                        }
                    } else break;
                }
               
            }
        }
    }
    cout << ans << endl;;

}
