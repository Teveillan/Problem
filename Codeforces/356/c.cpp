#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
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


const int N = 510;
const int M = N * N;
bool g[N][N], visit[N][N];
char str[N];
int fa[M], sum[M];
int lx[M], rx[M], ly[M], ry[M];
int q[N][N], f[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
bool check(int x, int y) {
    if(x < 1 || x > n) return 0;
    if(y < 1 || y > n) return 0;
    return g[x][y];
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int get(int x, int y) {return (x-1) * n + y-1;}
void merge(int x1, int y1, int x2, int y2) {
    int a = get(x1, y1), b = get(x2, y2);
    a = find(a), b = find(b);
    if(a != b) {
        sum[a] += sum[b], fa[b] = a;
        lx[a] = min(lx[a], lx[b]);
        rx[a] = max(rx[a], rx[b]);
        ly[a] = min(ly[a], ly[b]);
        ry[a] = max(ry[a], ry[b]);
    }
}

bool z[M];
int solve(int x, int y) {
    if(!check(x, y)) return 0;
    int a = find(get(x, y));
    if(z[a]) return 0;
    z[a] = 1;
    return sum[a];
}

int main()
{
    freopen("in", "r", stdin);
    while(cin >> n >> m) {
        MEM(visit, 0), MEM(g, 0);
        MEM(f, 0), MEM(sum, 0), MEM(q, 0);
        FOR(i, 1, n) {
            scanf("%s", str + 1);
            FOR(j, 1, n) g[i][j] = str[j] == '.';
        }

        FOR(i, 1, n) FOR(j, 1, n) if(g[i][j]) {
            int a = get(i, j);
            lx[a] = rx[a] = i;
            ly[a] = ry[a] = j;
            fa[a] = a, sum[a] = 1;
        }
        FOR(i, 1, n) FOR(j, 1, n) f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + g[i][j];
        FOR(i, 1, n) FOR(j, 1, n) if(g[i][j] && !visit[i][j]) {
            visit[i][j] = 1;
            queue<pii> que;
            que.push(pii(i, j));
            while(!que.empty()) {
                int xx = que.front().first, yy = que.front().second;
                que.pop();
                REP(k, 4) {
                    int x = xx + dx[k], y = yy + dy[k];
                    if(check(x, y) && !visit[x][y]) {
                        visit[x][y] = 1;
                        que.push(pii(x, y));
                        merge(xx, yy, x, y);
                    }
                }
            }

            int a = find(get(i, j));
            if(rx[a] - lx[a] + 1 <= m && ry[a] - ly[a] + 1 <= m) {
                int l = max(rx[a], m);
                int r = min(lx[a] + m - 1, n);
                int ll = max(ry[a], m);
                bool flag = (ly[a] + m <= n);
                FOR(k, l, r) {
                    q[k][ll] += sum[a];

                    if(flag)
                        q[k][ly[a] + m] -= sum[a];
                }
            }
        }

        int ret = 0;
        set<int>s;
        FOR(i, m, n) {
            int tmp = 0;
            FOR(j, 1, n) {
                memset(z, 0, sizeof(z));
                tmp += q[i][j];
                int ans = 0;
                REP(k, m) {
                    ans += solve(i+1, j - k);
                    ans += solve(i - k, j+1);
                    ans += solve(i - m, j - k);
                    ans += solve(i - k, j - m);
                }
                ans += m * m - (f[i][j] - f[i-m][j] - f[i][j-m] + f[i-m][j-m]);
                ans += tmp;
                ret = max(ret, ans);
            }
        }
        cout << ret << endl;
    }
    return 0;
}

