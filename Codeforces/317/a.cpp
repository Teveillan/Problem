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

const int N = 1e6;
LL f[N];

inline LL get(int l) {
    if(l < 0) return 0;
    return f[l];
}


LL solve(int x, int l) {
    LL ret = 0;
    FOR(i, 0, l) ret += get(min(l - i, x + i));
    return ret;
}


int main()
{
	//freopen("in", "r", stdin);
    LL a, b, c, l;
    while(cin >> a >> b >> c >> l) {
        MEM(f, 0);
        FOR(i, 0, 3e5) f[i] = i + 1;
        FOR(i, 1, 3e5) f[i] += f[i-1];
        LL ret= 0;
        FOR(i, 0, l) ret += f[l - i];
        ret -= solve(a-b-c, l) + solve(b-c-a, l) + solve(c-a-b, l);
        cout << ret << endl;
    }

    return 0;
}

