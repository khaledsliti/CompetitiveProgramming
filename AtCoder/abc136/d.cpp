#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
string s;
int L[N], R[N];
int ans[N];

int main()
{
  cin >> s;
  n = sz(s);
  for(int i = 0 ; i < n ; i++){
    if(s[i] == 'R')
      L[i] = 0;
    else
      L[i] = L[i - 1] + 1;
  }
  for(int i = n - 1 ; i >= 0 ; i--){
    if(s[i] == 'L')
      R[i] = 0;
    else
      R[i] = R[i + 1] + 1;
  }
  for(int i = 0 ; i < n ; i++){
    if(s[i] == 'L'){
      int d = L[i];
      if(d & 1)
        d--;
      ans[i - d]++;
    }else{
      int d = R[i];
      if(d & 1)
        d--;
      ans[i + d]++;
    }
  }
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  return 0;
}
