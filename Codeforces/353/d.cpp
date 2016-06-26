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
const int N = 1e5 + 100;

struct Node{
    Node *l, *r;
    int h, v;

    void get_h() {h = max(l->h, r->h) + 1;}

    Node(int v, int h = 1) : v(v), h(h) {
        l = r= NULL;
    }
    Node(){ l = r = NULL; }

    void turn_l() {
        Node *tmp = r;
        r = tmp->l;
        tmp -> l = tmp;
        swap(*tmp, *this);
        get_h(), tmp->get_h();
    }

    void turn_r() {
        Node *tmp = l;
        l = tmp -> r;
        tmp -> r = tmp;
        swap(*tmp, *this);
        get_h(), tmp->get_h();
    }

    int dfs(int value, int pre) {
        if(value == v) return pre;
        int ret = 0;
        if(value > v) {
            if(!r) r = new Node(value);
            ret = r->dfs(value, v);
        }
        if(value < v) {
            if(!l) l = new Node(value);
            ret = l->dfs(value, v);
        }
        int lh = (l == NULL? 0:l->h);
        int rh = (r == NULL? 0:r->h);
        if(abs(lh - rh) > 1) {
            if(lh > rh) turn_r();
            else turn_l();
        }
        return ret;
    }
};

int main()
{
	freopen("in", "r", stdin);
    int n, x;
    while(cin >> n) {
        Node root;
        FOR(i, 1, n) {
            scanf("%d", &x);
            if(i == 1) root = Node(x);
            else printf("%d ", root.dfs(x, -1));
        }
        puts("");
    }

    return 0;
}

