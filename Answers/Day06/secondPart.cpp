#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define F first
#define S second
#define endl '\n' 

typedef vector<int> vi;
typedef pair<int, int> ii;

bool check_loop(vector<string> grid, ii start, ii obs) {
    if (start == obs) return false;

    int direction = 0; // 0: up, 1: right, 2: down, 3: left
    ii me = start;

    // Place obstacle
    grid[obs.F][obs.S] = '#';

    // Set to track visited states (position + direction)
    set<pair<ii, int>> vis;

    while (true) {
        // If out of bounds, break
        if (me.F < 0 || me.F >= grid.size() || me.S < 0 || me.S >= grid[0].size()) break;

        // If state is revisited, loop detected
        if (vis.count({me, direction})) return true;

        // Mark state as visited
        vis.insert({me, direction});

        // Handle obstacle
        if (grid[me.F][me.S] == '#') {
            switch (direction) {
                case 0: me.F++; break; // Turn right (down)
                case 1: me.S--; break; // Turn right (left)
                case 2: me.F--; break; // Turn right (up)
                case 3: me.S++; break; // Turn right (right)
            }
            direction = (direction + 1) % 4; // Change direction (right turn)
        }

        // Regular movement in the current direction
        switch (direction) {
            case 0: me.F--; break; // Up
            case 1: me.S++; break; // Right
            case 2: me.F++; break; // Down
            case 3: me.S--; break; // Left
        }
    }

    return false; // No loop found
}

int main() {
    freopen("data.in", "r", stdin);
    vector<string> grid;

    string line;

    ii me;
    while (getline(cin, line)) {
        if (line.empty()) break;
        grid.pb(line);
    }

    for (int i = 0; i < grid.size(); i++) {
        if (grid[i].find('^') != string::npos) {
            me.F = i;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '^') {
                    me.S = j;
                    grid[i][j] = '.';
                    break;
                }
            }
            break;
        }
    }
    ii start = me;

    //cout << x << ' ' << y << endl;

    int direction = 0; // 0 - up; 1 - right; 2 - down; 3 - left.
    set<ii> vis;

    while (true) {
        if (me.F < 0 || me.F >= grid.size() || me.S < 0 || me.S >= grid[0].size()) break;
        else vis.insert({me.F, me.S});
        if (grid[me.F][me.S] == '#') {
            switch (direction) {
                case 0:
                    me.F++;
                    break;
                case 1:
                    me.S--;
                    break;
                case 2:
                    me.F--;
                    break;
                case 3:
                    me.S++;
                    break;
            }
            direction++; direction %= 4;
        }
        switch (direction) {
            case 0:
                me.F--;
                break;
            case 1:
                me.S++;
                break;
            case 2:
                me.F++;
                break;
            case 3:
                me.S--;
                break;
        }
    }

    int ans = 0;
    for (auto i : vis) {
        ans += check_loop(grid, start, i);
    }
    cout << ans << endl;
}
