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
  
  long long a;
  cin >> a;
  set<ll> div;
  for(ll i = 1; i * i <= a; i++) {
    if(a % i == 0) {
      div.insert(i);
      if(a / i != i) {
        div.insert(a / i);
      }
    }
  }
  for(auto x : div) 
    cout << x << endl;
  return 0;
}
