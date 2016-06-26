#include <iostream>

#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
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
const int N = 1000 * 1000 + 10;

int n, m;
LL k;
vector<int, pii> vec;
int fa[N], num[N];
int v[1000][1000], visit[1000][1000];
inline int get(int x, int y) {return x*m+y;}
inline bool check(int x, int y) {
    if(x<0 || x>=n) return 0;
    if(y<0 || y>=m) return 0;
    return 1;
}

inline int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

VI pri;
int solve(LL x, LL y) {
    LL tmp = min(x, y);
    for(int i = 0; i < pri.size() && pri[i] <= x; ++i) {
        if(k / pri[i] <= y)
            return x;
    }
    return -1;
}

void init() {
    pri.clear();
    FOR(i, 1, n * m) {
        if(k % i == 0) pri.pb(i);
    }
}

int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
        REP(i, n)
            REP(i, m) {
                scanf("%d", &v[x][y]);
                vec.pb(make_pair(v[x][y], pii(x, y)));
                fa[get(x,y)] = get(x, y);
                num[get(x, y)] = 1;
            }
        sort(vec.begin(), vec.end());
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        bool flag = 0;
        int max_num = 0;
        for(int i = vec.size()-1; i != -1; --i) {
                x = vec[i].second.first, y = vec[i].second.second;
                REP(j, 4) {
                    int tox = x + dx[j], toy = y + dy[j];
                    if(!check(tox, toy)) continue;
                    int xx = find(get(x, y)), yy = find(get(tox, toy));
                    if(xx == yy) continue;
                    fa[yy] = xx;
                    num[xx] += yy;
                    max_num = max(max_num, num[xx]);

                    int sum = solve(max_num, vec[i].first);
                    if(sum != -1) {
                        k /= sum;
                        flag = 1;
                        memset(visit, 0, sizeof(visit));
                        queue<pii>que;
                        que.push(pii(x, y));
                        while(!que.empty()) {
                            pii top = que.front(); que.pop();
                            for(int j = 0; j < 4 && sum; j++) {
                                x = top.first + dx[j], y = top.second + dy[j];
                                if(check(x, y) && !visit[x][y]) {
                                    visit[x][y] = 1;
                                    que.push(pii(x, y));
                                    --sum;
                                }
                            }
                        }
                    }
                    if(flag) break;
                }
            if(flag) break;
        }
        if(!flag) puts("NO");
        else puts("YES");

        REP(i, n) {
            REP(j, n) {
                if(j) putchar(' ');
                printf("%lld", k);
            }
            puts("");
        }


    }
    return 0;
}

