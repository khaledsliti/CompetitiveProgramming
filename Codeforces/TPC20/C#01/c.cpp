// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const long long L = -1e9, R = 1e15;

struct node {
  int val;
  node *l, *r;
  node(): val(0), l(NULL), r(NULL) {}
  node(int val): val(val), l(NULL), r(NULL) {}
};

typedef node* pnode;

int n;
int x[N], v[N], e[N];
long long pv[N], pe[N];
node* st;

void insert(pnode& cur, long long s, long long e, long long idx, int val) {
  if(!cur) cur = new node(n + 2);
  if(s > idx || e < idx) return;
  if(s == e){
    if(cur->val == n + 2)
      cur = new node(val);
    return;
  }
  long long mid = s + (e - s) / 2;
  insert(cur->l, s, mid, idx, val);
  insert(cur->r, mid + 1, e, idx, val);
  cur->val = min(cur->l->val, cur->r->val);
}

int get(pnode& cur, long long s, long long e, long long i, long long j) {
  if(!cur || s > j || e < i) return n + 2;
  if(s >= i && e <= j) return cur->val;
  long long mid = s + (e - s) / 2;
  return min(get(cur->l, s, mid, i, j), get(cur->r, mid + 1, e, i, j));
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d%d%d", x + i, v + i, &e[i]);
  }
  for(int i = 0 ; i < n ; i++) {
    pv[i] = v[i];
    pe[i] = e[i];
    if(i) pv[i] += pv[i - 1], pe[i] += pe[i - 1];
  }
  insert(st, L, R, -x[0], 0);
  long long best = 0;
  for(int i = 0 ; i < n ; i++) {
    int idx = get(st, L, R, L, pe[i] - x[i]);
    idx--;
    long long cur = pv[i] - (idx >= 0 ? pv[idx] : 0);
    best = max(best, cur);
    if(i + 1 < n)
      insert(st, L, R, pe[i] - x[i + 1], i + 1);
  }
  cout << best << endl;
  return 0;
}
