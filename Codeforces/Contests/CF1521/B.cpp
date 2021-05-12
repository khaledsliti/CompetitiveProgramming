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

int n;
int arr[N];

void solve() {
  cin >> n;
  int pos = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(arr[pos] > arr[i])
      pos = i;
  }
  vector<array<int, 4>> sol;
  for(int i = 0; i < n; i++) {
    if(i == pos) continue;
    if((pos - i) % 2 == 0) {
      sol.push_back({i + 1, pos + 1, arr[pos], arr[pos]});
    } else {
      sol.push_back({i + 1, pos + 1, arr[pos] + 1, arr[pos]});
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    for(int j = 0; j < 4; j++)
      cout << sol[i][j] << " ";
    cout << endl;
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

/*
3 4 3 11 15


*/