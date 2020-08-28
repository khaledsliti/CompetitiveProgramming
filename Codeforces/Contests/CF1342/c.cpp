// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 201;

int a, b;
int r[N * N];

long long calc(long long right) {
  int p = a * b;
  long long res = right / p * r[p - 1] + r[right % p];
  return res;
}

void solve() {
  int q;
  cin >> a >> b >> q;
  for(int i = 0 ; i < a * b ; i++)
    if((i % a) % b != (i % b) % a) r[i] = 1;
    else r[i] = 0;
  for(int i = 1 ; i < a * b ; i++)
    r[i] += r[i - 1];
  while(q--) {
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
