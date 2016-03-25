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

int SG[10001], f[101];

int dfs(int x, int m) {
    if(SG[x] != -1) return SG[x];
    bool mex[102] = {0};
    REP(i, m) {
        int tmp = x - f[i];
        if(tmp < 0) break;
        mex[dfs(tmp, m)] = 1;
    }

    REP(i, 102) if(!mex[i]) {
        return SG[x] = i;
    }
    return 0;
}

int main()
{
	freopen("in", "r", stdin);
    int n, m, k, x;
    while(cin >> n && n) {
        memset(SG, -1, sizeof(SG));
        REP(i, n) scanf("%d", &f[i]);
        sort(f, f + n);
        cin >> m;
        while(m--) {
            int ans = 0;
            cin >> k;
            while(k--) {
                scanf("%d", &x);
                ans ^= dfs(x, n);
            }
            if(ans) putchar('W');
            else putchar('L');
        }
        puts("");
    }
    return 0;
}

