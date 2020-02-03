#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;
string s;

int solve()
{
  for(int i = n - 1 ; i >= 0 ; i--){
    int b = s[i] - '0';
    if(b % 2 == 0)
      continue;
    for(int j = i - 1 ; j >= 0 ; j--){
      int a = s[j] - '0';
      if(a % 2 == 0)
        continue;
      return a * 10 + b;
    }
  }
  return -1;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n >> s;
    cout << solve() << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity