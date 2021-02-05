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
#define EPS 1e-9
#define PI acos(-1.0)

int db_cmp (long double a, long double b) {
  if (fabs(a - b) < EPS)
    return 0;
  return (a > b) * 2 - 1;
}

int main()
{
  long double A, N;
  cin >> A >> N;
  if(db_cmp(N, 2 * PI * sqrt(A / PI)) >= 0) cout << "Diablo is happy!" << endl;
  else cout << "Need more materials!" << endl;
  return 0;
}
