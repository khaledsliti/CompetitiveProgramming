// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];
pair<int, int> st[N << 2];

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = { arr[s], s };
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = min(st[l], st[r]);
}

pair<int, int> query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) return {n + 1, 0};
  if(s >= i && e <= j) return st[cur];
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return min(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

long long solve(int s, int e) {
  if(s > e) return 0;
  pair<int, int> q = query(0, 0, n - 1, s, e);
  int idx = q.second;
  int val = q.first;
  return 1LL * (idx - s + 1) * (e - idx + 1) * val + solve(s, idx - 1) + solve(idx + 1, e);
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  build(0, 0, n - 1);
  cout << solve(0, n- 1) << endl;
  return 0;
}
