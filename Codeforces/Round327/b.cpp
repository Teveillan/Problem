#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
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
	freopen("in", "r", stdin);

    int len, m;
    while(cin >> len >> m) {
         string str;
         cin >> str;

        map<int, int>s1, s2;
        for(int i = 'a'; i <= 'z'; ++i) s1[i] = i, s2[i] = i;

         while(m--) {
             char x[10], y[10];
             scanf("%s%s",x,y);
             int a = x[0], b = y[0];
             int c = s2[a], d = s2[b];

             swap(s1[c], s1[d]);
             swap(s2[a], s2[b]);
         }

        REP(i, len) printf("%c", s1[ str[i] ]);
         puts("");
    }
    return 0;
}

