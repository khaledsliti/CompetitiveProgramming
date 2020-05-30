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

int main()
{
  int H1, M1, H2, M2, P;
  cin >> H1 >> M1 >> H2 >> M2 >> P;
  int a = H1 * 60 + M1;
  int b = H2 * 60 + M2;
  cout << b - a - P << endl;
  return 0;
}
