#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> pii;
const int N = 1e5 + 10;
pii ans[N];

bool solve(int n, vector<pii> &in, vector<pii> &out) {
    int l = 1, r = n;
    int id1 = in.size() - 1, id2 = out.size() - 1;
    set<pii>s;
    REP(i, n-1) {
        if(i&1) {
            ans[ in[id1].second ].first = l;
            ans[ in[id1].second ].second = l + 1;
            s.insert(pii(l, l+1));
            for(int j = l + 2; id2 >= 0 && out[id2].first >= in[id1].first && j <= r; --id2, ++j) {
                if(s.find(pii(l, j)) != s.end()) continue;
                s.insert(pii(l, j));
                ans[ out[id2].second ].first = l;
                ans[ out[id2].second ].second = j;
            }
            l++;
        } else {
            ans[ in[id1].second ].first = r;
            ans[ in[id1].second ].second = r - 1;
            s.insert(pii(r-1, r));
            for(int j = r - 2; id2 >= 0 && out[id2].first >= in[id1].first && j >= l; --id2, --j) {
                if(s.find(pii(j, r)) != s.end()) continue;
                s.insert(pii(j, r));
                ans[ out[id2].second ].first = r;
                ans[ out[id2].second ].second = j;
            }
            r--;
        }
        --id1;
    }
    if(id2 >= 0) return 0;
    return 1;
}

int main()
{
	freopen("in", "r", stdin);
    int n, m;
    while(cin >> n >> m) {
        vector<pii> in, out;
        REP(i, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(y == 1) in.pb(pii(x, i));
            else out.pb(pii(x, i));
        }
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        if(!solve(n, in, out)) cout << - 1 << endl;
        else {
             REP(i, m) printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}

