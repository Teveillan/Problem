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

int dp[100100];
int main()
{
	//freopen("in", "r", stdin);
    int n, x;
    int a, b;
    while(cin >> n ) {
        int ret = 0;
        vector<pii>vec;
        REP(i, n) {
            scanf("%d%d", &a, &b);
            vec.pb(pii(a, b));
        }
        sort(vec.begin(), vec.end());
        REP(i, n) {
            int l = lower_bound(vec.begin(), vec.end(), pii(vec[i].first - vec[i].second, 0)) - vec.begin();
            int tmp = 0;
            if(l == 0) dp[i] = 1;
            else dp[i] = 1 + dp[l - 1];
            ret = max(ret, dp[i]);
        }
        cout << n - ret << endl;
    }

    return 0;
}

