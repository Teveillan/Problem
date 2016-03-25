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
#define CLR(arr) memset(arr, 0, sizeof(arr))

typedef vector<int> VI;
typedef pair<int,int> pii;

const int N = 2e5 + 100;
int node[2][N];
inline int lowbit(int x) {return x&-x;}
void update(int x, int value, int n, int flag) {
    while(x <= n) {
        node[flag][x] += value;
        x += lowbit(x);
    }
}
int query(int x, int flag) {
    int ret = 0;
    while(x) {
        ret += node[flag][x];
        x -= lowbit(x);
    }
    return ret;
}

VI head[N], vec[N];
vector<pii> lca[N], qhead[N];
int fa[N];
int find(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

bool visit[N];
void LCA(int cur, int pre) {
    visit[cur] = 1;
    REP(i, head[cur].size()) {
        int to = head[cur][i];
        if(visit[to]) continue;
        LCA(to, cur);
    }
    REP(i, qhead[cur].size()) {
        int to = qhead[cur][i].first, x = qhead[cur][i].second;
        if(visit[to]) {
            int tmp = find(to);
            lca[tmp].pb(pii(cur, to));
            vec[tmp].pb(x);
        }
    }
    fa[cur] = pre;
}

int l[N], r[N];
int dp[N], sum[N];
int t;
void dfs(int cur, int n) {
    visit[cur] = 1;
    l[cur] = ++t;
    REP(i, head[cur].size()) {
         int to = head[cur][i];
         if(visit[to]) continue;
         dfs(to, n);
         sum[cur] += dp[to];
    }
    REP(i, lca[cur].size()) {
        int u = lca[cur][i].first, v = lca[cur][i].second, x = vec[cur][i];
        int tmp = sum[cur] + query(l[u], 0) + query(l[v], 0) - query(l[u], 1) - query(l[v], 1) + x;
        dp[cur] = max(tmp, dp[cur]);
    }
    r[cur] = ++t;
    dp[cur] = max(dp[cur], sum[cur]);
    update(l[cur], sum[cur], n*2, 0);
    update(r[cur], -sum[cur], n*2, 0);
    update(l[cur], dp[cur], n*2, 1);
    update(r[cur], -dp[cur], n*2, 1);
}

int main()
{
    int casnum, n, m, u, v, x;
    cin >> casnum;
    while(casnum--) {
         cin >> n >> m;
         CLR(node);
         FOR(i, 1, n) head[i].clear(), qhead[i].clear(), lca[i].clear(), vec[i].clear();
         FOR(i, 1, n) fa[i] = i;
         REP(i, n-1) {
            scanf("%d%d", &u, &v);
            head[u].pb(v);
            head[v].pb(u);
         }

         REP(i, m) {
             scanf("%d%d%d", &u, &v, &x);
             qhead[u].pb(pii(v, x));
             qhead[v].pb(pii(u, x));
         }
         memset(sum, 0, sizeof(sum));
         memset(dp, 0, sizeof(dp));
         t = 0;
         CLR(visit);
         LCA(1, 1);
         CLR(visit);
         dfs(1, n);
         cout << dp[1] << endl;
    }
    return 0;
}

