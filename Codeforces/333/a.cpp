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
typedef unsigned long long LL;
typedef pair<int,int> pii;

LL xx[100], yy[100];

int main()
{
	//freopen("in", "r", stdin);
    int n, m, bx, by;
    while(cin >> n >> bx) {
        FOR(i, 1, n) cin >> xx[i];
        cin >> m >> by;
        FOR(i, 1, m) cin >> yy[i];

        LL x = 0, y = 0;
        LL tmp = 1;
        DWN(i, n, 1) {
            x += tmp * xx[i];
            tmp *= bx;
        }
        tmp = 1;
        DWN(i, m, 1) {
            y += tmp * yy[i];
            tmp *= by;
        }



        if(x == y) puts("=");
        else if(x > y) puts(">");
        else puts("<");
    }
    return 0;
}

