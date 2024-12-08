#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define pb push_back 
#define F first
#define S second
#define endl '\n' 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long ll;

bool solve(ll result, vector<ll> nums, ll current, ll i) {
    if (current == result && i == nums.size()) return true;
    else if (i == nums.size()) return false;
    
    if (current > result) return false;

    return solve(result, nums, current + nums[i], i+1ll) || 
            solve(result, nums, current * nums[i], i+1ll);
}

int main() {
    freopen("data.in", "r", stdin);

    ll ans = 0;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream st(line);
        ll result, num;
        vector<ll> nums;
        st >> result;
        char _;
        st >> _;
        while (st >> num) {
            nums.pb(num);
        }

        //cout << line << endl;
        //for (auto i : nums) cout << i << ' ';
        //cout << endl;

        if (!nums.empty() && solve(result, nums, nums[0], 1l)) ans += result;
    }
    cout << ans << endl;
}
