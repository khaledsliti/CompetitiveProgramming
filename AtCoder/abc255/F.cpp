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

const int N = 2e5 + 5;

int n;
int P[N];
int I[N];
int L[N], R[N];
int cur = 0;
bool good = true;
map<int, int> idx;

int solve(int l, int r) {
  if(!good) {
    return -1;
  }
  if(l > r) {
    return -1;
  }
  int root = idx[P[cur]];
  if(root < l || root > r) {
    good = false;
    return -1;
  }
  cur++;
  L[I[root]] = solve(l, root - 1);
  R[I[root]] = solve(root + 1, r);
  return I[root];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> P[i];
    P[i]--;
  }
  for(int i = 0; i < n; i++) {
    cin >> I[i];
    --I[i];
    idx[I[i]] = i;
  }
  if(P[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  memset(L, -1, sizeof L);
  memset(R, -1, sizeof R);
  solve(0, n - 1);
  if(!good) {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < n ;i++) {
    cout << L[i] + 1 << " " << R[i] + 1 << endl;
  }
  return 0;
}
