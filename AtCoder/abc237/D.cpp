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

const int N = 5e5 + 5;

int n;
int L[N], R[N];

int main()
{
  cin >> n;
  string s; cin >> s;
  for(int i = 0; i <= n; i++) {
    L[i] = -1;
    R[i] = -1;
  }
  for(int j = 1; j <= n; j++) {
    int i = j - 1;
    if(s[i] == 'L') {
      L[j] = L[i];
      R[j] = i;
      if(L[j] != -1) {
        R[L[j]] = j;
      }
      L[i] = j;
    } else {
      L[j] = i;
      R[j] = R[i];
      if(R[j] != -1) {
        L[R[j]] = j;
      }
      R[i] = j;
    }
  }
  int st = -1;
  for(int i = 0; i <= n; i++) {
    if(L[i] == -1) {
      st = i;
      break;
    }
  }
  for(; st != -1; st = R[st]) {
    cout << st << " ";
  }
  cout << endl;
  return 0;
}
