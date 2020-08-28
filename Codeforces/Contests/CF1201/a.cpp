#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1001;

int n, m;
int q[N][5];

int main()
{
  
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      char c;
      cin >> c;
      q[j][c - 'A']++;
    }
  }
  int sum = 0;
  for(int j = 0 ; j < m ; j++){
    int mx = 0;
    for(int c = 0 ; c < 5 ; c++)
      mx = max(mx, q[j][c]);
    int a;
    cin >> a;
    sum += a * mx;
  }
  cout << sum << endl;
  return 0;
}
