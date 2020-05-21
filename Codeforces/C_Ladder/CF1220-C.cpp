#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string s;

int main()
{
  cin >> s;
  int mn = 26;
  for(int i = 0 ; i < sz(s) ; i++){
    int cur = s[i] - 'a';
    if(mn < cur) printf("Ann\n");
    else printf("Mike\n");
    mn = min(mn, cur);
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity