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

const int N = 1e6 + 100;
int f[N];
int g[N];

int solve(int num) {
    int ret = 0;
    int tmp = 1e6 + 100;
    DWN(i, num-1, 0) {
        if(tmp <= g[i]) continue;
        if(f[ g[i] ] > g[i]) return 0;
        ++ret;
        tmp = f[ g[i] ];
    }
    return ret;
}


int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y, num ;
    while(cin >> n >> m) {
        vector<pii>vec;
        REP(i, n) {
            scanf("%d%d", &x, &y);
            vec.pb(pii(y, x));
        }
        sort(vec.begin(), vec.end());
        int r = n-1, l = 1e6 + 10;
        FOR(i, 1, 1e6) f[i] = 1e6 + 10;
        DWN(i, 1e6, 1) {
            while(r>=0 && vec[r].first >= i) {
                l = min(l, vec[r].second);
                r--;
            }
            f[i] = l;
        }

        while(m--) {
            scanf("%d", &num);
            REP(i, num) scanf("%d", &g[i]);
            printf("%d\n", solve(num));
        }
    }
    return 0;
}

