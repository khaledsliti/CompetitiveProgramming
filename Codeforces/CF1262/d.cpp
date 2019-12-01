#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

struct query{
  int k, pos, idx;
  bool operator<(const query& rhs) const {
    return k < rhs.k;
  }
};

int n, q;
int org[N];
pair<int, int> arr[N];
query qr[N];
int ans[N];

int bit[N];

void add(int idx)
{
  idx++;
  for(; idx <= n ; idx += idx & -idx)
    bit[idx]++;
}

int get(int idx)
{
  idx++;
  int v = 0;
  for(; idx ; idx -= idx & -idx)
    v += bit[idx];
  return v;
}

int getNth(int nth)
{
  int l = 0, r = n - 1, ans = -1;
  while(l <= r){
    int mid = (l + r) / 2;
    int v = get(mid);
    if(v >= nth){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return ans;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &arr[i].first);
    arr[i].second = i;
    org[i] = arr[i].first;
  }
  sort(arr, arr + n, [&](pair<int, int>& a, pair<int, int>& b){
    if(a.first != b.first)
      return a.first < b.first;
    return a.second > b.second;
  });
  // for(int i = 0 ; i < n ; i++)
  //   cout << arr[i].second << " ";
  // cout << endl;
  // return 0;
  scanf("%d", &q);
  for(int i = 0 ; i < q ; i++){
    scanf("%d%d", &qr[i].k, &qr[i].pos);
    qr[i].idx = i;
  }
  sort(qr, qr + q);
  int left = n - 1;
  for(int i = 0 ; i < q ; i++){
    int firstElement = n - qr[i].k;
    while(left >= firstElement)
      add(arr[left--].second);
    ans[qr[i].idx] = getNth(qr[i].pos);
  }
  for(int i = 0 ; i < q ; i++)
    printf("%d\n", org[ans[i]]);
  return 0;
}
