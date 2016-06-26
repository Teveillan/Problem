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
LL n;
inline bool check(LL x) {
    if(1 <= x && x <= n) return 1;
    return 0;
}

int main()
{
	//freopen("in", "r", stdin);
    LL a, b, c, d;
    while(cin >> n >> a >> b >> c >> d) {
        LL ret = 0;
        FOR(i, 1, n) {
            LL sum = a + b +  i;
            if(!check(sum - b - d) || !check(sum - d - c) || !check(sum - a - c)) continue;
            ++ret;
        }
        cout << ret * n << endl;
    }

    return 0;
}

