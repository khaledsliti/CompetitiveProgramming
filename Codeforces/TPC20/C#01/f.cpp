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
  long long A;
  cin >> A;
  if(A == 2) cout << -1 << endl;
  else cout << (A + 1) / 2 << " " << (A + 1) / 2 - 1 << endl;
  return 0;
}
