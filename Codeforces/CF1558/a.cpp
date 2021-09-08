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

const int N = 1e5 + 5;

void run(vector<int>& arr, int a, int b, set<int>& sol) {
  int score_a = 0, score_b = 0;
  for(int i = 0; i < sz(arr); i++) {
    if(i % 2 == 0 && arr[i] == 0) score_a++;
    else if(i % 2 == 1 && arr[i] == 1) score_b++;
  }

  cout << a << " " << b << " " << score_a << " " << score_b << endl;

  for(int it = 0; it < a + b + 1; it++) {
    if(score_a <= a && score_b <= b) {
      sol.insert(score_a + score_b);
    }
    score_a++;
    score_b++;
  }
}

void solve(int a, int b, set<int>& sol) {
  vector<int> arr(a + b, 0);
  int cnt = 0;
  for(int i = 0; i < sz(arr) && cnt < a; i += 2) {
    arr[i] = 1;
    cnt++;
  }
  for(int i = 1; i < sz(arr) && cnt < a; i += 2) {
    arr[i] = 1;
    cnt++;
  }
  run(arr, a, b, sol);
  
  for(int i = 0; i < sz(arr); i++) {
    arr[i] = 0;
  }
  cnt = 0;
  for(int i = 1; i < sz(arr) && cnt < a; i += 2) {
    arr[i] = 1;
    cnt++;
  }
  for(int i = 0; i < sz(arr) && cnt < a; i += 2) {
    arr[i] = 1;
    cnt++;
  }
  run(arr, a, b, sol);
}

void solve() {
  int a, b;
  cin >> a >> b;
  set<int> sol;
  solve(a, b, sol);
  solve(b, a, sol);
  cout << sz(sol) << endl;
  for(int a: sol) {
    cout << a << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
