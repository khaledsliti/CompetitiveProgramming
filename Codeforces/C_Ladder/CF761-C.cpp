// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 51;
const int oo = 1e5;

int n, m;
string s[N];
int dist[N][3];

int index(char c) {
  if(c >= '0' && c <= '9') return 0;
  if(c >= 'a' && c <= 'z') return 1;
  return 2;
}


int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  for(int i = 0 ; i < n ; i++)  
    for(int j = 0 ; j < 3 ; j++)
      dist[i][j] = oo;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      int idx = index(s[i][j]);
      dist[i][idx] = min(dist[i][idx], min(j, m - j));
    }
  }
  int best = oo;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      if(i == j) continue;
      for(int k = 0 ; k < n ; k++) {
        if(k == i || k == j) continue;
        best = min(best, dist[i][0] + dist[j][1] + dist[k][2]);
      }
    }
  }
  cout << best << endl;
  return 0;
}
