// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, s;
int arr[N];
long long tmp[N];

bool check(int k, int& cost) {
  for(int i = 0 ; i < n ; i++) {
    tmp[i] = arr[i] + 1LL * k * (i + 1);
  }
  sort(tmp, tmp + n);
  for(int i = 1 ; i < k ; i++)
    tmp[i] += tmp[i - 1];
  if(tmp[k - 1] > s)
    return false;
  cost = tmp[k - 1];
  return true;
}

int main()
{
  scanf("%d%d", &n, &s);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  int l = 1, r = n, ans = 0;
  int cost = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    int cur_cost;
    if(check(mid, cur_cost)){
      ans = mid;
      cost = cur_cost;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << ans << " " << cost << endl;
  return 0;
}
