#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

#define pb push_back 
#define endl '\n' 

typedef vector<int> vi;

int main() {
    freopen("data.in", "r", stdin);
    vector<string> inp;

    string line;

    int x = 0, y = 0;

    while (getline(cin, line)) {
        if (line.empty()) break;
        inp.pb(line);
    }

    for (int i = 0; i < inp.size(); i++) {
        if (inp[i].find('^') != string::npos) {
            x = i;
            for (int j = 0; j < inp[i].size(); j++) {
                if (inp[i][j] == '^') {
                    y = j;
                    inp[i][j] = '.';
                    break;
                }
            }
            break;
        }
    }

    //cout << x << ' ' << y << endl;

    int direction = 0; // 0 - up; 1 - right; 2 - down; 3 - left.

    while (true) {
        if (x < 0 || x >= inp.size() || y < 0 || y >= inp[0].size()) break;
        else inp[x][y] = (inp[x][y] == '#' ? '#' : 'X');
        if (inp[x][y] == '#') {
            switch (direction) {
                case 0:
                    x++;
                    break;
                case 1:
                    y--;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y++;
                    break;
            }
            direction++; direction %= 4;
        }
        switch (direction) {
            case 0:
                x--;
                break;
            case 1:
                y++;
                break;
            case 2:
                x++;
                break;
            case 3:
                y--;
                break;
        }
    }

    int count = 0;
    for (int i = 0; i < inp.size(); i++) {
        for (int j = 0; j < inp[i].size(); j++)
            count += inp[i][j] == 'X';
    }
    cout << count << endl;
}
