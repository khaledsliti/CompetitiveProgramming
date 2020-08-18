#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
  int t;
  cin >> t;
  while(t--){
    long long A, B;
    cin >> A >> B;
    long long b = 9;
    long long ans = 0;
    while(b <= B){
      ans += A;
      b = b * 10 + 9;
    }
    cout << ans << endl;
  }
  return 0;
}
