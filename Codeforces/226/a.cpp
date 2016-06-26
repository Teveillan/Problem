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

const int N = 1e6 + 100;
int v[N];

int main()
{
	freopen("in", "r", stdin);

    int n, x;
    while(cin >> n) {
        MEM(v, 0);
        REP(i, n) {
            scanf("%d", &x);
            ++v[x];
        }
        LL tmp = 0, ans = 0;
        FOR(i, 0, 1e6) {
            tmp += v[i];
            if(tmp & 1) ++ans;
            tmp /= 2;
        }

        if(tmp) ans += __builtin_popcount(tmp);
        cout << ans << endl;
    }
    return 0;
}

