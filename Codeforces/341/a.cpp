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
    int n;
    LL x;
    cin >> n;
    LL sum = 0, tmp = 1e10;
    while(n--) {
        scanf("%lld", &x);
        sum += x;
        if(x & 1) tmp = min(tmp, x);
    }
    if(sum & 1) sum -= tmp;
    cout<< sum << endl;
    return 0;
}

