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

int mex(int s, int c) {
    int t = sqrt((double)s);
    while(t + t*t >= s) --t;
    if(c > t) return s - c;
    return mex(t, c);
}

int main()
{
	//freopen("in", "r", stdin);
    int n, s, c, casid = 0;
    while(cin >> n && n) {
        int ans = 0;
        while(n--) {
            scanf("%d%d", &s, &c);
            if(s == 0 || c == 0 || s == c) continue;
            ans ^= mex(s, c);
        }
        printf("Case %d:\n", ++casid);
        puts(ans?"Yes":"No");
    }
    return 0;
}

