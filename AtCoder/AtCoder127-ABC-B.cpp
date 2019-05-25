#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
  int r, d, x;
  cin >> r >> d >> x;
  long long ans = x;
  for(int i = 1 ; i <= 10 ; i++){
    ans = r * ans - d;
    cout << ans << endl;
  }
  return 0;
}