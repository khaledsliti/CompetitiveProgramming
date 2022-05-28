#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2472200;


int n;
int A[N], B[N];
pair<int, int> idx[N];
int cur_idx;

int lis(vector<int>& arr) {
  vector<int> t;
  for(int i = 0; i < sz(arr); i++) {
    int pos = lower_bound(all(t), arr[i]) - begin(t);
    if(pos < sz(t)) {
      t[pos] = arr[i];
    } else {
      t.push_back(arr[i]);
    }
  }
  return sz(t);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n ;i++) {
    int x; cin >> x;
    A[x] = i;
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    B[x] = i;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j += i) {
      idx[cur_idx++] = {A[i], B[j]};
    }
  }

  sort(idx, idx + cur_idx, [](const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  });

  // for(int i = 0; i < cur_idx; i++) {
  //   cout << idx[i].first << " " << idx[i].second << endl;
  // }

  vector<int> arr(cur_idx);
  for(int i = 0; i < cur_idx; i++) {
    arr[i] = idx[i].second;
  }

  cout << lis(arr) << endl;


  return 0;
}
