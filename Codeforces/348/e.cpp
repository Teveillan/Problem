#include <iostream>
#include <cstdlib>
#include <map>
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

typedef pair<pii, int> T;

const int N = 1e5 + 100;
vector<T>head[N];

int node[N];

inline int lowbit(int x) {return x & -x;}
void update(int x, int v) {
    while(x < N) {
        node[x] += v;
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    for(; x; x -= lowbit(x)) {
        ret += node[x];
    }
    return ret;
}

int ans[N];
int main()
{
	freopen("in", "r", stdin);
    int n, p, t, num;
    while(cin >> n) {
        FOR(i, 1, n) head[i].clear();
        memset(ans, -1, sizeof(ans));
        int flag = 0;
        map<int, int>m;
        FOR(i, 1, n) {
            scanf("%d%d%d", &p, &t, &num);
            if(m.find(num) == m.end()) m[num] = ++flag;
            head[m[num]].pb(T(pii(t, i), p));
        }
        FOR(i, 1, flag) sort(head[i].begin(), head[i].end());
        FOR(i, 1, flag) {
            memset(node, 0, sizeof(node));
            for(T top: head[i]) {
                int id = top.first.second;
                if(top.second == 3) ans[id] = query(id);
                else {
                    int v = (top.second == 1 ? 1 : -1);
                    update(id, v);
                }
            }
        }
        FOR(i, 1, n) if(ans[i] != -1) printf("%d\n", ans[i]);
    }

    return 0;
}

