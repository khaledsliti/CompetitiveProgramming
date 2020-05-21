#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;

int main()
{
  cin >> n;
  long long sum = 1LL * n * (n + 1) / 2LL;
  if(sum & 1) cout << 1 << endl;
  else cout << 0 << endl;
  unordered_map<int, int> pref;
  pref[0] = 0;
  long long cur = 0;
  for(int i = 1 ; i <= n ; i++){
    cur += i;
    long long need = cur - sum / 2;
    if(pref.count(need)){
      cout << i - pref[need];
      for(int j = pref[need] + 1 ; j <= i ; j++)
        cout << " " << j;
      cout << endl;
      return 0;
    }
    pref[cur] = i;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity