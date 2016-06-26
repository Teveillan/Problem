#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

const int N = 405;
int g[N][N];
VI adj[N];
double f[N], max_p[N];

double solve1(int s, int n, const VI &vec) {
    MEM(f, 0);
    for(int x: vec) {
        for(int y: adj[x]) {
            f[y] += 1.0 / vec.size() / adj[x].size();
        }
    }

    VI v;
    FOR(i, 1, n) if(f[i] > 1e-8) v.pb(i);

    double ret = 0;
    FOR(i, 1, n) {
        MEM(max_p, 0);
        for(int x: v) max_p[g[i][x]] = max(max_p[g[i][x]], f[x]);

        double tmp = 0;
        for(int x: v) tmp += max_p[g[i][x]], max_p[g[i][x]] = 0;
        ret = max(ret, tmp);
    }
    return ret;
}

VI vec[N];
double solve(int s, int n) {
    REP(i, n) vec[i].clear();
    FOR(i, 1, n) vec[g[s][i]].pb(i);

    double ret = 0;
    REP(i, n) {
        if(!vec[i].size()) continue;
        double tmp1 = 1.0 / vec[i].size();
        double tmp2 = solve1(s, n, vec[i]);
        ret += max(tmp1, tmp2) * (double)vec[i].size() / n;
    }
    return ret;
}

int main()
{
	freopen("in", "r", stdin);

    int n, m, u, v;
    while(cin >> n >> m) {
        memset(g, 0x3f, sizeof(g));
        FOR(i, 1, n) g[i][i] = 0, adj[i].clear();
        while(m--) {
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
            adj[u].pb(v), adj[v].pb(u);
        }
        FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        double ret = 0;
        FOR(i, 1, n) ret = max(ret, solve(i, n));
        printf("%.8lf\n", ret);
    }
    return 0;
}

