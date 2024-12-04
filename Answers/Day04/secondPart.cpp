#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define pb push_back 
#define endl '\n' 

#define calc(a, b) (stoi(a) * stoi(b))

typedef vector<int> vi;

int src(vector<string> grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();

    if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m &&
        grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'S' && 
        grid[i+1][j-1] == 'M' && grid[i+1][j+1] == 'S'
    ) return 1;

    if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m &&
        grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'S' && 
        grid[i+1][j-1] == 'M' && grid[i+1][j+1] == 'M'
    ) return 1;

    if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m &&
        grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'M' && 
        grid[i+1][j-1] == 'S' && grid[i+1][j+1] == 'M'
    ) return 1;

    if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m &&
        grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'M' && 
        grid[i+1][j-1] == 'S' && grid[i+1][j+1] == 'S'
    ) return 1;
    
    return 0;
}

int main() {
    freopen("data.in", "r", stdin);
    int count = 0;

    vector<string> grid;

    string line;
    while (cin >> line) {
        grid.pb(line);
    }
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                count += src(grid, i, j);
            }
        }
    }


    cout << count << endl;
}
