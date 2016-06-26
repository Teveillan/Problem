#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
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

const int MOD = 1e9 + 7;
long long qi(long long n, long long p = MOD) {
	long long ret = 1;
	int exponent = p - 2;
	for (int i = exponent; i; i >>= 1, n = n * n % p) {
		if (i & 1) {
			ret = ret * n % p;
		}
	}
	return ret;
}
const int N = 1e5 + 2;
char s[N];
LL a[N], ra[N], b[N], rb[N];
int inv[N];
void get_inverse(int n, int p) {
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] =  (long long)(p - p / i) * inv[p % i] % p;
	}
}
void init() {
    a[0] = b[0] = 1;
    ra[0] = rb[0] = 1;
    FOR(i, 1, N-1) {
        a[i] = a[i-1] * 25 % MOD;
        ra[i] = qi(a[i]);

        b[i] = b[i-1] * 26 % MOD;
        rb[i] = qi(b[i]);
    }
	get_inverse(1e5, MOD);
}

void solve(vector<int> &vec, int l) {
    vec[l] = 1;
    FOR(i, l+1, N-1) {
        vec[i] = (LL)vec[i-1] * (i-1) % MOD * inv[(i-1) - (l-1)] % MOD;
    }
    FOR(i, l, N-1) {
        vec[i] = (LL)vec[i] * a[i] % MOD * rb[i] % MOD;
        vec[i] = (vec[i-1] + vec[i]) % MOD;
    }
}

int main()
{
	freopen("in", "r", stdin);
    init();
    int q, n, l, o;
    while(cin >> q >> s) {
        map<int, VI >f;
        l = strlen(s);
        while(q--) {
            scanf("%d", &o);
            if(o == 1) {
                scanf("%s", s);
                l = strlen(s);
            } else {
                if(f.count(l) == 0) {
                    f[l] = VI(N);
                    solve(f[l], l);
                }
                scanf("%d", &n);

                int ret = b[n] * ra[l] % MOD * ((f[l][n] - f[l][l-1] + MOD) % MOD) % MOD;
                printf("%d\n", ret);
            }
        }
    }

    return 0;
}
