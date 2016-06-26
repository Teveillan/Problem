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
#define L pos << 1
#define R pos << 1 | 1
#define MID ((l+r)>>1)
const int N = 3e5 + 100;
struct T {
    pii node[N << 2], lazy[N << 2];
    void push_up(int pos) {
        node[pos] = min(node[L], node[R]);
    }

    void push_down(int pos) {
        if(lazy[pos].first == 1e9) return;
        node[L] = min(node[L], lazy[pos]);
        node[R] = min(node[R], lazy[pos]);
        lazy[L] = min(lazy[L], lazy[pos]);
        lazy[R] = min(lazy[R], lazy[pos]);
        lazy[pos] = pii(1e9, 1e9);
    }
    void update(int pos, int l, int r, int ll, int rr, pii value) {
        if(ll > r || rr < l) return;
        if(ll <= l && rr >= r) node[pos] = min(node[pos], value), lazy[pos] = min(lazy[pos], value);
        else {
            push_down(pos);
            update(L, l, MID, ll, rr, value);
            update(R, MID+1, r, ll, rr, value);
            push_up(pos);
        }
    }
    void set(int pos, int l, int r, int id, pii value) {
        if(l == r) node[pos] = value;
        else {
            push_down(pos);
            if(id <= MID) set(L, l, MID, id, value);
            else set(R, MID+1, r, id, value);
            push_up(pos);
        }
    }

    pii query(int pos, int l, int r, int id) {
        if(l == r) return node[pos];
        else {
            push_down(pos);
            pii ret = (id <= MID ? query(L, l, MID, id) : query(R, MID+1, r, id));
            push_up(pos);
            return ret;
        }
    }

    void erase(int pos, int l, int r, int id) {
        if(l == r) node[pos] = pii(1e9, 1e9);
        else {
            push_down(pos);
            if(id <= MID) erase(L, l, MID, id);
            else erase(R, MID+1, r, id);
            push_up(pos);
        }
    }
}t;

VI adj[N];
int son[N],  max_son[N];
pii ans[N];
void dfs1(int cur) {
    son[cur] = 1, max_son[cur] = 0;
    for(int to: adj[cur]) {
        dfs1(to);
        son[cur] += son[to];
        max_son[cur] = max(max_son[cur], son[to]);
    }
}
vector<int>vec;
void dfs2(int cur, int n) {
    vec.pb(son[cur]);
    t.set(1, 0, n, vec.size() - 1, pii(1e9, 1e9));

    for(int to: adj[cur]) dfs2(to, n);

    int id = lower_bound(vec.begin(), vec.end(), son[cur] * 2, greater<int>()) - vec.begin();

    t.update(1, 0, n, id, vec.size() - 1, pii(max_son[cur], cur));
    ans[cur] = t.query(1, 0, n, vec.size() - 1);
    t.erase(1, 0, n, vec.size() - 1);
    vec.pop_back();
}

int main()
{
	//freopen("in", "r", stdin);
    int n, m, x;
    while(cin >> n >> m) {
        FOR(i, 1, n) adj[i].clear();
        vec.clear();

        FOR(i, 2, n) {
            scanf("%d", &x);
            adj[x].pb(i);
        }

        dfs1(1);
        dfs2(1, n);
        while(m--) {
            scanf("%d", &x);
            printf("%d\n", ans[x].second);
        }
    }

    return 0;
}
