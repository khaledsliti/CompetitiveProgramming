// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


int h;

int get_leaf(int u, int len) {
  cout << "2 " << u << " " << len << endl;
  cout.flush();
  int r;
  cin >> r;
  return r;
}

int get_dist(int u) {
  cout << "1 " << u << endl;
  cout.flush();
  int r;
  cin >> r;
  return r;
}

void result(int u) {
  cout << "3 " << u << endl;
  cout.flush();
  int r;
  cin >> r;
  if(r == -1)
    exit(0);
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> h;
    int u = get_leaf(1, h);
    while(true) {
      assert(u > -1);
      int d = get_dist(u);
      assert(d > -1);
      if(d == 0) {
        result(u);
        break;
      }
      u = get_leaf(u, d);
      if(d == 2) {
        result(u);
        break;
      }
    }
  }
  return 0;
}
