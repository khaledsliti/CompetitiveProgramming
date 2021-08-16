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

const int N = 1e4 + 5;

int n;
int arr[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if(arr[n - 1] == 0) {
    for(int i = 1; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }
  for(int i = 0; i < n - 1; i++) {
    if(arr[i] == 0 && arr[i + 1] == 1) {
      for(int j = 0; j <= i; j++) {
        cout << j + 1 << " ";
      }
      cout << n + 1 << " ";
      for(int j = i + 1; j < n; j++) {
        cout << j + 1 << " ";
      }
      cout << endl;
      return;
    }
  }
  cout << n + 1;
  for(int i = 1; i <= n; i++) {
    cout << " " << i;
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
