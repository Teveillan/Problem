#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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

int main()
{
	//freopen("in", "r", stdin);

    int n, x, y;
    while(cin >> n) {
        map<int, int>a, b;
        map<pii, int>f;

        REP(i, n) {
            scanf("%d%d", &x, &y);
            a[x]++;
            b[y]++;
            f[pii(x, y)]++;
        }

        LL ret = 0;
        for(auto it: a) {
            LL tmp = it.second;
            ret += tmp * (tmp - 1) / 2;
        }

        for(auto it: b) {
            LL tmp = it. second;
            ret += tmp * (tmp - 1) / 2;
        }

        for(auto it: f) {
            LL tmp = it.second;
            ret -= tmp * (tmp - 1) / 2;
        }
        cout << ret << endl;
    }

    return 0;
}

