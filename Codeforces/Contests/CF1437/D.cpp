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
int arr[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> w;
  for(int i = 1; i < n; i++) {
    int j = i + 1;
    while(j < n && arr[j - 1] < arr[j]) {
      j++;
    }
    w.push_back(j - i);
    i = j - 1;
  }
  int par = 1, lev = 1, nxt = 0;
  for(int i = 0; i < sz(w); i++) {
    if(par == 0) {
      lev++;
      par = nxt;
      nxt = 0;
    }
    par--;
    nxt += w[i];
  }
  cout << lev << endl;
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
