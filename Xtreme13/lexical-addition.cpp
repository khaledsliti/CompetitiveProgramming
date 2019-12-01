#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long n, a, b;
vector<long long> sol;

void build(int len)
{
  long long rem = n - a * len;
  sol.resize(len, a);
  for(int i = len - 1 ; i >= 0 && rem > 0 ; i--){
    long long cur = min(b - a, rem);
    rem -= cur;
    sol[i] += cur;
  }
}

bool check(int len)
{
  if(n >= len * a && n <= len * b){
    build(len);
    return true;
  }
  return false;
}

int main()
{
  while(cin >> n >> a >> b){
    sol.clear();
    for(int len = 1 ; len <= 1000000 ; len++)
      if(check(len))
        break;
    if(sz(sol)){
      cout << "YES" << endl;
      for(int i = 0 ; i < sz(sol) ; i++){
        if(i) cout << " ";
        cout << sol[i];
      }
      cout << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
