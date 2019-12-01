/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1158/problem/D

  Idea:
    To build the solution, let's choose the points one by one.
    The first point is the point with the smallest Y (if there are more than one point we take the one with the smallest X).
    In each step we sort all point anti-clockwise. If we have to turn right we take the first point in the sorted array
    and we take the last one otherwise.

  Compexity:
    Time: O(N^2 log N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef complex<long long> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())

const int N = 2005;

struct pointWithIndex{
  point p;
  int index;
};

int n;
vector<pointWithIndex> points;
string dir;

struct cmp
{
    pointWithIndex about;
    cmp(pointWithIndex c)
    {
        about = c;
    }
    bool operator()(const pointWithIndex& p, const pointWithIndex& q) const
    {
        return cross(vec(about.p, p.p), vec(about.p, q.p)) < 0;
    }
};

int main()
{
  cin >> n;
  points.resize(n);
  for(int i = 0 ; i < n ; i++){
    int a, b;
    cin >> a >> b;
    points[i].p = point(a, b);
    points[i].index = i + 1;
  }
  cin >> dir;
  int bestIndex = 0;
  for(int i = 1 ; i < n ; i++){
    if(make_pair(points[bestIndex].p.Y, points[bestIndex].p.X) > make_pair(points[i].p.Y, points[i].p.X))
      bestIndex = i;
  }
  vector<int> ans;
  ans.push_back(points[bestIndex].index);
  pointWithIndex cur = points[bestIndex];
  points.erase(points.begin() + bestIndex);
  for(int i = 0 ; i < sz(dir) ; i++){
    sort(points.begin(), points.end(), cmp(cur));
    if(dir[i] == 'R'){
      cur = points[0];
      ans.push_back(points[0].index);
      points.erase(points.begin());
    }else{
      cur = points[sz(points) - 1];
      ans.push_back(points[sz(points) - 1].index);
      points.pop_back();
    }
  }
  assert(sz(points) == 1);
  ans.push_back(points[0].index);
  for(int i = 0 ; i < sz(ans) ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}