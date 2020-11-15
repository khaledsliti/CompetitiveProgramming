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
  double Sx, Sy, Gx, Gy;
  cin >> Sx >> Sy >> Gx >> Gy;
  double x = (Sy * Gx + Gy * Sx) / (Gy + Sy);
  cout << fixed << setprecision(10) << x << endl;
  return 0;
}
