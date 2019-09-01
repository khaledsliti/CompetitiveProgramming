#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n;
long long x[N], y[N];
int per[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> x[i] >> y[i];
  for(int i = 0 ; i < n ; i++)
    per[i] = i;
  sort(per, per + n, [&](int i, int j){
    double alp1 = atan2(y[i], x[i]);
    double alp2 = atan2(y[j], x[j]);
    return alp1 < alp2;
  });
  long long best = 0;
  for(int i = 0 ; i < n ; i++){
    long long cur_x = 0, cur_y = 0;
    for(int j = i ; j < i + n ; j++){
      cur_x += x[per[j % n]];
      cur_y += y[per[j % n]];
      best = max(best, cur_x * cur_x + cur_y * cur_y);
    }
  }
  cout << fixed << setprecision(15) << sqrt((long double)best) << endl;
  return 0;
}
