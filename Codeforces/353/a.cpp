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


bool solve(int a, int b, int c) {
    if(a == b) return 1;
    if(c == 0) return 0;
    if((b - a) % c == 0 && (b - a) / c > 0) return 1;
    return 0;
}

int main()
{
	//freopen("in", "r", stdin);
    LL a, b, c;
    while(cin >> a >> b >> c) {
        if(solve(a, b, c)) puts("YES");
        else puts("NO");
    }

    return 0;
}

