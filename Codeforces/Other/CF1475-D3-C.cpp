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

int a, b, k;
int A[N], B[N], cnt_a[N], cnt_b[N];

void solve() {
  cin >> a >> b >> k;
  for(int i = 0; i <= a; i++) {
    cnt_a[i] = 0;
  }
  for(int i = 0; i <= b; i++) {
    cnt_b[i] = 0;
  }
  for(int i = 0; i < k; i++) {
    cin >> A[i];
    cnt_a[A[i]]++;
  }
  for(int i = 0; i < k; i++) {
    cin >> B[i];
    cnt_b[B[i]]++;
  }
  long long ans = 0;
  for(int i = 0; i < k; i++) {
    int rem = k - cnt_a[A[i]] - cnt_b[B[i]] + 1;
    ans += rem;
  }
  cout << ans / 2 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
