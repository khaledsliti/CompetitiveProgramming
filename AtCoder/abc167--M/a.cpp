// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;



int main()
{
  string a, b;
  cin >> a >> b;
  if(sz(a) == sz(b) - 1) {
    for(int i = 0 ; i < sz(a) ; i++) {
      if(a[i] != b[i])
        return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
  } else cout << "No" << endl;
  return 0;
}
