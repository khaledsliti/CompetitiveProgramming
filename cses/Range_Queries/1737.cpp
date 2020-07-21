// We only fail when we stop trying
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

const int N = 2e5 + 5;

struct Node;
Node* Empty;

struct Node {
  ll sum;
  Node* left, *right;
  Node(): sum(0LL), left(this), right(this) {}
  Node(ll s, Node* left, Node* right): sum(s), left(left), right(right) {}
};

int n, q, arrays;
Node* root[N];

Node* update(Node* cur, int s, int e, int i, int val) {
  if(s > i || e < i) return cur;
  if(s == e) return new Node(val, Empty, Empty);
  int mid = s + (e - s) / 2;
  auto L = update(cur->left, s, mid, i, val);
  auto R = update(cur->right, mid + 1, e, i, val);
  return new Node(L->sum + R->sum, L, R);
}

ll get(Node* cur, int s, int e, int i, int j) {
  if(s > j || e < i) return 0LL;
  if(s >= i && e <= j) return cur->sum;
  int mid = s + (e - s) / 2;
  return get(cur->left, s, mid, i, j) + get(cur->right, mid + 1, e, i, j);
}

int main()
{
  Empty = new Node();
  root[0] = Empty;
  arrays = 1;
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    root[0] = update(root[0], 0, N - 1, i, t);
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int k, a, x;
      scanf("%d%d%d", &k, &a, &x);
      root[k - 1] = update(root[k - 1], 0, N - 1, --a, x);
    } else if(t == 2) {
      int k, a, b;
      scanf("%d%d%d", &k, &a, &b);
      printf("%lld\n", get(root[--k], 0, N - 1, --a, --b));
    } else if(t == 3) {
      int k;
      scanf("%d", &k);
      root[arrays++] = root[--k];
    }
  }
  return 0;
}
