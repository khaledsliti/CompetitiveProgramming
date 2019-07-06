#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
using namespace std;
 
const int N = 1e5 + 5;
 
int n;
int deg[N];
 
int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int a, b;
    cin >> a >> b;
    deg[--a]++;
    deg[--b]++;
  }
  for(int i = 0 ; i < n ; i++)
    if(deg[i] == 2)
      return cout << "NO" << endl, 0;
  cout << "YES" << endl;
  return 0;
}
