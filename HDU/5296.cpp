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

const int N = 1e5 + 10;
vector<pii> head[N];
bool visit[N];
int dfn[N], deep[N], dis[N], fa[N][20];
void dfs(int cur, int pre, int &t) {
    dfn[cur] = ++t;
    deep[cur] = deep[pre] + 1;
    fa[cur][0] = pre;
    FOR(i, 1, 19) fa[cur][i] = fa[ fa[cur][i-1] ][i-1];
    REP(i, head[cur].size()) {
        int to = head[cur][i].first, c = head[cur][i].second;
        if(to != pre) {
            dis[to] = dis[cur] + c;
            dfs(to, cur, t);
        }
    }
}

int lca(int u, int v) {
    if(deep[u] < deep[v]) swap(u, v);
    int tmp = deep[u] - deep[v];
    REP(i, 20) if(tmp & (1 << i)) u = fa[u][i];
    if(u == v) return u;
    DWN(i, 19, 0) if(fa[u][i] != fa[v][i])
        u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

map<int, int>M;
void add(int x, int &ans) {
    visit[x] = 1;
    if(M.size() == 0) {
        M[dfn[x]] = x;
        return;
    }
    map<int, int>::iterator it1, it2;
    it1 = M.lower_bound(dfn[x]), it2 = it1;
    if(it1 == M.begin() || it1 == M.end()) it1 = M.begin(), it2 = M.end();
    it2--;

    int u = it1->second, v = it2->second;
    ans += dis[x] - dis[lca(u, x)] - dis[lca(v, x)] + dis[lca(u, v)];
    M[dfn[x]] = x;
}

void del(int x, int &ans) {
    visit[x] = 0;
    M.erase(dfn[x]);
    if(M.size() == 0) return;

    map<int, int>::iterator it1, it2;
    it1 = M.lower_bound(dfn[x]), it2 = it1;
    if(it1 == M.begin() || it1 == M.end()) it1 = M.begin(), it2 = M.end();
    it2--;

    int u = it1->second, v = it2->second;
    ans -= dis[x] - dis[lca(u, x)] - dis[lca(v, x)] + dis[lca(u, v)];
}

int main()
{
	//freopen("in", "r", stdin);
    int n, m, casnum, u, v, c, t, casid = 0;
    cin >> casnum;
    while(casnum--) {
        memset(visit, 0, sizeof(visit));
        cin >> n >> m;
        FOR(i, 1, n) head[i].clear();
        REP(i, n-1) {
            scanf("%d%d%d", &u, &v, &c);
            head[u].pb(pii(v, c));
            head[v].pb(pii(u, c));
        }
        t = 0;
        dfs(1, 0, t);
        int ans = 0;
        printf("Case #%d:\n", ++casid);
        M.clear();
        while(m--) {
            scanf("%d%d", &u, &v);
            if(u == 1 && !visit[v]) add(v, ans);
            if(u == 2 && visit[v]) del(v, ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}

