// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  for(int i = 2 ; i <= n ; i++) {
    while(n % i == 0)
      cout << i, n/= i;
  }
  if(n > 1) cout << n;
  return 0;
}
