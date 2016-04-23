#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
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

const int N = 2e6 + 100;;
const int NN = 1e5 + 100;
int X = 101, Y = 101, Z = 101;
int fa[N];
int x[NN], y[NN], z[NN];
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

bool visit[105][105][105];

inline int get(int a, int b, int c) {
    return a + b * X + c * X * Y;
}

inline bool check(int a, int b, int c) {
    if(a < 0 || b < 0 || c <= 0) return 0;
    if(a > X || b > Y  || c > Z) return 0;
    return 1;
}

struct Node{
    int a, b, c;
    Node(){}
    Node(int a, int b, int c): a(a), b(b), c(c) {}
};

int find(int a) {
    if(a == fa[a]) return a;
    else return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    fa[b] = a;
}

void bfs(int a, int b, int c) {
    queue<Node>que;
    que.push(Node(a, b, c));
    visit[a][b][c] = 1;
    while(!que.empty()) {
        Node top = que.front(); que.pop();
        REP(i, 6) {
            int aa = top.a + dx[i], bb = top.b + dy[i], cc = top.c + dz[i];
            if(check(aa, bb, cc) && !visit[aa][bb][cc]) {
                visit[aa][bb][cc] = 1;
                merge(get(a, b, c), get(aa, bb, cc));
                que.push(Node(aa, bb, cc));
            }
        }
    }
}

bool solve(int n) {
    DWN(i, n-1, 0) {
        int a = x[i], b = y[i], c = z[i];
        bool flag1 = 0, flag2 = 0;
        REP(j, 6) {
            int aa = a + dx[j], bb = b + dy[j], cc = c + dz[j];
            if(check(aa, bb, cc)) {
                if(find(get(aa, bb, cc)) == find(get(101, 101, 101))) flag1 = 1;
                if(visit[aa][bb][cc]) flag2 = 1;
            }
            if(cc == 0) flag2 = 1;
        }
        if(!flag1 || !flag2) {
            return 0;
        }
        REP(j, 6) {
            int aa = a + dx[j], bb = b + dy[j], cc = c + dz[j];
            if(check(aa, bb, cc)) merge(get(aa, bb, cc), get(a, b, c));
        }
        visit[a][b][c] = 0;
    }
    return 1;
}

int main()
{
	//freopen("in", "r", stdin);

    int n, casnum;
    cin >> casnum;
    while(casnum--) {
        cin >> n;
        MEM(visit, 0);
        REP(i, n) scanf("%d%d%d", &x[i], &y[i], &z[i]), visit[x[i]][y[i]][z[i]] = 1;
        FOR(i, 0, X) FOR(j, 0, Y) FOR(k, 0, Z) fa[get(i, j, k)] = get(i, j, k);
        FOR(i, 0, X) FOR(j, 0, Y) FOR(k, 0, Z) if(!visit[i][j][k]) bfs(i, j, k);

        MEM(visit, 0);
        REP(i, n) visit[x[i]][y[i]][z[i]] = 1;
        FOR(i, 0, X) FOR(j, 0, Y) visit[i][j][0] = 1;

        if(solve(n)) puts("Yes");
        else puts("No");
    }

    return 0;
}

