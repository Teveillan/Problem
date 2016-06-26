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

int get(int n) {
    if(n == 0) return 1;
    int ret = 0;
    while(n) {
        n /= 7;
        ++ret;
    }
    return ret;
}

int solve(int mask, int n) {
    VI vec;
    REP(i, 7) if((1<<i) & mask) vec.pb(i);
    int ret = 0;
    do {
        int tmp = 0;
        for(int x: vec) {
            tmp = tmp * 7 + x;
        }
        if(tmp <= n) ++ret;
    } while(next_permutation(vec.begin(), vec.end()));
    return ret;
}


int main()
{
	//freopen("in", "r", stdin);
    int n, m;
    while(cin >> n >> m) {
        --n, --m;
        int len1 = get(n), len2 = get(m);
        int ret = 0;
        int mask = (1 << 7) - 1;
        REP(mask1, 1 << 7) {
            if(__builtin_popcount(mask1) == len1) {
                int a = solve(mask1, n);
                int tmp = mask ^ mask1;
                if(a)
                for(int mask2 = tmp; mask2; mask2 = (mask2 - 1) & tmp) {
                    if(__builtin_popcount(mask2) == len2) {
                        int b = solve(mask2, m);
                        ret += a * b;
                    }
                }
            }
        }
        cout << ret << endl;
    }

    return 0;
}

