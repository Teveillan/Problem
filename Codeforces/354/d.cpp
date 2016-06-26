#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
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
#define mp make_pair
const int N = 1010;
bool g[N][N][4][4];
char str[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void build(int n, int m) {
    int f[4] = {0};
    FOR(i, 0, n) FOR(j, 0, m) {
        memset(f, 0, sizeof(f));
        char c = str[i][j];
        if(c == '+' || c == '^' || c == '|') f[0] = 1;
        if(c == '+' || c == '>' || c == '-') f[1] = 1;
        if(c == '+' || c == 'v' || c == '|') f[2] = 1;
        if(c == '+' || c == '<' || c == '-') f[3] = 1;

        if(c == 'U') f[1] = f[2] = f[3] = 1;
        if(c == 'R') f[0] = f[2] = f[3] = 1;
        if(c == 'D') f[0] = f[1] = f[3] = 1;
        if(c == 'L') f[0] = f[1] = f[2] = 1;

        REP(k, 4) {
            REP(a, 4) g[i][j][k][a] = f[a];
            int tmp = f[3];
            DWN(i, 3, 1) f[i] = f[i-1];
            f[0] = tmp;
        }
    }
}

int dis[N][N][4];
typedef pair<int, pii> pp;
int inf = 1061109567;
inline void in(int x, int y, int d, int len, queue<pp> &que) {
    if(dis[x][y][d] != inf) return;
    dis[x][y][d] = len;
    que.push(mp(d, mp(x, y)));
}

int solve(int sx, int sy, int ex, int ey) {
    memset(dis, 0x3f, sizeof(dis));
    dis[sx][sy][0] = 0;
    queue<pp> que;
    que.push(mp(0, mp(sx, sy)));
    while(!que.empty()) {
        pp top = que.front(); que.pop();
        int d = top.first, x = top.second.first, y = top.second.second, len = dis[x][y][d] + 1;
        if(x == ex && y == ey) return len - 1;
        in(x, y, (d+1)%4, len, que);

        REP(i, 4) {
            int tox = x + dx[i], toy = y + dy[i];
            if(g[x][y][d][i] && g[tox][toy][d][i^2])
                in(tox, toy, d, len, que);
        }
    }
    return -1;
}

int main()
{
	freopen("in", "r", stdin);
    int n, m, sx, sy, ex, ey;
    while(cin >> n >> m) {
        FOR(i, 1, n) scanf("%s", str[i] + 1);
        FOR(i, 0, n) str[i][0] = str[i][m+1] = '*';
        FOR(i, 0, m) str[0][i] = str[n+1][i] = '*';
        build(n, m);
        cin >> sx >> sy >> ex >> ey;
        cout << solve(sx, sy, ex, ey) << endl;
    }

    return 0;
}

