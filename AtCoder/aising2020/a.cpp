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

int calc(int n, int d) {
  return n / d;
}

int main()
{
  int l, r, d;
  cin >> l >> r >> d;
  cout << calc(r, d) - calc(l - 1, d) << endl;
  return 0;
}
