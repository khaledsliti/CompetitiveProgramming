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

ll A, B, N;
ll P, Q, R, S;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> A >> B >> P >> Q >> R >> S;
  vector<vector<char>> arr(Q - P + 1, vector<char>(S - R + 1, '.'));
  
  for(int i = 0; i < sz(arr); i++) {
    for(int j = 0; j < sz(arr[i]); j++) {
      long long x = P + i, y = R + j;
      if(x + y == A + B || x - y == A - B) {
        arr[i][j] = '#';
      }
    }
  }

  for(int i = 0; i < sz(arr); i++) {
    for(int j = 0; j < sz(arr[i]); j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}
