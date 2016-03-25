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
typedef pair<int,int> pii;

typedef unsigned long long LL;

LL solve(LL n, LL m) {
    LL ret = 0;
    ret += n * n * m;
    ret += n * (n-1) * (2 * n - 1) / 6;
    ret -= n * (n - 1) / 2 * (n + m);
    return ret;
}

LL get(LL n, LL sum, LL &r) {
    LL l = 1;
    while(l <= r) {
        LL mid = l + (r - l) / 2;
        LL tmp = solve(n, mid);
        if(tmp == sum) return r=mid;
        else if(tmp < sum) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main()
{
	//freopen("in", "r", stdin);
    LL sum;
    while(cin >> sum) {
        vector<pair<LL, LL> >ans;
        LL r = 1e10;
        int num = 0;
        for(LL i = 1; ; ++i) {
            get(i, sum, r);
            cout << i << ' ' << r << ' ' << solve(i, r) << endl;
            if(r < i) {
                num = ans.size();
                break;
            }
            if(solve(i, r) == sum) {
               ans.pb(make_pair(i, r));
               if(i == r) {
                   num = ans.size() - 1;
                   break;
               }
            }
        }
        DWN(i, num-1, 0) {
             ans.pb(make_pair(ans[i].second, ans[i].first));
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            printf("%lld %lld\n", ans[i].first, ans[i].second);
        }


    }

    return 0;
}

