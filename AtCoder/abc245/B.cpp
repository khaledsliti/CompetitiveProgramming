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



int main()
{
  int n;
  cin >> n;
  set<int> ex;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    ex.insert(a);
  }
  for(int i = 0;; i++) {
    if(ex.find(i) == ex.end()) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
