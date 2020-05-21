// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, m, d;
pair<int, int> arr[N];
int ans[N];

int main()
{
  scanf("%d%d%d", &n, &m, &d);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  sort(arr, arr + n);
  priority_queue<pair<int, int>> pq;
  int days = 0;
  for(int i = 0 ; i < n ; i++){
    if(pq.empty() || -pq.top().first > arr[i].first)
      pq.push({0, -++days});
    int t = -pq.top().first;
    int idx = -pq.top().second;
    pq.pop();
    ans[arr[i].second] = idx;
    pq.push({- (arr[i].first + d + 1), -idx});
  }
  cout << days << endl;
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
