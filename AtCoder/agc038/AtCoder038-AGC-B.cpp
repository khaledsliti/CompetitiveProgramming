#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int arr[N];
int pref[N];

bool isSorted(int i, int j)
{
  if(i >= j)
    return true;
  int s = pref[j];
  if(i) s -= pref[i];
  return s == 0;
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  for(int i = 1 ; i < n ; i++)
    pref[i] = (arr[i - 1] > arr[i]) + pref[i - 1];
  vector<int> pos = {0};
  set<int> cur;
  for(int i = 0 ; i < k ; i++)
    cur.insert(arr[i]);
  for(int i = 1 ; i <= n - k ; i++){
    bool can = (arr[i - 1] == *(cur.begin())) && (arr[i + k - 1] > *(cur.rbegin()));
    if(!can)
      pos.pb(i);
    cur.erase(arr[i - 1]);
    cur.insert(arr[i + k - 1]);
  }
  int sorted = 0;
  for(int i = 0 ; i < sz(pos) ; i++)
    if(isSorted(pos[i], pos[i] + k - 1))
      sorted++;
  // cout << sorted << endl;
  cout << sz(pos) - max(0, sorted - 1) << endl;
  return 0;
}
