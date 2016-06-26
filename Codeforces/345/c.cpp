#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <functional>
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
const int N = 1e6 + 10;
vector<pii>vec;
int n, m;
bool visit[N];

int fa[N];
int find(int x) {return x == fa[x]?x:fa[x] = find(fa[x]);}

VI adj[N];
void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[v] = u;
}
int q[N];

int degree[N];
void add(int u, int v) {
    adj[u].pb(v);
    ++degree[v];
}
int ans[N];
int main()
{
	freopen("in", "r", stdin);
    int v;
    while(cin >> n >> m) {
        REP(i, n*m) fa[i] = i;
        map<pii, int>f[2];
        REP(i, n) REP(j, m) {
            scanf("%d", &v);
            if(f[0].count(pii(i, v))) merge(f[0][pii(i, v)], i*m+j);
            if(f[1].count(pii(j, v))) merge(f[1][pii(j, v)], i*m+j);
            f[0][pii(i, v)] = i*m + j;
            f[1][pii(j, v)] = i*m + j;
            q[i*m+j] = v;
        }
        REP(i, n*m) adj[i].clear();
        MEM(degree, 0);
        vector<pii> vec;
        REP(i, n) {
            vec.resize(m);
            REP(j, m) vec[j] = pii(q[i*m+j], i*m+j);
            sort(vec.begin(), vec.end());

            int l = 0, r = 0;
            while(r < vec.size()) {
                while(r < vec.size() && vec[l].first == vec[r].first) r++;
                if(r != vec.size()) add(find(vec[l].second), find(vec[r].second));
                l = r;
            }

        }
        REP(i, m) {
            vec.resize(n);
            REP(j, n) vec[j] = pii(q[j*m+i], j*m+i);
            sort(vec.begin(), vec.end());

            int l = 0, r = 0;
            while(r < vec.size()) {
                while(r < vec.size() && vec[l].first == vec[r].first) r++;
                if(r != vec.size()) add(find(vec[l].second), find(vec[r].second));
                l = r;
            }
        }
        memset(ans, 0, sizeof(ans));
        memset(visit, 0, sizeof(visit));
        queue<int>que;

        REP(i, n*m) if(!degree[find(i)] && !visit[find(i)]) que.push(i), visit[find(i)] = 1, ans[find(i)] = 1;
        while(!que.empty()) {
            int top = que.front(); que.pop();
            for(int to: adj[top]) {
                if(--degree[to] == 0) que.push(to);
                ans[to] = max(ans[to], ans[top] + 1);
            }
        }
        REP(i, n) {
            REP(j, m) printf("%d ", ans[find(i*m+j)]);
            puts("");
        }
    }
    return 0;
}

