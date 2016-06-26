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

const int N = 1e6 + 100;
LL l[N], r[N];
char str[N];
int main()
{
	freopen("in", "r", stdin);

    LL n, a, b, t;
    while(cin >> n >> a >> b >> t) {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        scanf("%s", str + n);
        FOR(i, n, n + n - 1) {
            l[i] = l[i - 1];
            if(str[i] == 'w') l[i] += b;
            if(i != n) l[i] += a;
            l[i]++;
        }
        DWN(i, n-1, 0) {
            r[i] = r[i + 1];
            if(str[i + n] == 'w') r[i] += b;
            r[i] += a;
            r[i]++;
        }
        int ll = 0;
        int ret = 0;
        FOR(i, n, n + n - 1) {
            while(l[i] + r[ll] + min(i - n, n - ll) * a > t) ll++;
            if(ll > n) break;
            ret = max(ret, i - ll + 1);
        }
        ret = min(ret, (int)n);
        cout << ret << endl;
    }

    return 0;
}

