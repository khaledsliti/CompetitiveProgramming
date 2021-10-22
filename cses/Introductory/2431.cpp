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

void solve(long long k) {
  long long s = 9, l = 1;
  while(true) {
    long long cur_size = s * l;
    if(k <= cur_size) {
      long long number = 1;
      for(int i = 0; i < l - 1; i++) {
        number *= 10;
      }
      number += (k - 1) / l;
      cout << to_string(number)[(k - 1) % l] << endl;
      break;
    }
    k -= cur_size;
    s *= 10;
    l++;
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    long long k;
    cin >> k;
    solve(k);
  }
  return 0;
}
