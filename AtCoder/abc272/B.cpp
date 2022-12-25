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

const int N = 105;

int n;
int ok[N][N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> n >> m;
  while(m--) {
    int k; cin >> k;
    vector<int> a(k);
    for(int i = 0; i < sz(a); i++) {
      cin >> a[i];
      for(int j = 0; j < i; j++) {
        ok[a[j] - 1][a[i] - 1] = 1;
        ok[a[i] - 1][a[j] - 1] = 1;
      }
    }
  }
  bool good = true;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < i; j++) {
      if(!ok[i][j]) {
        good = false;
      }
    }
  }
  cout << (good ? "Yes" : "No") << endl;
  return 0;
}
