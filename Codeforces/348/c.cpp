#include <iostream>
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
int ans[110][110];
struct Node {
    int t, x, y, c;
    Node(int t, int x, int y = -1, int c = -1) : t(t), x(x), y(y), c(c){}
};


int main()
{
	freopen("in", "r", stdin);
    int n, m, q;
    int t, x, y, c;
    while(cin >> n >> m >> q) {
        memset(ans, 0, sizeof(ans));
        vector<Node> que, vec;
        REP(i, q) {
            scanf("%d", &t);
            if(t == 3) scanf("%d%d%d", &x, &y, &c);
            else scanf("%d", &x);
            --x, --y;
            que.pb(Node(t, x, y, c));
        }

        DWN(i, q-1, 0) {
            if(que[i].t == 3) vec.pb(que[i]);
            else {
                t = que[i].t, x = que[i].x;
                if(t == 1) for(Node &top: vec) {
                    if(top.x == x) top.y = (top.y + 1) % m;
                }
                if(t == 2) for(Node &top: vec) {
                    if(top.y == x) top.x = (top.x + 1) % n;
                }
            }
        }
        for(Node top: vec) ans[top.x][top.y] = top.c;
        REP(i, n) {
            REP(j, m) printf("%d ", ans[i][j]);
            puts("");
        }
    }
    return 0;
}

