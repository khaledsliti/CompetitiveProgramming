#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e3 + 5;

int n;
pair<int, int> arr[N];
string sol;

void go(pair<int, int>& cur, pair<int, int> target)
{
  while(cur.first < target.first){
    cur.first++;
    sol += 'R';
  }
  while(cur.second < target.second){
    cur.second++;
    sol += 'U';
  }
}

bool check()
{
  sol.clear();
  pair<int, int> cur(0, 0);
  for(int i = 1 ; i < n ; i++)
    if(arr[i].second < arr[i - 1].second)
      return false;
  for(int i = 0 ; i < n ; i++)
    go(cur, arr[i]);
  return true;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    if(!check()) cout << "NO" << endl;
    else cout << "YES" << endl << sol << endl;
  }
  return 0;
}
