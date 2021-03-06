// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


struct node {
  int tot;
  node *l, *r;
  node(int tot): tot(tot), l(nullptr), r(nullptr) {}
};

typedef node* pnode;

int n, k, A, B;
pnode tr;

void insert(pnode& tr, int s, int e, int idx) {
  if(!tr) tr = new node(0);
  if(s > idx || e < idx) return;
  if(s == e) {
    tr->tot++;
    return;
  }
  int len = e - s + 1;
  int mid = s + (len >> 1) - 1;
  insert(tr->l, s, mid, idx);
  insert(tr->r, mid + 1, e, idx);
  tr->tot = tr->l->tot + tr->r->tot;
}

long long solve(pnode tr, int s, int e) {
  if(!tr || !tr->tot) return A;
  int len = e - s + 1;
  int mid = s + (len >> 1) - 1;
  long long ans = 1LL * B * len * tr->tot;
  if(s != e)
    ans = min(ans, solve(tr->l, s, mid) + solve(tr->r, mid + 1, e));
  return ans;
}

int main()
{
  cin >> n >> k >> A >> B;
  while(k--) {
    int a; cin >> a;
    insert(tr, 1, 1 << n, a);
  }
  cout << solve(tr, 1, 1 << n) << endl;
  return 0;
}
