#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include "iostream"
#include "vector"
using namespace std;

#define pb push_back 

typedef vector<int> vi;
typedef unordered_map<int, int> umii;

int main () {
    freopen("data.in", "r", stdin);
    vi firstList; 
    umii appearanceCount;
    int idFromFirstList = 0, idFromSecondList = 0, totalSimilarityScore = 0, listLength;

    while (cin >> idFromFirstList) {
        firstList.pb(idFromFirstList);
        cin >> idFromSecondList;
        appearanceCount[idFromSecondList]++;
    }

    listLength = firstList.size();

    for (int i = 0; i < listLength; i++) {
        totalSimilarityScore += firstList[i] * appearanceCount[firstList[i]];
    }
    cout << totalSimilarityScore << endl;
}