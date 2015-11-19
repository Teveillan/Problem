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
	//freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
         int n, m;
         cin >> n >> m;
         VI vec;
         REP(i, n) {
              int x;
              scanf("%d", &x);
              vec.pb(x);
         }
         sort(vec.begin(), vec.end());
         int num = 0;
         LL total = 0;
         REP(i, n) {
             if(total + vec[i] <= m) {
                 total += vec[i];
                 ++num;
             }
         }
         cout << num << endl;
    }
    return 0;
}

