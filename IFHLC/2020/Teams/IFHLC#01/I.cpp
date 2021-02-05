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

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for(int i = 1; i < n; i++) {
    if(v[i - 1] > v[i]) {
      for(int j = i; j < n; j++) {
        if(v[j - 1] < v[j]) {
          int a = i - 1, b = j;
          while(v[a - 1] == v[a]) --a;
          reverse(v.begin() + a, v.begin() + b);
          bool yes = true;
          for(int k = 1; k < n; k++)
            yes &= v[k - 1] <= v[k];
          if(yes) cout << a + 1 << " " << b << endl;

        }
      }
      cout << i + 1 << " " << n << endl;
      return 0;
    }
  }
  cout << "1 1\n";
  return 0;
}
