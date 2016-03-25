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

const int N = 410;
bool g[N][N];
bool visit[N][N];
pii que[2][N*N];
int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
         memset(g, 0, sizeof(g));
         memset(visit, 0, sizeof(visit));
         while(m--) {
             scanf("%d%d", &x, &y);
             g[x][y] = g[y][x] = 1;
         }

        int cur = 1, pre = 0;
        int r[2] = {0};
        que[cur][r[cur]++] = pii(1, 1);
        visit[1][1] = 1;
        int ans = 0;
        bool flag = 0;
        while(1) {
             if(ans == n+10) break;
             ++ans;
             cur ^= 1, pre ^= 1;
             r[cur] = 0;

             FOR(i, 1, n)
                 FOR(j, 1, n)
                 if(!visit[i][j]) {
                     if(i == j && i != n) continue;

                     REP(k, r[pre]) {
                         x = que[pre][k].first, y = que[pre][k].second;
                         if(g[i][x] && !g[j][y]) {
                             if(i == n && j == n) flag = 1;
                             visit[i][j] = 1;
                             que[cur][r[cur]++] = pii(i, j);
                             break;
                         }
                     }
                 }
            if(flag) break;
        }
        if(!flag) puts("-1");
        else cout << ans << endl;
    }

    return 0;
}

