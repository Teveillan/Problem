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

int main()
{
	//freopen("in", "r", stdin);

    int n, x;
    while(cin >> n) {
        n /= 2;
        VI vec;
        REP(i, n) {
            scanf("%d", &x);
            vec.pb(x);
        }
        sort(vec.begin(), vec.end());
        int ret = 0;
        ret = min(vec[0]+vec[1], vec[n-1]+vec[n-2]);
        REP(i, n-1) ret = min(ret, vec[i] + vec[i+n+1]);
        cout << ret << endl;
    }

    return 0;
}

