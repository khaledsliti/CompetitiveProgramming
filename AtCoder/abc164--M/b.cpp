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
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int t = 0;
  while(A > 0 && C > 0) {
    if(t == 0) {
      C -= B;
    } else {
      A -= D;
    }
    t ^= 1;
  }
  if(t == 0) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
