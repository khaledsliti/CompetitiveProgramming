#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int L, n;
int x[N];
long long fromFront[N];
long long fromBack[N];

long long getFront(int i, int j)
{
  if(i > j)
    return 0LL;
  return fromFront[j] - (i > 0 ? fromFront[i - 1] : 0);
}

long long getBack(int i, int j)
{
  if(i > j)
    return 0LL;
  return fromBack[i] - (j + 1 < n ? fromBack[j + 1] : 0);
}

int main()
{
  scanf("%d%d", &L, &n);
  long long ans = 0;
  for(int i = 0 ; i < n ; i++)
      scanf("%d", x + i);
  for(int it = 0 ; it < 2 ; it++){
    for(int i = 0 ; i < n ; i++){
      fromFront[i] = x[i];
      if(i)
        fromFront[i] += fromFront[i - 1];
    }
    for(int i = n - 1 ; i >= 0 ; i--){
      fromBack[i] = L - x[i];
      if(i + 1 < n)
        fromBack[i] += fromBack[i + 1];
    }
    for(int i = 0 ; i < n ; i++){
      int len = n - i;
      int mid = i + len / 2;
      long long cur = getFront(i, mid - 1) + getBack(mid + 1, n - 1);
      cur *= 2LL;
      if(len & 1) cur += getFront(mid, mid);
      else cur += getBack(mid, mid);
      ans = max(ans, cur);
    }
    for(int i = 0 ; i < n ; i++)
      x[i] = L - x[i];
    reverse(x, x + n);
  }
  cout << ans << endl;
  return 0;
}
