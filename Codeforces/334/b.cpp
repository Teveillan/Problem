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


int main()
{
	//freopen("in", "r", stdin);

    int n, m;
    while(cin >> n >> m) {
         VI vec;
         REP(i, n) {
             int x;
             scanf("%d", &x);
             vec.pb(x);
         }

         int l = vec.back(), r = 2e6 + 10;
         int ret = -1;
         while(l <= r) {
            int mid = (l + r) / 2;
            int ll = 0, rr = n-1;
            int num = 0;
            while(ll <= rr) {
                if(vec[ll] + vec[rr] > mid) --rr;
                else ++ll, --rr;
                ++num;
            }
            if(num <= m) ret=mid, r = mid - 1;
            else l = mid + 1;
         }
         cout << ret << endl;
    }
    return 0;
}

