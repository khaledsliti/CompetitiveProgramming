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
  string a;
  cin >> a;
  cout << (a[2] == a[3] && a[4] == a[5] ? "Yes" : "No") << endl;
  return 0;
}
