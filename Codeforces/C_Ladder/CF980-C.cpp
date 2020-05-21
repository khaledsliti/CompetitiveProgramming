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

int n, k;
int rep[N], arr[N];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < 256 ; i++)
    rep[i] = -1;
  for(int i = 0 ; i < n ; i++) {
    if(~rep[arr[i]]) continue;
    int j = arr[i];
    while(j >= 0 && rep[j] == -1 && arr[i] - j + 1 <= k)
      --j;
    if(j >= 0 && arr[i] - j + 1 <= k && arr[i] - rep[j] + 1 <= k)
      rep[arr[i]] = rep[j];
    else rep[arr[i]] = j + 1;
    ++j;
    while(j < arr[i])
      rep[j++] = rep[arr[i]];
  }
  for(int i = 0 ; i < n ; i++)
    cout << rep[arr[i]] << " ";
  return 0;
}
