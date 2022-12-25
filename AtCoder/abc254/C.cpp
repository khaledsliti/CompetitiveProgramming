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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < k; i++) {
    vector<int> tmp;
    for(int j = i; j < n; j += k) {
      tmp.push_back(a[j]);
    }
    sort(all(tmp));
    reverse(all(tmp));
    for(int j = i; j < n; j += k) {
      a[j] = tmp.back();
      tmp.pop_back();
    }
  }
  for(int i = 1; i < n; i++) {
    if(a[i - 1] > a[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
