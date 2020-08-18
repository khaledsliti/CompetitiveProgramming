#include <bits/stdc++.h>
using namespace std;
#define N 100010

int n, k;
string s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> k >> s;
    sort(begin(s), end(s));
    if(s[k - 1] == s[0]) {
      cout << s[0];
      if(n == k) {
        cout << endl;
        continue;
      }
      if(s[n - 1] == s[k]) {
        for(int i = 0 ; i < (n - 1) / k; i++)
          cout << s[k];
        cout << endl;
      } else {
        for(int i = k ; i < n ; i++)
          cout << s[i];
        cout << endl;
      }
    } else {
      cout << s[k - 1] << endl;
    }
  }
  return 0;
}
