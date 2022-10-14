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

int calc(int a, int b, int c, int x) {
  int t = b + c;
  return (x / t * b + min(b, x % t)) * a;
}

int main()
{
  int a, b, c, d, e, f, x;
  cin >> b >> a >> c >> e >> d >> f >> x;
  int first = calc(a, b, c, x);
  int second = calc(d, e, f, x);
  if(first > second) cout << "Takahashi" << endl;
  else if(first == second) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
