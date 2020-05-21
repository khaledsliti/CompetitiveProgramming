#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 109;

int n, q;
int av[N];

int main()
{
  cin >> n >> q;
  while(q--){
    int t, k, d;
    cin >> t >> k >> d;
    vector<int> s;
    for(int i = 0 ; i < n && sz(s) < k ; i++) {
      if(av[i] <= t)
        s.push_back(i);
    }
    if(sz(s) == k) {
      int sum = 0;
      for(int j = 0 ; j < sz(s) ; j++){
        sum += s[j] + 1;
        av[s[j]] = d + t;
      }
      cout << sum << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
