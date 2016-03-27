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

const int N = 4e5 + 100;
int ans[N];
int node[N];
vector<pii> head[N];

inline int lowbit(int x) {return x&-x;}
void update(int x, int nn) {
    while(x <= nn) {
        ++node[x];
        x += lowbit(x);
    }
}

int query(int x) {
    if(x <= 0) return 0;
    int ret = 0;
    while(x) {
        ret += node[x];
        x -= lowbit(x);
    }
    return ret;
}


int main()
{
	freopen("ind", "r", stdin);

    int n, x, y;
    while(cin >> n) {
        memset(node, 0, sizeof(node));
        vector<pii>vec;
        VI v;
        map<int, int> s;
        REP(i, n) {
            scanf("%d%d", &x, &y);
            vec.pb(pii(x, y));
            v.pb(x), v.pb(y);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int num = v.size();

        REP(i, num) s[ v[i] ] = i;
        REP(i, n) {
            vec[i].first = s[ vec[i].first ] + 1;
            vec[i].second = s[ vec[i].second ] + 1;
        }

        REP(i, num) head[i].clear();
        REP(i, n) head[ vec[i].second ].pb(pii(vec[i].first, i));

        FOR(i, 1, num) {
            for(int j = head[i].size() - 1; j >= 0; --j) {
                int l = head[i][j].first, id = head[i][j].second;
                ans[id] = query(i) - query(l-1);
                update(l, num);
            }
        }
        REP(i, n) printf("%d\n", ans[i]);
    }

    return 0;
}

