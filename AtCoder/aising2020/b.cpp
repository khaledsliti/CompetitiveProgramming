// We only fail when we stop trying
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
  int n;
  cin >> n;
  int a = 0;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if((i & 1) && (x & 1))
      a++;
  }
  cout << a << endl;
  return 0;
}
