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

int solve(int n) {
    if(n == 1) return 1;
    --n;
    return (n >= 2 && n % 2 == 0);
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
         int n;
         scanf("%d", &n);
         cout << solve(n) << endl;
    }
    return 0;
}

