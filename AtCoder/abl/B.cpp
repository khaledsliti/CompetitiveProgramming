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

ll A, B, C, D;

int main()
{
  cin >> A >> B >> C >> D;
  A = max(A, C);
  B = min(B, D);
  if(A <= B) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
