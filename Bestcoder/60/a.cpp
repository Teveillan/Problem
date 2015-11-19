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
         int n;
         LL po = 0, ne = 0;

         LL tmp = 0;
         int flag[3] = {0};
         cin >> n;
            LL x;
         REP(i, n) {
            scanf("%lld", &x);
            if(x == 0) ++flag[0];
            else if(x > 0) {
                if(po == 0) po = x;
                else po *= x;
                ++flag[1];
            } else {
                if(tmp == 0) tmp = x;
                else {
                    tmp *= x;
                    ne *= x;
                    tmp = 0;
                    ++flag[2];
                }
            }


        }
        if(po > 0) cout << po * max(1ll, ne) << endl;
        else if(ne > 0) cout << ne << endl;
        else if(flag[0]) cout << "0" << endl;
        else cout << x << endl;
    }
    return 0;
}

