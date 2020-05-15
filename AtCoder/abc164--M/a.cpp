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
  int S, W;
  cin >> S >> W;
  if(W >= S) cout << "unsafe" << endl;
  else cout << "safe" << endl;
  return 0;
}
