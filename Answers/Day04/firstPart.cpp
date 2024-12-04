#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define pb push_back 
#define endl '\n' 

#define calc(a, b) (stoi(a) * stoi(b))

typedef vector<int> vi;

const string WORD = "XMAS";
const int SIZE = 4;

int src(vector<string> grid, int i, int j) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();

    // up 
    for (int k = 1; k < SIZE; k++) {
        if (i - k < 0 || grid[i - k][j] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // down 
    for (int k = 1; k < SIZE; k++) {
        if (i + k >= n || grid[i + k][j] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // left
    for (int k = 1; k < SIZE; k++) {
        if (j - k < 0 || grid[i][j - k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // right
    for (int k = 1; k < SIZE; k++) {
        if (j + k >= m || grid[i][j + k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // up right
    for (int k = 1; k < SIZE; k++) {
        if (i - k < 0 || j + k >= m || grid[i - k][j + k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // up left
    for (int k = 1; k < SIZE; k++) {
        if (i - k < 0 || j - k < 0 || grid[i - k][j - k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // down right
    for (int k = 1; k < SIZE; k++) {
        if (i + k >= n || j + k >= m || grid[i + k][j + k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 

    // down left
    for (int k = 1; k < SIZE; k++) {
        if (i + k >= n || j - k < 0 || grid[i + k][j - k] != WORD[k]) break;
        if (k == SIZE - 1) count++;
    } 
    
    return count;
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
            if (grid[i][j] == 'X') {
                count += src(grid, i, j);
            }
        }
    }


    cout << count << endl;
}
