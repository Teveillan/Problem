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

const int N = 1e5 + 100;
LL sum[N];
int v[N];

bool solve(LL mid, LL last, int n, vector<pii> &vec) {
    int id = upper_bound(vec.begin(), vec.begin() + n, pii(mid, -1)) - vec.begin();
    last -= mid * id - sum[id];

    return last >= 0;
}

int main()
{
	freopen("in", "r", stdin);

    LL n, A, cf, cm, m;
    int x;
    while(cin >> n >> A >> cf >> cm >> m) {
        MEM(sum, 0);
        vector<pii>vec;
        REP(i, n) {
            scanf("%d", &x);
            vec.pb(pii(x, i));
        }
        sort(vec.begin(), vec.end());

        FOR(i, 1, n) {
            sum[i] += sum[i-1];
            sum[i] += vec[i-1].first;
        }

        LL ans=0;
        int minist = 0, num = 0;
        FOR(i, 0, n) {
            LL last = (i == 0? m : m - (i*A - (sum[n] - sum[n-i])));
            if(last < 0) continue;
            LL l = 0, r = 1e9, ll = 0;
            while(l <= r) {
                LL mid = (l + r) / 2;
                if(solve(mid, last, n-i, vec)) l = mid + 1, ll = mid;
                else r = mid - 1;
            }
            ll = min(ll, A);
            LL tmp = i * cf + ll * cm;
            if(tmp > ans) {
                ans = tmp;
                minist = ll;
                num = i;
            }
        }

        for(pii x: vec) v[x.second] = x.first;
        FOR(i, n-num, n-1) v[vec[i].second] = A;
        REP(i, n) v[i] = max(v[i], minist);
        cout << ans << endl;
        REP(i, n) printf("%d ", v[i]);
        puts("");
    }

    return 0;
}

