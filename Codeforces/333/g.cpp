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

const int N = 1 << 13;
int lca[13][13];
LL dp[N][13];
vector<pii> head[13];
VI g[13];
bool check(int root1, int root2, int pos1, int pos2, int n) {
    REP(i, n) {
        for(pii tmp: head[i]) {
            int j = tmp.first, c = tmp.second;
            if((pos1 & (1<<i)) && (pos2 & (1<<j))) {
                if(c != root1) return 0;
            }
        }
        for(int j: g[i]) {
            if((pos1 & (1<<i)) && (pos2 & (1<<j))) {
                if(!(i == root1 && j == root2)) return 0;
            }
        }
    }
    return 1;
}

int main()
{
	freopen("in", "r", stdin);

    int n, m, q, u, v, c;
    while(cin >> n >> m >> q) {
        memset(dp, 0, sizeof(dp));
        memset(g, 0, sizeof(g));
        memset(lca, -1, sizeof(lca));
        REP(i, n) head[i].clear(), g[i].clear();
        bool flag = 0;
        while(m--) {
            scanf("%d%d", &u, &v); --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        while(q--) {
            scanf("%d%d%d", &u, &v, &c); --u, --v, --c;
            if(lca[u][v] != -1 && lca[u][v] != c) flag = 1;
            if(u == v && u != c) flag = 1;
            lca[u][v] = lca[v][u] = c;
            head[u].pb(pii(v, c));
            head[v].pb(pii(u, c));
        }
        if(flag) {
             puts("0");
             continue;
        }

        REP(i, n) dp[1<<i][i] = 1;
        REP(pos, 1<<n) {
            for(int pos1 = pos&(pos-1); pos1; pos1 = pos&(pos1-1)) {
                int pos2 = pos ^ pos1;
                REP(i, n) if(dp[pos1][i]) {
                    if((pos1^(1<<i)) > pos2) continue;
                    REP(j, n) if(dp[pos2][j]) {
                        if(check(i, j, pos1, pos2, n)) dp[pos][i] += dp[pos1][i] * dp[pos2][j];
                    }
                }
            }
        }
        cout << dp[(1<<n) - 1][0] << endl;
    }
    return 0;
}

