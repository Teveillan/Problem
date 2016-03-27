#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> pii;

int solve(LL h1, LL h2, LL a, LL b) {
    LL tmp = max(h1, h2) + 10;
    tmp *= 2;
    REP(i, tmp) {
        if(i == 0) {
            h1 += 8 * a;
            if(h1 >= h2) return i;

            h1 -= 2 * b;
        }
        else {
            h1 -= 10 * b;

            h1 += 12 * a;
            if(h1 >= h2) return i;

            h1 -= 2 * b;
        }
    }
    return -1;
}

int main()
{
	freopen("in", "r", stdin);
    LL h1, h2, a, b;
    while(cin >> h1 >> h2 >> a >> b) {
        cout << solve(h1, h2, a, b) << endl;
    }
    return 0;
}

