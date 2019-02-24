/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1117/problem/C

  Idea:
    If we can reach the destination point after x days so we can reach it after (x + 1) days. Because we can simply go to the opposite
    of the direction of the wind after the x_th day.
    So we can do binary search on the number of required days to find the minimum number of needed days.
    Now, given the number of days d. Starting from point (x1, y1) and if we don't any movement we can reach point (x1 + dx, y1 + dy)
    So given this point, we can know if we can reach point (x2, y2) after d days. Simply the Manhattan distance between (x1 + dx, y1 + dy)
    and (x2, y2) must be less than or equal to the number of days.

  Compexity:
    Time: (64 * N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 1e5 + 5;

long long x1, x2, y1, y2;
int n;
string s;
int d[N][8];

bool check(long long days)
{
  ll dx = 0, dy = 0;
  for(int i = 0 ; i < n ; i++){
    dx += (s[i] == 'R') - (s[i] == 'L');
    dy += (s[i] == 'U') - (s[i] == 'D');
  }
  dx *= days / n;
  dy *= days / n;
  int cnt = days % n;
  for(int i = 0 ; i < cnt ; i++){
    dx += (s[i] == 'R') - (s[i] == 'L');
    dy += (s[i] == 'U') - (s[i] == 'D');
  }
  dx += x1;
  dy += y1;
  long long need = llabs(dx - x2) + llabs(dy - y2);
  return need <= days;
}

int main()
{
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  cin >> s;
  long long l = 0, r = 4e18, ans = -1;
  while(l <= r){
    long long mid = (l + r) / 2;
    if(check(mid)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  cout << ans << endl;
	return 0;
}