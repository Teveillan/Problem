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


int main()
{
	//freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        map<int, int>f1, f2;
        int x, y;
        while(n--) {
            scanf("%d%d", &x, &y);
            ++f1[x+y];
            ++f2[x-y];
        }
        LL ans = 0;
        FOR(i, -2000, 2000) {
             ans += (LL)f1[i] * (f1[i] - 1) / 2;
             ans += (LL)f2[i] * (f2[i] - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

