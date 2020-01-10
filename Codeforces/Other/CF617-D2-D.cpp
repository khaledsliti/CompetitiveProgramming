#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> point;

point a[3];

bool check(const point& a, const point& b, const point c)
{
  return a.second == b.second && (c.first <= min(a.first, b.first) || c.first >= max(a.first, b.first));
}

int main()
{
  for(int i = 0 ; i < 3 ; i++)
    cin >> a[i].first >> a[i].second;
  for(int it = 0 ; it < 2 ; it++){
    if(a[0].first == a[1].first && a[1].first == a[2].first)
      return cout << 1 << endl, 0;
    for(int i = 0 ; i < 3 ; i++)
      swap(a[i].first, a[i].second);
  }
  for(int it = 0 ; it < 2 ; it++){
    vector<int> idx = {0, 1, 2};
    do{
      if(check(a[idx[0]], a[idx[1]], a[idx[2]]))
        return cout << 2 << endl, 0;
    }while(next_permutation(all(idx)));
    for(int i = 0 ; i < 3 ; i++)
      swap(a[i].first, a[i].second);
  }
  cout << 3 << endl;
  return 0;
}
