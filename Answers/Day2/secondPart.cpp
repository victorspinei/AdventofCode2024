#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define endl '\n' 

typedef vector<int> vi;

// Helper function to check if a report is safe
bool isSafe(const vi& vec) {
    bool onlyIncreasing = true, onlyDecreasing = true, safeDistance = true;

    int k = vec.size();
    for (int i = 0; i < k - 1; i++) {
        int delta = abs(vec[i] - vec[i + 1]);

        // Safe distance check
        if (delta < 1 || delta > 3) {
            safeDistance = false;
        }

        // Monotonicity checks
        if (vec[i] > vec[i + 1]) {
            onlyIncreasing = false;
        }
        if (vec[i] < vec[i + 1]) {
            onlyDecreasing = false;
        }
    }

    // A report is safe if it satisfies any of the rules
    return (onlyIncreasing || onlyDecreasing) && safeDistance;
}

int main() {
    freopen("data.in", "r", stdin);
    int safeReports = 0;

    string report;
    while (getline(cin, report)) {
        if (report.empty()) continue;

        vi levels;
        istringstream iss(report);
        int level;

        while (iss >> level) {
            levels.pb(level);
        }

        bool anyOk = false;
        auto consider = [&](int i) {
            vi copy = levels;
            copy.erase(copy.begin() + i);
            if (isSafe(copy)) {
                anyOk = true;
            }
        };

        consider(0);
        int k = levels.size();
        for (int i = 0; i < k - 1; i++) {
            int delta = levels[i+1] - levels[i];
            if (abs(delta) < 1 || abs(delta) > 3) {
                consider(i);
                consider(i + 1);
                break;
            }
            if (i + 2 < k) {
                int delta2 = levels[i+2] - levels[i+1];
                if ((delta > 0) != (delta2 > 0)) {
                    consider(i);
                    consider(i+1);
                    consider(i+2);
                    break;
                } 
            }
        }
        

        safeReports += anyOk;
    }

    cout << safeReports << endl;
    return 0;
}
