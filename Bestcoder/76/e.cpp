#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)

typedef pair<int,int> pii;

#define L pos<<1
#define R pos<<1|1
#define MID ((l+r)>>1)
#define LL L, l, MID
#define RR R, MID+1, r

const int N = 1e5 + 100;
int node[N<<2], lazy[N<<2], v[N];
vector<pair<pii, int> > vec;
void build(int pos, int l, int r, int value) {
    lazy[pos] = -1;
    if(l==r) node[pos] = (v[l] <= value);
    else {
        build(LL, value);
        build(RR, value);
        node[pos] = node[L] + node[R];
    }
}

void push_down(int pos, int l, int r) {
    if(l == r || lazy[pos] == -1) return;
    lazy[L] = lazy[R] = lazy[pos];
    node[L] = lazy[pos] * (MID - l + 1);
    node[R] = lazy[pos] * (r - MID);
    lazy[pos] = -1;
}

void push_up(int pos, int l, int r) {node[pos] = node[L] + node[R];}

int query(int pos, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return node[pos];
    push_down(pos, l, r);
    int ret = 0;
    if(ll <= MID) ret += query(LL, ll, rr);
    if(rr >  MID) ret += query(RR, ll, rr);
    push_up(pos, l, r);
    return ret;
}

void update(int pos, int l, int r, int ll, int rr, int value) {
    if(ll <= l && r <= rr) node[pos] = (r - l + 1) * value, lazy[pos] = value;
    else {
        push_down(pos, l, r);
        if(ll <= MID) update(LL, ll, rr, value);
        if(rr >  MID) update(RR, ll, rr, value);
        push_up(pos, l, r);
    }
}

int solve(int mid, int n, int m, int k) {
    build(1, 1, n, mid);

    REP(i, vec.size()) {
        int l = vec[i].first.first, r = vec[i].first.second, flag = vec[i].second;
        int num = query(1, 1, n, l, r);
        if(num == 0 || num == r - l + 1) continue;
        if(!flag) {
            update(1, 1, n, l, l+num-1, 1);
            update(1, 1, n, l+num, r, 0);
        } else {
            update(1, 1, n, r-num+1, r, 1);
            update(1, 1, n, l, r-num, 0);
        }
    }
    return query(1, 1, n, k, k) == 1;
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum, n, m, k, x, y, z;
    cin >> casnum;
    while(casnum--) {
        vec.clear();
        cin >> n >> m;
        FOR(i, 1, n) scanf("%d", &v[i]);
        REP(i, m) {
            scanf("%d%d%d", &z, &x, &y);
            vec.pb(make_pair(pii(x, y), z));
        }
        cin >> k;
        int l = 1, r = n, ans;
        while(l <= r) {
            if(solve(MID, n, m, k)) ans = MID, r = MID - 1;
            else l = MID + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

