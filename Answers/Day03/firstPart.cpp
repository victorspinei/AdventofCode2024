#include <bits/stdc++.h>
#include <cctype>
using namespace std;

#define pb push_back 
#define endl '\n' 

#define calc(a, b) (stoi(a) * stoi(b))

typedef vector<int> vi;

int main() {
    freopen("data.in", "r", stdin);
    int sum = 0;

    string input;
    while (cin >> input) {
        int n = input.size();

        for (int i = 0; i < n; i++) {
            if (i + 3 < n && input.substr(i, 4) == "mul(") {
                i += 4; // Move past "mul("
                string a, b;

                // Parse the first number
                while (i < n && input[i] != ',' && isdigit(input[i])) {
                    a += input[i++];
                }
                if (i == n || input[i] != ',') continue; // Ensure valid delimiter
                i++; // Move past ','

                // Parse the second number
                while (i < n && input[i] != ')' && isdigit(input[i])) {
                    b += input[i++];
                }
                if (i == n || input[i] != ')') continue; // Ensure valid closing parenthesis

                // Calculate and add the result
                if (!a.empty() && !b.empty() && a.size() <= 3 && b.size() <= 3) {
                    sum += calc(a, b);
                }

                //cout << a << " " << b << endl;
            }
        }
    }

    cout << sum << endl;

}
