// Guess Who's Back
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

struct Node {
  int sum;
  Node *left, *right;
  Node(): sum(0), left(nullptr), right(nullptr) {}
};

typedef Node* pNode;

int n;
int L[N], R[N];
int idx[N];
pNode st;

int getSum(pNode cur) {
  return cur == nullptr ? 0 : cur->sum;
}

int getLength(int s, int e) {
  return e - s + 1;
}

void insert(pNode& cur, int s, int e, int idx) {
  if(s > idx || e < idx) return;
  if(cur == nullptr) cur = new Node();
  if(s == e) {
    cur->sum = 1;
    return;
  }
  int mid = s + (e - s) / 2;
  insert(cur->left, s, mid, idx);
  insert(cur->right, mid + 1, e, idx);
  cur->sum = getSum(cur->left) + getSum(cur->right);
}

pNode getLeft(pNode cur) {
  return cur == nullptr ? nullptr : cur->left;
}

pNode getRight(pNode cur) {
  return cur == nullptr ? nullptr : cur->right;
}

int getFirst(pNode cur, int s, int e, int i, int j) {
  if(s > j || e < i) return -1;
  if(s >= i && e <= j) {
    if (getSum(cur) == getLength(s, e)) {
      return -1;
    }
    if(s == e) return s;
    int mid = s + (e - s) / 2;
    if(getSum(getLeft(cur)) < getLength(s, mid)) {
      return getFirst(getLeft(cur), s, mid, i, j);
    }
    return getFirst(getRight(cur), mid + 1, e, i, j);
  }
  int mid = s + (e - s) / 2;
  int ans = getFirst(getLeft(cur), s, mid, i, j);
  if(ans != -1) return ans;
  return getFirst(getRight(cur), mid + 1, e, i, j);
}

void clearSt(pNode& cur) {
  if(cur == nullptr) return;
  clearSt(cur->left);
  clearSt(cur->right);
  delete cur;
  cur = nullptr;
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", L + i, R + i);
  }
  for(int i = 0; i < n; i++) {
    idx[i] = i;
  }
  sort(idx, idx + n, [&](int i, int j) {
    if(R[i] != R[j]) {
      return R[i] < R[j];
    }
    return L[i] > L[j];
  });
  st = nullptr;
  for(int i = 0; i < n; i++) {
    int pos = getFirst(st, 1, 1e9, L[idx[i]], R[idx[i]]);
    if(pos == -1) {
      printf("No\n");
      return;
    }
    insert(st, 1, 1e9, pos);
  }

  printf("Yes\n");
  clearSt(st);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
