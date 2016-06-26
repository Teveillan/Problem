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

typedef pair<pii, int> pp;
const int N = (4e5 + 100) * 6;
struct ST {
#define L pos << 1
#define R pos << 1 | 1
#define MID ((l+r)>>1)
    int node[N << 2];
    void update(int pos, int l, int r, int x, int value) {
        if(x > r || x < l) return;
        node[pos] = max(node[pos], value);
        if(l == r) return;
        update(L, l, MID, x, value), update(R, MID+1, r, x, value);
    }
    int query(int pos, int l, int r, int ll, int rr) {
        if(rr < l || ll > r) return 0;
        if(ll <= l && rr >= r) return node[pos];
        return max(query(L, l, MID, ll, rr), query(R, MID+1, r, ll, rr));
    }
    void init() {MEM(node, 0);}
}st;
VI vec;
vector<pp>q;
int v[N];
int get(int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}

VI f;
int get_len(int n) {
    f.clear();
    REP(i, n) {
        auto it = lower_bound(f.begin(), f.end(), v[i]);
        if(it == f.end()) f.pb(v[i]);
        else *it = v[i];
    }
    return f.size();
}

bool flag[N];
VI g[N];
int l[N], r[N];

void get_flag(int n) {
    MEM(flag, 0);
    int max_len = get_len(n);
    f.clear();
    REP(i, n) {
        auto it = lower_bound(f.begin(), f.end(), v[i]);
        l[i] = it - f.begin();
        g[l[i]].pb(i);
        if(it == f.end()) f.pb(v[i]);
        else *it = v[i];
    }
    f.clear();
    DWN(i, n-1, 0) {
        auto it = lower_bound(f.begin(), f.end(), v[i], greater<int>() );
        r[i] = it - f.begin();
        if(it == f.end()) f.pb(v[i]);
        else *it = v[i];
    }
    FOR(id, 0, n) {
        int num = 0;

        for(int x: g[id]) if(l[x] + r[x] + 1 == max_len) ++num;
        if(num == 1)
            for(int x: g[id]) {
                if(l[x] + r[x] + 1 == max_len) {
                    flag[x] = 1;
                    break;
                }
            }
    }
}

int ans[N];
int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
        q.clear(); vec.clear();
        REP(i, n) scanf("%d", &v[i]), vec.pb(v[i]), vec.pb(v[i]+1), vec.pb(v[i]-1);
        REP(i, m) {
            scanf("%d%d", &x, &y);
            --x;
            q.pb(pp(pii(x, y), i));
            vec.pb(y), vec.pb(y-1), vec.pb(y+1);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        sort(q.begin(), q.end());

        get_flag(n);
        int max_len = get_len(n);

        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        st.init();
        int a = 0, b = 0;
        REP(i, n) {
            if(b < q.size() && q[a].first.first == i)
                while(b < q.size() && q[a].first.first == q[b].first.first) b++;
            FOR(j, a, b-1) {
                l[q[j].second] = st.query(1, 0, vec.size(), 0, get(q[j].first.second - 1));
            }

            int tmp = st.query(1, 0, vec.size(), 0, get(v[i] - 1)) + 1;
            st.update(1, 0, vec.size(), get(v[i]), tmp);
            a = b;
        }

        st.init();
        a = b = q.size() - 1;
        DWN(i, n-1, 0) {
            if(a >= 0 && q[b].first.first == i)
                while(a >= 0 && q[a].first.first == q[b].first.first) a--;
            DWN(j, b, a+1) {
                r[q[j].second] = st.query(1, 0, vec.size(), get(q[j].first.second + 1), vec.size());
            }

            int tmp = st.query(1, 0, vec.size(), get(v[i]+1), vec.size()) + 1;
            st.update(1, 0, vec.size(), get(v[i]), tmp);
            b = a;
        }

        REP(i, m) {
            int id = q[i].second;
            ans[id] = l[id] + r[id] + 1;
            if(flag[q[i].first.first]) ans[id] = max(ans[id], max_len - 1);
            else ans[id] = max(ans[id], max_len);
        }
        REP(i, m) printf("%d\n", ans[i]);
    }
    return 0;
}

