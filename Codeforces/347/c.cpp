#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
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

const int N = 1e5 + 10;
VI head[N][2], ans[2];
stack<int>s;
int num;
bool visit[N], flag[N];

bool dfs(int cur, int v) {
    visit[cur] = 1;
    s.push(cur);
    if(flag[cur]) ++num;
    REP(color, 2)
        for(int to: head[cur][color]) {
            int tmp = flag[cur] ^ color ^ v;
            if(visit[to]) {
                if(flag[to] != tmp) return 0;
            } else {
                flag[to] = tmp;
                if(!dfs(to, v)) return 0;
            }
        }
    return 1;
}

int solve(int n, int v) {
    memset(visit, 0, sizeof(visit));
    memset(flag, 0, sizeof(flag));

    FOR(i, 1, n) if(!visit[i]) {
        while(!s.empty()) s.pop();
        num = 0;

        if(!dfs(i, v)) return 1e9;
        int m = s.size();
        int tmp = (num * 2 <= m ? 1 : 0);
        while(!s.empty()) {
            int top = s.top(); s.pop();
            if(flag[top] == tmp) ans[v].pb(top);
        }
    }
    return ans[v].size();
}

int main()
{
	freopen("in", "r", stdin);

    int n, m, x, y;
    char c;
    while(cin >> n >> m) {
        FOR(i, 1, n) REP(j, 2) head[i][j].clear();
        REP(i, 2) ans[i].clear();
        while(m--) {
            scanf("%d%d %c", &x, &y, &c);
            int tmp = (c == 'B' ? 0 : 1);
            head[x][tmp].pb(y), head[y][tmp].pb(x);
        }
        int ret0 = solve(n, 0), ret1 = solve(n, 1);
        if(ret0 == 1e9 && ret1 == 1e9) puts("-1");
        else {
            int ret = (ret0 < ret1 ? 0 : 1);
            cout << ans[ret].size() << endl;
            for(int v: ans[ret]) printf("%d ", v);
            puts("");
        }

    }
    return 0;
}

