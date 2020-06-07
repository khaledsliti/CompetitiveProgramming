// We only fail when we stop trying
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

const int N = 501;

int n;
int arr[N];
vector<int> a, b;

void solve() {
  cin >> n;
  a.clear(); b.clear();
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if(t) a.push_back(arr[i]);
    else b.push_back(arr[i]);
  }
  if(sz(a) && sz(b)) cout << "Yes" << endl;
  else {
    vector<int>& v = sz(a) ? a : b;
    bool sorted = true;
    for(int i = 1; i < sz(v); i++)
      sorted &= v[i] >= v[i - 1];
    if(sorted) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
