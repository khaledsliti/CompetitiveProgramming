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

int n;

int main()
{
  cin >> n;
  if(n == 1) cout << 1 << endl;
  else if(n <= 3) cout << "NO SOLUTION" << endl;
  else if(n == 4) cout << "3 1 4 2" << endl;
  else {
    for(int i = 1; i <= n; i += 2)
      cout << i << " ";
    for(int i = 2; i <= n; i += 2)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
