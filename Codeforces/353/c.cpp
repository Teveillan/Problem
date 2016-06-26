#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
    LL n;
    int x;
    while(cin >> n) {
        map<LL, int>m;
        LL tmp = 0;
        int ret = 1;

        FOR(i, 1, n) {
            scanf("%d", &x);
            tmp += x;
            ret = max(ret, ++m[tmp]);
        }
        cout << n - ret << endl;
    }

    return 0;
}

