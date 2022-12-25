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
int arr[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int a = 1;
  for(int i = 2; i < n; i++) {
    if(arr[a] > arr[i]) {
      a = i;
    }
  }
  arr[0]--;
  int b = 0;
  for(int i = 0; i < n; i++) {
    if(i != a && arr[b] > arr[i]) {
      b = i;
    }
  }
  ll an = 2LL * arr[a] + 1;
  ll bn = 2 + 2LL * arr[b];
  if(an <= bn) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
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
