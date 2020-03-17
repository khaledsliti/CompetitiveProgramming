#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5005;

int n, m;
int s[N];
int f[N], h[N];
int L[N][N], R[N][N];

void pre()
{
  memset(L, -1, sizeof L);
  memset(R, -1, sizeof R);
  for(int i = 0 ; i < n ; i++){
    if(i > 0){
      for(int j = 0 ; j < n ; j++)
        L[i][i]
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  for(int i = 0 ; i < m ; i++){
    cin >> f[i] >> h[i];
  }

  return 0;
}
