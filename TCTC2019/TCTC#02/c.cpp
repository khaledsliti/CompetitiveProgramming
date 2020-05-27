#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

int n;
int cnt[26];

int main()
{
  cin >> n;
  long long minLen = 27 * 13;
  if(minLen > n)
    cout << -1 << endl;
  else{
    for(int i = 0 ; i < 26 ; i++)
      cnt[i] = i + 1;
    n -= minLen;
    int At = 25;
    for(int i = 0; i < n ; i++){
      cnt[At]++;
      if(--At < 0)
        At = 25;
    }
    string s;
    for(int i = 0 ; i < 26 ; i++)
      while(cnt[i]--)
        s += char('a' + i);
    cout << s << endl;
  }
  return 0;
}
