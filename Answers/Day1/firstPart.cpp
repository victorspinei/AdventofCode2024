#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include "iostream"
#include "vector"
using namespace std;

#define pb push_back 

typedef vector<int> vi;

int main () {
    freopen("data.in", "r", stdin);
    vi firstList, secondList; 
    int idFromFirstList = 0, idFromSecondList = 0, totalDistance = 0, listLength;

    while (cin >> idFromFirstList) {
        firstList.pb(idFromFirstList);
        cin >> idFromSecondList;
        secondList.pb(idFromSecondList);
    }

    listLength = firstList.size();
    sort(firstList.begin(), firstList.end());
    sort(secondList.begin(), secondList.end());
    for (int i = 0; i < listLength; i++) {
        totalDistance += abs(firstList[i] - secondList[i]);
    }
    cout << totalDistance << endl;
}