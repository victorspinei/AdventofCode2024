#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define endl '\n' 

typedef vector<int> vi;

int main() {
    freopen("data.in", "r", stdin);

    map<int, set<int>> orderingRules;
    map<int, set<int>> secondOrderingRules;
    string line;

    auto sorter = [&](int a, int b){return secondOrderingRules[a].count(b) > 0;};

    // ordering Rules
    while (getline(cin, line)) {
        int n = line.size();
        if (line.empty()) break;
        int i = 0;
        for (; i < n; i++) if (line[i] == '|') break;
        int a = stoi(line.substr(0, i));
        int b = stoi(line.substr(i+1, n - i - 1));

        orderingRules[b].insert(a);
        secondOrderingRules[a].insert(b);
    }

    long long sum = 0;

    // updates
    while (getline(cin, line)) {
        vi list;
        int n = line.size();
        int i = 0, j = 0;
        for (; i < n; i++) {
            if (line[i] == ',') {
                list.pb(stoi(line.substr(j, i - j)));
                j = i+1;
            }
        }
        list.pb(stoi(line.substr(j, i - j)));
        int m = list.size();

        bool orderedCorectly = true;

        for (i = m - 1; i >= 1; i--) {
            if (orderingRules[list[i]].count(list[i-1]) == 0) {
                orderedCorectly = false;
                break;
            }
        }


        if (orderedCorectly) {
            continue;
        }

        sort(list.begin(), list.end(), sorter);
        sum += list[m / 2];

    }
    cout << sum << endl;
}
