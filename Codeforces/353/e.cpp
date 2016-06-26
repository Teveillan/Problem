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

const int N = 1e5 + 100;
int v[N];
struct ST{
#define L pos << 1
#define R pos << 1 | 1
#define MID ((l+r)>>1)
    int node[N<<2];
    void init() {memset(node, 0, sizeof(node));}
    void update(int pos, int l, int r, int id, int value) {
        if(l == r) node[pos] = value;
        else {
            if(id <= MID) update(L, l, MID, id, value);
            else update(R, MID+1, r, id, value);
            node[pos] = (v[node[L]] > v[node[R]] ? node[L] : node[R]);
        }
    }
    int query(int pos, int l, int r, int ll, int rr) {
        if(rr < l || ll > r) return 0;
        if(ll <= l &&  r <= rr) return node[pos];
        else {
            int ret_l = query(L, l, MID, ll, rr);
            int ret_r = query(R, MID+1, r, ll, rr);
            return (v[ret_l] > v[ret_r] ? ret_l : ret_r);
        }
    }
}st;

LL ans[N];
int main()
{
	//freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        st.init();
        FOR(i, 1, n-1) scanf("%d", &v[i]);
        DWN(i, n-1, 1) {
            if(v[i] == n) ans[i] = n - i;
            else {
                int id = st.query(1, 1, n, i + 1, v[i]);
                ans[i] = v[i] - i;
                ans[i] += ans[id] - (v[i] - id) + (n - v[i]);
            }
            st.update(1, 1, n, i, i);
        }
        LL ret = 0;
        FOR(i, 1, n-1) ret += ans[i];
        cout << ret << endl;
    }

    return 0;
}

