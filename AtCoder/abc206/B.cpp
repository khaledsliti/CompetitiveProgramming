// Guess Who's Back
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
  int n; cin >> n;
  int cur = 0;
  for(int i = 1; ; i++) {
    cur += i;
    if(cur >= n) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
