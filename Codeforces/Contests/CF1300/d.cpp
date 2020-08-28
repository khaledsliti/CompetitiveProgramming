#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
typedef pair<int, int> point;
#define X first
#define Y second

int n;
int x[N], y[N];

point vec(pair<point, point> s)
{
  return { s.first.X - s.second.X, s.first.Y - s.second.Y };
}

bool same(pair<point, point> seg1, pair<point, point> seg2)
{
  auto v1 = vec(seg1);
  auto v2 = vec(seg2);
  // cout << v1.first << " " << v1.second << " - " << v2.first << " " << v2.second << endl;
  // cout << (v1.X == v2.X && v1.Y == v2.Y) << endl;
  // cout << "-----" <<  endl;
  return v1.X == v2.X && v1.Y == v2.Y;
}

bool solve()
{
  if(n & 1)
    return false;
  for(int i = 0 ; i < n / 2 ; i++){
    int j = i + n / 2;
    pair<point, point> s1 = {{x[i], y[i]}, {x[i + 1], y[i + 1]}};
    pair<point, point> s2 = {{x[(j + 1) % n], y[(j + 1) % n]}, {x[j], y[j]}};
    if(!same(s1, s2))
      return false;
  }
  return true;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d%d", &x[i], &y[i]);
  }
  cout << (solve() ? "yes" : "no") << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity