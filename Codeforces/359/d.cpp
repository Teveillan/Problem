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

struct Node {
    int y, l, r, value;
    Node(int _y, int _l, int _r, int _value) : y(_y), l(_l), r(_r), value(_value){}
    bool operator < (const Node &other) const {
        return y < other.y;
    }
};
int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
        vector<int> xcoords;
        vector<Node>vec;
        REP(i, n) {
            scanf("%d%d", &x, &y);
            xcoords.pb(x), xcoords.pb(x+m);
            vec.pb(Node(y,  x, x+m, 1));
            vec.pb(Node(y+m,x, x+m, -1));
        }
        sort(vec.begin(), vec.end());
        sort(xcoords.begin(), xcoords.end());
        xcoords.erase(unique(xcoords.begin(), xcoords.end()), xcoords.end());

        VI cnt(xcoords.size(), 0), last(xcoords.size(), 0), list(xcoords.size(), 0);
        vector<LL>ans(n + 1);

        for(const Node &node: vec) {
            int s = distance(xcoords.begin(), lower_bound(xcoords.begin(), xcoords.end(), node.l));
            while(s < xcoords.size() && xcoords[s] < node.r) {
                int e = s + 1;
                ans[cnt[s]] += (LL)(node.y - last[s]) * (xcoords[e] - xcoords[s]);
                cnt[s] += node.value;
                last[s] = node.y;
                s = e;
            }
        }

        FOR(i, 1, n) printf("%lld ", ans[i]);
    }

    return 0;
}

