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

const int N = 1e6;
bool isprime[N];
VI prime;
void init() {
    memset(isprime, 1, sizeof(isprime));
    for(int i = 2; i + i < N; ++ i) {
        if(!isprime[i]) continue;
        prime.pb(i);
        for(int j = i + i; j < N; j += i) isprime[j] = 0;
    }
}

int solve(LL n, LL m, int tmp) {
    int num1 = 0, num2 = 0;
    while(n % tmp == 0) ++num1, n /= tmp;
    while(m % tmp == 0) ++num2, m /= tmp;

    if((num1 == 0) != (num2 == 0)) return -1;
    if(num1 > num2) return -1;
    int ret = 0;
    while(num1 < num2) {
        ++ret;
        num1 <<= 1;
    }
    return ret;
}


int main()
{
    init();
	freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
         LL n, m;
         cin >> n >> m;
            int ans = 0;
            bool flag = 0;
            REP(i, prime.size()) {
                 int tmp = prime[i];
                 int ret = solve(n, m, tmp);
                 if(ret == -1) {
                      flag = 1;
                      break;
                 }
                 ans = max(ans, solve(n, m, tmp));
            }
        if(flag) puts("-1");
        else
         cout << ans << endl;
    }
    return 0;
}

