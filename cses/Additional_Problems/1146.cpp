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
  long long n;
  cin >> n;
  vector<int> b;
  while(n > 0) {
    b.push_back(n & 1);
    n >>= 1;
  }
  int prv = 0;
  long long ans = 0;
  for(int i = sz(b) - 1; i >= 0; i--) {
    if(b[i]) {
      ans += prv * (1LL << i);
      if(i > 0) {
        ans += i * (1LL << (i - 1));
      }
      prv++;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
