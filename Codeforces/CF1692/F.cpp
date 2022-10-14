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
int arr[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] %= 10;
  }
  map<int, int> l, r;
  for(int i = 0; i < n; i++) {
    l[arr[i]]++;
  }
  for(int i = n - 1; i >= 0; i--) {
    l[arr[i]]--;
    for(int a = 0; a < 10; a++) {
      if(!l[a]) continue;
      for(int b = 0; b < 10; b++) {
        if(!r[b]) continue;
        if((a + b + arr[i]) % 10 == 3) {
          cout << "YES" << endl;
          return;
        }
      }
    }
    r[arr[i]]++;
  }
  cout << "NO" << endl;
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
