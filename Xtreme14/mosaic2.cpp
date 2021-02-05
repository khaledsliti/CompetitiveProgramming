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

long long W, H, A, B, M, C;

int main()
{
  cin >> W >> H >> A >> B >> M >> C;
  long long tot = ((W + A - 1) / A) * ((H + B - 1) / B);
  tot = (tot + 9) / 10;
  long long cost = tot * M;
  if(W % A != 0) cost += H * C;
  if(H % B != 0) cost += W * C;
  cout << cost << endl;
  return 0;
}
