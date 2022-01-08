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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long k; cin >> k;
  vector<int> sol;
  while(k > 0) {
    if(k & 1) sol.push_back(2);
    else sol.push_back(0);
    k >>= 1;
  }
  reverse(all(sol));

  for(int x: sol) {
    cout << x;
  }
  cout << endl;
  return 0;
}

/*

0
2
20
22


*/
