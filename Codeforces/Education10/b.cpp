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


int v[1010], ans[1010];
int main()
{
	freopen("inb", "r", stdin);
    int n;
    while(cin >> n) {
        VI vec;
        REP(i, n) {
            scanf("%d", &v[i]);
        }
        sort(v, v+n);

        int l = 0, r = n - 1;
        for(int i = 0; i < n; i += 2) {
            ans[i] = v[l++];
        }
        for(int i = 1; i < n; i += 2) {
             ans[i] = v[l++];
        }

             REP(i, n) printf("%d ", ans[i]);
             puts("");

    }

    return 0;
}

