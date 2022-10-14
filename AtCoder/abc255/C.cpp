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

ll X, A, D, N;

int main()
{
  cin >> X >> A >> D >> N;
  ll B = A + (N - 1) * D;
  if(D < 0) {
    A = -A;
    B = -B;
    D = -D;
    X = -X;
  }
  if(X <= A) {
    cout << A - X << endl;
    return 0;
  }
  if(X >= B) {
    cout << X - B << endl;
    return 0;
  }
  ll P = A + ((X - A) / D * D);
  ll Q = P + D;
  assert(P <= X && X <= Q);
  cout << min(X - P, Q - X) << endl;
  return 0;
}
