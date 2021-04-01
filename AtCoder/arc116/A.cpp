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
  int T;
  cin >> T;
  while(T--) {
    long long n;
    cin >> n;
    int cnt = 0;
    while(n % 2 == 0) {
      cnt++;
      n >>= 1;
    }
    if(cnt == 0) cout << "Odd" << endl;
    else if(cnt == 1) cout << "Same" << endl;
    else cout << "Even" << endl;
  }
  return 0;
}
