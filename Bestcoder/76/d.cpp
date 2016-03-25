#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)

int dfs(int pos, int l, int cur_value) {
    if(pos <= cur_value) return 1 << __builtin_popcount(pos);

    int ret = 0;
    if((1<<l) & pos) {
        if((1<<l) <= cur_value) ret += dfs(pos^(1<<l), l-1, cur_value - (1<<l));
        ret += dfs(pos^(1<<l), l-1, cur_value);
    } else {
        ret += dfs(pos, l-1, cur_value);
    }
    return ret;
}

int get(int pos, int max_value) { //数位DP,求在pos中选部分二进制为1的位组成a,且a<=max_value的方案数
    if(max_value < 0) return 0;
    int len = 0;
    while((1<<len) <= max_value) len++;

    pos = pos & ((1<<len) - 1);//把高位舍掉,反正也没用
    int ret = dfs(pos, len-1, max_value);
    return ret;
}

int main()
{
    int casnum, n, m;
    cin >> casnum;
    while(casnum--) {
        cin >> n >> m;
        int len = 0;
        while((1<<len) <= n || (1<<len) <= m) len++;
        int s = 1;
        REP(i, len) s *= 3;
        long long ans = 0;
        REP(i, s) { // 三进制枚举状态值
            int tmp = i, x = 0, y = 0; // x为and值, y为or值
            REP(j, len) {
                if(tmp % 3 == 1) y |= (1<<j);
                else if(tmp % 3 == 2) x |= (1<<j), y |= (1<<j);
                tmp /= 3;
            }
            if(y == 0) continue;
            if(x > n || x > m) continue;

            int z = x ^ y;
            int value = get(z, n-x) - get(z, z-m+x-1);
            if(x == 0) { //这里要注意.当x==0时, a 和 b 都不能为0
                if(z <= n) --value;
                if(z <= m) --value;
            }
            ans += __gcd(x, y) * max(value, 0);
        }
        cout << ans << endl;
    }

    return 0;
}

