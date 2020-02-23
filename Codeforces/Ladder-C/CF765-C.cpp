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
  int k, a, b;
  cin >> k >> a >> b;
  if(a / k == 0){
    if(b >= k && b % k == 0) cout << b / k << endl;
    else cout << -1 << endl;
  }else if(b / k == 0){
    if(a >= k && a % k == 0) cout << a / k << endl;
    else cout << -1 << endl;
  }else{
    cout << a / k + b / k << endl;
  }
  return 0;
}
