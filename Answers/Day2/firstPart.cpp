#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

#define pb push_back 
#define endl '\n' 

typedef vector<int> vi;

int main () {
    freopen("data.in", "r", stdin);
    int safeReports = 0;

    string report;
    while (getline(cin, report)) {
        int level = 0;
        vi levels;
        bool flag = true;

        istringstream iss(report);

        while (iss >> level) {
            levels.pb(level);
        }

        int levelsSize = levels.size();
        bool increasing = true, decreasing = true;

        for (int i = 0; i < levelsSize - 1; i++) {
            int delta = abs(levels[i] - levels[i+1]);
            if (delta == 0 || delta > 3) {
                flag = false;
                break;
            }
            if (levels[i] > levels[i+1]) increasing = false;
            if (levels[i] < levels[i+1]) decreasing = false;
        }

        if (flag) {
            flag = increasing || decreasing;
        }

        safeReports += (flag ? 1 : 0);
    
    };

    cout << safeReports << endl;
}