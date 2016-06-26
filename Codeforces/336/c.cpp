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
const int N = 1e6 + 100;
int nxt[N];
void get_next(string s) {
    int i = 0, j = -1;  // j记录已匹配的个数
    nxt[0] = -1;
    while (i < s.size()) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            nxt[i] = j;
        } else j = nxt[j];
    }
} //get_next


bool kmp(string s1, string s2) {
    int i = 0, j = 0;
    while (i < (int)s1.size() && j < (int)s2.size()) {
        if (j == -1 || s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            j = nxt[j];
        }
    }
    if(j == 0) return 1;
    return 0;
}

int main() {
	freopen("in", "r", stdin);
    int n;
    string s1, s2;
    while(cin >> n >> s1 >> s2) {
        REP(i, s2.size()) {
            if(s2[i] == 'N') s2[i] = 'S';
            else if(s2[i] == 'S') s2[i] = 'N';
            else if(s2[i] == 'E') s2[i] = 'W';
            else if(s2[i] == 'W') s2[i] = 'E';
        }
        reverse(s2.begin(), s2.end());
        get_next(s2);
        if(kmp(s1, s2)) puts("YES");
        else puts("NO");
    }
    return 0;
}

