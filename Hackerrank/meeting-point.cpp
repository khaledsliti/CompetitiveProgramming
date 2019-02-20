/*
  Author: RedStone

  Idea:
    The main idea is to transform coordinates from (x, y) => (x - y, x + y) = (u, v)
    After this, the Chebyshev distance:

      Max(abs(x1 - x2), abs(y1 - y2)) = [ abs( abs(x1 - x2) - abs(y1 - y2 ) ) + abs( abs(x1 - x2) + abs(y1 - y2 ) ) ] / 2
                                      = [ abs(x1 - x2 - y1 + y2) + abs(x1 - x2 + y1 - y2) ] / 2     (By Symmetry)
                                      = [ abs(u1 - u2) + abs(v1 - v2) ] / 2

      abs(u - v) + abs(u + v) is the Manhatten distance

      So now, we must find the point with minimum sum of all Manhatten distances after transforming the point (x, y) to (x - y, x + y)
      To calculate the sum of the distances from a point to all other points, we can do this in O(log N). We need to sort all x coordinates and y coordinate
      Then we can use prefix sum with a simple formula:

      D = Sum[ abs(x - x_i) + abs(y - y_i) ]
        = Sum[ abs(x - x_i) ] + Sum[ abs(y - y_i) ]

      To calculate Sum[ abs(x - x_i) ] we can get the sum of all x_i less than or equal to x (let's call it L) and the sum of all x_i greater than x (let's call it R)
      So, Sum[ abs(x - x_i) ] = R - (N - cnt) * x + cnt * x - L, where cnt is the number of x_i less than or equal to x
      And we do the same thing for Sum[ abs(y - y_i) ]

  Compexity: O(N log(N))
*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 1e5 + 5;

int n;
int x[N], y[N];
int xs[N], ys[N];
ll xcum[N], ycum[N];

ll calc(int val, ll* cum, int* x)
{
  int idx = lower_bound(x, x + n, val + 1) - x;
  ll left_sum = idx ? cum[idx - 1] : 0;
  ll right_sum = cum[n - 1] - left_sum;
  return (2LL * idx - n) * val + right_sum - left_sum;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    x[i] = a + b;
    y[i] = a - b;
    xs[i] = x[i];
    ys[i] = y[i];
  }
  sort(xs, xs + n);
  sort(ys, ys + n);
  for(int i = 0 ; i < n ; i++){
    xcum[i] = xs[i];
    ycum[i] = ys[i];
    if(i){
      xcum[i] += xcum[i - 1];
      ycum[i] += ycum[i - 1];
    }
  }
  ll best = 1e18;
  for(int i = 0 ; i < n ; i++)
    best = min(best, calc(x[i], xcum, xs) + calc(y[i], ycum, ys));
  cout << best / 2 << endl;
	return 0;
}
