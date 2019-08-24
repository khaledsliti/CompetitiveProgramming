#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
string s;
int arr[N];

int main()
{
  cin >> n;
  n *= 2;
  cin >> s;
  for(int i = 0 ; i < n ; i++)
    arr[i] = s[i] == 'B';
  int prv = 0, acc = 0;
  int ans = 1;
  for(int i = 0 ; i < n ; i++){
    int cur = arr[i] ^ acc;
    if(cur){ // must start
      // cout << "start" << endl;
      prv++;
      acc ^= 1;
    }else{ // must end
      // cout << "end" << endl;
      ans = (1LL * ans * prv) % mod;
      prv--;
      acc ^= 1;
    }
  }
  if(prv) cout << 0 << endl;
  else{
    for(int i = 2 ; i <= n / 2 ; i++)
      ans = (1LL * ans * i) % mod;
    cout << ans << endl;
  }
  return 0;
}
