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

const int N = 1e5 + 100;
int v[N];

int node[N];
int f[N];
inline int lowbit(int x) {
    return x & -x;
}
void update(int x, int n, int value) {
    while(x <= n) {
        node[x] = min(node[x], value);
        x += lowbit(x);
    }
}
int query(int x) {
     int ret = 1e9;
     while(x) {
         ret = min(ret, node[x]);
         x -= lowbit(x);
     }
     return ret;
}

int solve(int n, vector<pii>&vec) {
    sort(vec.begin(), vec.end());
    FOR(i, 1, n) node[i] = 1e9;
    DWN(i, n-1, 0) {
         int x = vec[i].second;
         int tmp = query(x);
        if(tmp > 1e8) f[x] = x;
        else f[x] = tmp;
        update(x, n, x);
    }
    int ret = 0;
    int l = n+1;
    DWN(i, n, 1) {
        if(i == l - 1)
        ++ret;
        l = min(l, f[i]);
    }
    return ret;
}


int main()
{
	//freopen("in", "r", stdin);

    int n;
    while(cin >> n) {
        vector<pii>vec;
        FOR(i, 1, n) {
            scanf("%d", &v[i]);
            vec.pb(pii(v[i], i));
        }
        cout << solve(n, vec) << endl;
    }
    return 0;
}

