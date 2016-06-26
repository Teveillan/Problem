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
bool visit[N], isNotAc[N], flag[N];
VI adj[N];
int deep[N];
VI ans;
int gift[N];

bool dfs(int cur, int pre, int deep) {
    if(gift[cur] == cur) ans.pb(cur);
    else if(pre != -1) {
        if(gift[cur] != gift[pre]) return 0;
        if(!flag[gift[cur]]) ans.pb(gift[cur]);
    }
    flag[gift[cur]] = 1;

    for(int to: adj[cur]) {
        if(!dfs(to, cur, deep + 1)) return 0;
    }
    return 1;
}

bool solve(int n) {
    ans.clear();
    FOR(i, 1, n) if(!isNotAc[i]) {
        if(!dfs(i, -1, 1)) return 0;
    }
    return 1;
}

int main()
{
	freopen("in", "r", stdin);
    int n, m, u, v;
    while(cin >> n >> m) {
        MEM(visit, 0), MEM(isNotAc, 0), MEM(flag, 0);
        FOR(i, 1, n) adj[i].clear();
        while(m--) {
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            isNotAc[v] = 1;
        }
        FOR(i, 1, n) scanf("%d", &gift[i]);
        if(!solve(n)) puts("-1");
        else {
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(int x: ans) printf("%d\n", x);
            puts("");
        }
    }

    return 0;
}

