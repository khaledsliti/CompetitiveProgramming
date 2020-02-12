#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

struct point{
  long long x, y;
};

const int N = 1e6 + 5;

int n;
int arr[N];
vector<point> pts, hall;
long double ans[N];

bool is_smaller(const point& a, const point& b, const point& c)
{
  return (c.y - a.y) * (b.x - a.x) <= (b.y - a.y) * (c.x - a.x);
}

int main()
{
  scanf("%d", &n);
  pts.pb({0, 0});
  long long pref = 0;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
    pref += arr[i];
    pts.pb({i + 1, pref});
  }
  hall.pb(pts[0]);
  for(int i = 1 ; i < sz(pts) ; i++){
    while(sz(hall) > 1 && is_smaller(hall[sz(hall) - 2], hall[sz(hall) - 1], pts[i]))
      hall.pop_back();
    hall.pb(pts[i]);
  }
  for(int i = 0 ; i + 1 < sz(hall) ; i++){
    long long sum = 0;
    int cnt = 0;
    for(int j = hall[i].x ; j < hall[i + 1].x ; j++)
      cnt++, sum += arr[j];
    for(int j = hall[i].x ; j < hall[i + 1].x ; j++)
      printf("%.9f\n", sum * 1.0 / cnt);
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity