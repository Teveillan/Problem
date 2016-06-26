#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
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

typedef pair<LL, LL> pp;
map<LL, pp>m;
map<LL, LL>s;

void init() {
    for(LL i = 2; i * i * i <= 1e15; ++i) {
        m[i * i * i- 1] = pp(-1, -1);
        s[i * i * i] = i;
    }
}

pp solve(LL n) {
    if(n < 0) return pp(0, 0);
    if(n < 8) return pp(n, n);
    if(m.count(n) && m[n] != pp(-1, -1)) return pp(m[n]);

    auto it = s.upper_bound(n);
    it--;
    LL x = it -> second;
    x *= x * x;
    pp tmp = solve(n % x);
    tmp.first += n / x, tmp.second += n / x * x;
    pp ret = tmp;
    if(n / x) {
        tmp = solve(x - 1);
        tmp.first += n / x - 1;
        tmp.second += (n / x - 1) * x;
        ret = max(ret, tmp);
    }

    if(m.count(n)) m[n] = ret;
    return ret;
}

int main()
{
	//freopen("in", "r", stdin);

    init();

    LL n;
    while(cin >> n) {
        pp ret = solve(n);
        cout << ret.first << ' ' << ret.second << endl;
    }

    return 0;
}

