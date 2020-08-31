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

const int N = 3;

int a, b = 123456789;

int get(int a[N][N]) {
  int r = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      r = r * 10 + a[i][j];
    }
  }
  return r;
}

vector<int> neighbors(int a) {
  int x[N][N];
  vector<int> res;
  for(int i = N - 1; i >= 0; i--) {
    for(int j = N - 1; j >= 0; j--) {
      x[i][j] = a % 10;
      a /= 10;
    }
  }
  for(int i = 0; i < N - 1; i++) {
    for(int j = 0; j < N; j++) {
      swap(x[i][j], x[i + 1][j]);
      res.push_back(get(x));
      swap(x[i][j], x[i + 1][j]);
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N - 1; j++) {
      swap(x[i][j], x[i][j + 1]);
      res.push_back(get(x));
      swap(x[i][j], x[i][j + 1]);
    }
  }
  return res;
}

int main()
{
  a = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int x;
      cin >> x;
      a = a * 10 + x;
    }
  }
  queue<int> q;
  q.push(a);
  unordered_map<int, int> vis;
  vis[a] = 0;
  while(q.empty() == false) {
    int cur = q.front();
    q.pop();
    for(int v : neighbors(cur)) {
      if(vis.count(v) == 0) {
        vis[v] = 1 + vis[cur];
        q.push(v);
      }
    }
  }
  cout << vis[123456789] << endl;
  return 0;
}
