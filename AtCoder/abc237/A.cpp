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
  long long x; cin >> x;
  if(x >= -(1LL << 31) && x <= (1LL << 31) - 1) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}
