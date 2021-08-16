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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    sort(all(v));
    sum -= v[n - 1];
    cout << fixed << setprecision(10) << (sum * 1.0 / (n - 1)) + v[n - 1] << endl;
  }
  return 0;
}
