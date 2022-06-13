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

const int N = 1e5 + 5;

int n;
int s[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> sol(n);
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j < n && s[i] == s[j]) {
      j++;
    }
    if(j == i + 1) {
      cout << -1 << endl;
      return;
    }
    for(int k = i; k + 1 < j; k++) {
      sol[k] = k + 1;
    }
    sol[j - 1] = i;
    i = j - 1;
  }
  for(int i = 0; i < n; i++) {
    cout << sol[i] + 1 << " ";
  }
  cout << endl;
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
