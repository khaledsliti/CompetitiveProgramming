// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, k;
int arr[N];
int score[N];
int tmp[N];
unordered_set<int> sol;

void solve(int pos) {
  tmp[pos + 1] = score[0];
  for(int i = pos + 2; i <= n ; i++) {
    tmp[i] = tmp[i - 1] + arr[i - 1];
  }
  for(int i = pos ; i >= 0 ; i--) {
    tmp[i] = tmp[i + 1] - arr[i];
  }
  unordered_set<int> sc;
  for(int i = 1 ; i <= n ; i++)
    sc.insert(tmp[i]);
  for(int i = 0 ; i < k ; i++){
    if(sc.find(score[i]) == sc.end())
      return;
  }
  sol.insert(tmp[0]);
}

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  for(int i = 0 ; i < k ; i++){
    cin >> score[i];
  }
  for(int i = 0 ; i < n ; i++)
    solve(i);
  cout << sz(sol) << endl;
  return 0;
}
