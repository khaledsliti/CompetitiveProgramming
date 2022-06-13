// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 4e5 + 5;

int n, m, q;

struct Query {
  int t;
  int l, r, x, i, j;
} Q[N];

struct node;
node* EMPTY;

struct node {
  ll val;
  node *L, *R;
  node() : val(0), L(this), R(this) {}
  node(ll val, node* l, node* r) : val(val), R(r), L(l) {}
};

int curSt;
node* root[N];

node* add(node* cur, int idx, int val, int s, int e)
{
  if(idx < s || idx > e) return cur;
  if(s == e) return new node(cur->val + val, EMPTY, EMPTY);
  int mid = s + (e - s) / 2;
  node* L = add(cur->L, idx, val, s, mid);
  node* R = add(cur->R, idx, val, mid + 1, e);
  return new node(L->val + R->val, L, R);
}

ll get(node* cur, int i, int j, int s, int e)
{
  if(s > j || e < i) return 0;
  if(s >= i && e <= j) return cur->val;
  int mid = s + (e - s) / 2;
  return get(cur->L, i, j, s, mid) + get(cur->R, i, j, mid + 1, e);
}

ll get(node* l, node* r, int i, int j) {
  return get(l, i, j, 0, m - 1) - get(r, i, j, 0, m - 1);
}

void print(node* cur, int s, int e) {
  if(s == e) {
    cout << cur->val;
    return;
  }
  int mid = s + (e - s) / 2;
  print(cur->L, s, mid);
  print(cur->R, mid + 1, e);
}

int lastRowUpdate[N];
int stState[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  EMPTY = new node();

  cin >> n >> m >> q;
  memset(lastRowUpdate, -1, sizeof(lastRowUpdate));
  root[curSt++] = EMPTY;
  for(int i = 0; i < q; i++) {
    cin >> Q[i].t;
    if(Q[i].t == 1) {  // 2 updates
      int l, r, x;
      cin >> Q[i].l >> Q[i].r >> Q[i].x;
      Q[i].l--;
      Q[i].r--;
      root[curSt++] = add(root[curSt - 1], Q[i].l, Q[i].x, 0, m - 1);
      if (Q[i].r + 1 < m) {
        root[curSt++] = add(root[curSt - 1], Q[i].r + 1, -Q[i].x, 0, m - 1);
      }
    } else if (Q[i].t == 2) {
      cin >> Q[i].i >> Q[i].x;
      Q[i].i--;
      lastRowUpdate[Q[i].i] = i;
    } else {  // 1 query
      cin >> Q[i].i >> Q[i].j;
      Q[i].i--;
      Q[i].j--;
      int last = lastRowUpdate[Q[i].i];
      int x = last == -1 ? 0 : Q[last].x;
      auto old = last == -1 ? root[0] : root[stState[last]];
      ll ans = get(root[curSt - 1], old, 0, Q[i].j);
      // D(x); D(curSt); D(last); D(ans);
      cout << x + ans << endl;
    }
    stState[i] = curSt - 1;
  } 
  // print(root[curSt - 1], 0, m - 1);
  // cout << endl;
  return 0;
}
