#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
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

const int N = 1e5 + 100;
VI adj[N];
set<int>q[N];
set<pii, greater<pii> >remain[N];
set<pii>lca[N];
int ans[N], fa[N];

bool flag[N];
int find(int x) {return x == fa[x]?x : fa[x] = find(fa[x]);}
int stmp[N], ss;
void dfs(int cur, int pre) {
    stmp[cur] = ++ss;
    for(int id: q[cur]) {
        if(q[pre].count(id)) flag[id] = 1;
        if(!remain[id].empty()) {
            int x = remain[id].begin() -> second;
            int y = find(x);
            lca[y].insert(pii(id, cur));
            lca[y].insert(pii(id, x));
        }
        remain[id].insert(pii(stmp[cur], cur));
    }
    for(int to: adj[cur]) if(to != pre) {
        dfs(to, cur);
        fa[to] = cur;
    }

    map<int, int>m;
    for(pii top: lca[cur]) {
        int id = top.first, x = top.second;
        if(x != cur && remain[id].count(pii(stmp[x], x))) ++m[id];
    }

    for(pii top: m) {
        int id = top.first, num = top.second;
        if(q[cur].count(id)) ans[id] += num;
        else if(num >= 2) ++ans[id];
    }

    for(pii top: lca[cur]) {
        int id = top.first, x= top.second;
        if(q[cur].count(id)) {
            if(x != cur)remain[id].erase(pii(stmp[x], x));
        }
        else if(m[id] >= 2) remain[id].erase(pii(stmp[x], x));
    }
}

int main()
{
	freopen("in", "r", stdin);
    int n, x, y, num, m;
    while(cin >> n) {
        ss = 0;
        MEM(fa, 0), MEM(ans, 0), MEM(flag, 0);
        FOR(i, 0, n) adj[i].clear(), q[i].clear(), lca[i].clear(), fa[i] = i;
        REP(i, n - 1) {
            scanf("%d%d", &x, &y);
            adj[x].pb(y), adj[y].pb(x);
        }
        cin >> m;
        REP(i, m) remain[i].clear();
        REP(i, m) {
            scanf("%d", &num);
            while(num--) {
                scanf("%d", &x);
                q[x].insert(i);
            }
        }
        dfs(1, 0);
        REP(i, m) printf("%d\n", flag[i]?-1:ans[i]);
    }
    return 0;
}
