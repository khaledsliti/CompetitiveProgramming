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

const int N = 106;

int n, m;
int pl[N];
int score[N];
string s[N];

void play(int a, int b, int j) {
  char x = s[a][j];
  char y = s[b][j];
  if(x == 'G') {
    if(y == 'C') {
      score[a]++;
    } else if(y == 'P') {
      score[b]++;
    }
  } else if(x == 'C') {
    if(y == 'P') {
      score[a]++;
    } else if(y == 'G') {
      score[b]++;
    }
  } else if(x == 'P') {
    if(y == 'G') {
      score[a]++;
    } else if(y == 'C') {
      score[b]++;
    }
  }
}

int main()
{
  cin >> n >> m;
  n *= 2;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    pl[i] = i;
  }
  for(int j = 0; j < m; j++) {
    for(int i = 0; i < n; i += 2) {
      int k = i + 1;
      play(pl[i], pl[i + 1], j);
    }
    sort(pl, pl + n, [&](int x, int y) {
      if(score[x] != score[y]) {
        return score[x] > score[y];
      }
      return x < y;
    });
  }
  for(int i = 0; i < n; i++) {
    cout << pl[i] + 1 << endl;
  }
  return 0;
}
