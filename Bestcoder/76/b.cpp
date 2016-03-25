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
LL MOD = 1e9 + 7;

LL get(LL l, LL k) {
    return (l + l + k - 1) * k / 2;
}

LL solve(LL n, LL k) {
    LL l = 1;
    while(1) {
        LL tmp = get(l, k);
        if(tmp > n) {
            if(l == 1) return -1;
            tmp = get(l-1, k);
            --l;
            LL more = n - tmp;
            LL r = l + k - 1 - more + 1;
            LL ans = 1;
            LL sum = 0;
            FOR(i, l, r - 1) ans = (ans * i) % MOD, sum += i;
            FOR(i, r + 1, l + k) ans = (ans * i) % MOD, sum += i;
            return ans;
        }
        else if(tmp == n) {
            LL ans = 1;
            FOR(i, l, l + k - 1) ans = (ans * i) % MOD;
            return ans;
        }
        l++;
    }
}

int main()
{
	//freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
        LL n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}

