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

  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  prev_permutation(all(p));
  for(int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  return 0;
}
