// Guess Who's Back
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

const int N = 1e5 + 5;

int n;
pair<long long, long long> arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr, arr + n);

  for(int i = 0; i < n; i++) {
    swap(arr[i].first, arr[i].second);
  }

  long long items = 0;
  long long cost = 0;
  int idx = n - 1;
  for(int i = 0; i < n; i++) {
    long long minItems = arr[i].second;
    long long need = arr[i].first;
    if(!need) continue;
    if(items >= minItems) {
      items += need;
      cost += need;
    } else if(idx > i) {
      long long toTake = minItems - items;
      while(idx > i && toTake > 0) {
        long long av = arr[idx].first;
        long long take = min(av, toTake);
        toTake -= take;
        cost += 2 * take;
        items += take;
        arr[idx].first -= take;
        if(arr[idx].first == 0) {
          idx--;
        }
      }
      i--;
    } else {
      long long rem = minItems - items;
      if(rem >= arr[i].first) {
        cost += arr[i].first * 2;
      } else {
        cost += 2 * rem + arr[i].first - rem;
      }
      items += arr[i].first;
    }
  }

  cout << cost << endl;

  return 0;
}
