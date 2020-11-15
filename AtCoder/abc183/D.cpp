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

const int N = 3e5 + 5;

int n, w;
long long a[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> w;
  for(int i = 0; i < n; i++) {
    int s, t, p;
    cin >> s >> t >> p;
    a[s] += p;
    a[t] -= p;
  }
  for(int i = 1; i < N; i++) {
    a[i] += a[i - 1];
  }
  // for(int i = 0; i < 10; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  for(int i = 0; i < N; i++) {
    if(a[i] > w) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
