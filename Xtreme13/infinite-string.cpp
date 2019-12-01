#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int b;
long long x;

long long power(long long a, long long b)
{
  if(!b)
    return 1LL;
  long long r = power(a, b >> 1);
  r *= r;
  if(b & 1)
    r *= a;
  return r;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> b >> x;
    if(b == 1){
      cout << "a" << endl;
      continue;
    }
    long long bp = b;
    int len = 1;
    while(x / bp >= len){
      x -= bp * len;
      bp *= b;
      len++;
    }
    long long idx = x / len;
    long long pos = (x % len) + 1;
    // cout << len << endl;
    // cout << len << " " << idx << " " << pos << endl;
    // cout << x << endl;
    int last = -1;
    string s = "";
    for(int i = len - 1 ; i >= len - pos ; i--){
      for(int d = b - 1 ; d >= 0 ; d--){
        long long pbi = d * power(b, i);
        if(idx >= pbi){
          last = d;
          idx -= pbi;
          s += char('a' + last);
          break;
        }
      }
    }
    if(last == -1)
      exit(-1);
    cout << s.back() << endl;
  }
  return 0;
}
