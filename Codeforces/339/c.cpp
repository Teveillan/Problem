#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
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

const int N = 1e5 + 100;
int v[30];

int f[30];

string get_odd(int num, int n, int len) {
    REP(i, n) f[i] = v[i] / num;
    int a = 0, b = 0;
    REP(i, n) if(f[i] % 2) ++a, b = i;
    if(a > 1) return "";
    else if(a == 1) --f[b];
    len /= num;
    int l = 0, r = len-1;
    string ret(len, 'a');
    REP(i, n) {
        while(f[i]) {
            f[i] -= 2;
            ret[l++] = i + 'a';
            ret[r--] = i + 'a';
        }
    }
    if(a) ret[l] = b + 'a';
    return ret;
}

string get_even(int num, int n, int len) {
    REP(i, n) f[i] = v[i] / num;
    len /= num;
    int l = 0;
    string ret(len, 'a');
    REP(i, n) {
        while(f[i]--) ret[l++] = 'a' + i;
    }
    return ret;
}

pair<int, string> solve(int n, int g, int len) {
    if(n == 1) return mp(v[0], string(v[0], 'a'));
    DWN(i, g, 1) {
        if(g % i) continue;
        if(i & 1) {
            string tmp = get_odd(i, n, len);
            if(!tmp.size()) continue;
            string ret;
            REP(j, i) ret += tmp;
            return mp(i, ret);
        } else {
            string tmp0 = get_even(i, n, len);
            string tmp1 = tmp0;
            reverse(tmp1.begin(), tmp1.end());
            string ret;
            REP(j, i) if(j & 1) ret += tmp1;
            else ret += tmp0;
            return mp(i, ret);
        }
    }

    string tmp = "";
    REP(i, n) tmp += string(v[i], 'a' + i);
    return mp(0, tmp);
}


int main()
{
	freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        int g = -1, len = 0;
        REP(i, n) {
            scanf("%d", &v[i]);
            len += v[i];
            if(g == -1) g = v[i];
            else g = __gcd(g, v[i]);
        }
        pair<int, string> ret = solve(n, g, len);
        cout << ret.first << endl;
        cout << ret.second << endl;
    }

    return 0;
}

