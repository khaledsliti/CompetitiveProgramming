#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
typedef pair<long long, long long> point;

const long long MAX = 2e18;

point p0, p1, p2;
point s;
long long t;
vector<point> pts;

long long dist(const point& a, const point& b)
{
  return llabs(a.X - b.X) + llabs(a.Y - b.Y);
}

void pre()
{
  point cur = p0;
  pts.emplace_back(cur);
  while(max(cur.X, cur.Y) <= 1e16){
    cur = { cur.X * p1.X + p2.X, cur.Y * p1.Y + p2.Y };
    pts.emplace_back(cur);
  }
}

int solve(int st)
{
  point cur = s;
  if(dist(cur, pts[st]) > t)
    return 0;
  long long rem = t - dist(cur, pts[st]);
  cur = pts[st];
  int cnt = 1;
  for(int i = st - 1 ; i >= 0 ; i--){
    long long d = dist(cur, pts[i]);
    if(rem >= d){
      rem -= d;
      cur = pts[i];
      ++cnt;
    }else{
      break;
    }
  }
  for(int i = st + 1 ; i < sz(pts) ; i++){
    long long d = dist(cur, pts[i]);
    if(rem >= d){
      rem -= d;
      cur = pts[i];
      ++cnt;
    }else{
      break;
    }
  }
  return cnt;
}

int main()
{
  cin >> p0.X >> p0.Y >> p1.X >> p1.Y >> p2.X >> p2.Y;
  cin >> s.X >> s.Y >> t;
  pre();
  int best = 0;
  for(int i = 0 ; i < sz(pts) ; i++)
    best = max(best, solve(i));
  cout << best << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity