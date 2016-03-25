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

bool solve(string &str1, string &str2) {
    int l1 = str1.size(), l2 = str2.size();
    if(l1 != l2) return 0;
    REP(i, l1) {
        char a = str1[i], b = str2[i];
        if(a == 'A' && b != 'U') return 0;
        if(a == 'T' && b != 'A') return 0;
        if(a == 'C' && b != 'G') return 0;
        if(a == 'G' && b != 'C') return 0;
    }
    return 1;
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum;
    string str1, str2;
    int n;
    cin >> casnum;
    while(casnum--) {
        cin >> n;
         cin >> str1 >> str2;
         if(solve(str1, str2)) puts("YES");
         else puts("NO");
    }
    return 0;
}

