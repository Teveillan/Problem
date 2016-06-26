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

const int N = 3e5 + 100;

int solve(int n, int m, int len, int num, const VI & v) {
    if(m >= n) return 0;
    map<pii, int> f[N];
    f[0][pii(num, m - num)] = 0;

    REP(i, n + 1) {
        for(auto top: f[i]) {
            int num0 = top.first.first, num1 = top.first.second;
            if(num0 && i + len <= n) {
                int j = i + len;
                pii k = pii(num0 - 1, num1);
                if(!f[j].count(k)) f[j][k] = 2e9;
                f[j][k] = min(f[j][k], top.second + v[j - 1] - v[i]);
            }
            if(num1 && i + len - 1 <= n) {
                int j = i + len - 1;
                pii k = pii(num0, num1 - 1);
                if(!f[j].count(k)) f[j][k] = 2e9;
                f[j][k] = min(f[j][k], top.second + v[j - 1] - v[i]);
            }
        }
    }
    return f[n][pii(0, 0)];
}

int main()
{
	freopen("in", "r", stdin);

    int n, m;
    while(cin >> n >> m) {
        VI vec(n);
        REP(i, n) scanf("%d", &vec[i]);
        sort(vec.begin(), vec.end());
        vec.pb(vec.back());
        int len = (n - 1) / m + 1, num = (n - 1) % m + 1;
        int ret = solve(n, m, len, num, vec);
        cout << ret << endl;
    }

    return 0;
}

