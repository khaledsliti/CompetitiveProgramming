#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3005;

int n;
int s[N];
int c[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  for(int i = 0 ; i < n ; i++)
    cin >> c[i];
  int best = -1;
  for(int i = 1 ; i + 1 < n ; i++) {
    int best_left = 1e9;
    int best_right = 1e9;
    for(int j = 0 ; j < i ; j++)
      if(s[j] < s[i])
        best_left = min(best_left, c[j]);
    for(int j = i + 1 ; j < n ; j++)
      if(s[j] > s[i])
        best_right = min(best_right, c[j]);
    if(best_left < 1e9 && best_right < 1e9){
      int cur = best_left + best_right + c[i];
      if(best == -1 || best > cur){
        best = cur;
      }
    }
  }
  cout << best << endl;
  return 0;
}
