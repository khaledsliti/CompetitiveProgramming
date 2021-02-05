// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 25;

int n;
string A, B;
string s[N], t[N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void run() {
  for(int i = 0; i < n; i++) {
    t[i] = s[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int cnt = 0;
      for(int k = 0; k < 4; k++) {
        int ni = (i + dx[k]), nj = (j + dy[k]);
        ni = ((ni % n) + n) % n;
        nj = ((nj % n) + n) % n;
        if(s[ni][nj] == '1') {
          cnt++;
        }
      }
      if(s[i][j] == '0') {
        if(A[cnt] == '1') t[i][j] = '1';
        else t[i][j] = '0';
      }
      if(s[i][j] == '1') {
        if(B[cnt] != '1') t[i][j] = '0';
        else t[i][j] = '1';
      }
    }
  }

  for(int i = 0; i < n; i++) {
    s[i] = t[i];
  }
}

int main()
{
  string line; cin >> line;
  A = line.substr(0, 5);
  B = line.substr(6);
  int it;
  cin >> n >> it;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  while(it--) {
    run();
  }
  for(int i = 0; i < n; i++)
    cout << s[i] << endl;
  return 0;
}
