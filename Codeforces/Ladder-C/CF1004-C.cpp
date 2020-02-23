#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];
int bit[N];
int used[N];

void add(int idx)
{
  for(int i = idx ; i < N ; i += i & -i)
    bit[i]++;
}

int get(int idx)
{
  int r = 0;
  for(int i = idx ; i > 0 ; i -= i & -i)
    r += bit[i];
  return r;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  for(int i = 0 ; i < n ; i++)
    if(!used[arr[i]]){
      add(i + 1);
      used[arr[i]] = 1;
    }
  for(int i = 0 ; i < n ; i++)
    used[arr[i]] = 0;
  long long ans = 0;
  for(int i = n - 1 ; i >= 0 ; i--){
    if(!used[arr[i]]){
      ans += get(i);
      used[arr[i]] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
