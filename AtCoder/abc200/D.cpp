// Guess Who's Back
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

const int Mod = 200;
const int N = 201;

int n;
int arr[N];
int dp[N][N][N][2][2];

int get(int a) { return (a % Mod + Mod) % Mod; }

int solve(int i, int x, int y, int t1, int t2) {
  if(x == y && t1 && t2) return 1;
  if(i >= n) return 0;
  int& r = dp[i][x][y][t1][t2];
  if(r != -1) return r;
  r = solve(i + 1, x, y, t1, t2);
  r |= solve(i + 1, get(x + arr[i]), y, 1, t2);
  r |= solve(i + 1, x, get(y + arr[i]), t1, 1);
  return r;
}

vector<int> A, B;
void trace(int i, int x, int y, int t1, int t2) {
  if(i >= n) return;
  if(solve(i, x, y, t1, t2) == solve(i + 1, x, y, t1, t2)) {
    trace(i + 1, x, y, t1, t2);
  } else if(solve(i, x, y, t1, t2) == solve(i + 1, get(x + arr[i]), y, 1, t2)) {
    A.push_back(i + 1);
    trace(i + 1, get(x + arr[i]), y, 1, t2);
  } else {
    B.push_back(i + 1);
    trace(i + 1, x, get(y + arr[i]), t1, 1);
  }
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  if(!solve(0, 0, 0, 0, 0)) {
    cout << "NO" << endl;
  } else {
    trace(0, 0, 0, 0, 0);
    cout << "YES" << endl;
    cout << sz(A);
    for(int x: A) cout << " " << x;
    cout << endl;
    cout << sz(B);
    for(int x: B) cout << " " << x;
    cout << endl;
  }
  return 0;
}
