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
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int f = sz(s), l = -1;
    for(int i = 0 ; i < sz(s) ; i++){
      int j = sz(s) - 1 - i;
      if(s[j] == '1')
        f = j;
      if(s[i] == '1')
        l = i;
    }
    int ans = 0;
    while(f <= l)
      ans += s[f++] == '0';
    cout << ans << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity