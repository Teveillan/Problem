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

char str[1100];
VI flag;


int main()
{
	freopen("in", "r", stdin);

    int n;
    while(gets(str)) {
        flag.clear();
        int len = strlen(str);
        int num[2] = {0, 0};
        int id = 0;
        flag.pb(1);
        while(str[id] != '=') {
            if(str[id] == '?') ++num[flag.back()];
            else if(str[id] == '+') flag.pb(1);
            else if(str[id] == '-') flag.pb(0);

            ++id;
        }
        id += 2;

        sscanf(str + id, "%d", &n);
        if(n >= num[1] - num[0]*n && n <= num[1] * n - num[0]) {
            puts("Possible");
            VI ans(flag.size(), 1);
            int tmp = num[1] - num[0];
            for(int i = 0; tmp != n && i < flag.size(); ++i) {
                if(flag[i])
                    while(tmp < n && ans[i] < n) ++tmp, ++ans[i];
                else
                    while(tmp > n && ans[i] < n) --tmp, ++ans[i];
            }

            REP(i, flag.size()) {
                if(i != 0) putchar(flag[i]?'+':'-'), putchar(' ');
                printf("%d ", ans[i]);
            }
            printf("= %d\n", n);

        } else puts("Impossible");
    }

    return 0;
}

