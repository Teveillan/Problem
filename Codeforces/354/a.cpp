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

int main()
{
	//freopen("in", "r", stdin);
    int n, x;
    while(cin >> n) {
        VI vec;
        FOR(i, 1, n) {
            scanf("%d", &x);
            if(x == 1 || x == n) vec.pb(i);
        }
        int ret = -1;
        REP(i, 2) {
            ret = max(ret, vec[i] - 1);
            ret = max(ret, n - vec[i]);
        }
        cout << ret << endl;
    }

    return 0;
}

