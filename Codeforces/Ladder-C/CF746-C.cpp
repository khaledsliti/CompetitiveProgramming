// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int s;

int solve(int pos, int dir, int p, int d) {
  if(pos == p && dir == d)
    return 0;
  if(pos == s && dir == 1 || pos == 0 && dir == -1)
    return solve(pos, -dir, p, d);
  return 1 + solve(pos + dir, dir, p, d);
}

int main()
{
  int x1, x2;
  int t1, t2;
  int p, d;
  cin >> s >> x1 >> x2;
  cin >> t1 >> t2;
  cin >> p >> d;
  int ch1 = abs(x1 - x2) * t2;
  int ch2 = (solve(p, d, x1, (x1 < x2 ? 1 : -1)) + abs(x1 - x2)) * t1;
  cout << min(ch1, ch2) << endl;
  return 0;
}
