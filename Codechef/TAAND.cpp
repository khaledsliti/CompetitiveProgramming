// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
int arr[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
  }
  int best = 0;
  for(int i = 30 ; i >= 0 ; i--) {
    int cnt = 0;
    best |= (1 << i);
    for(int i = 0 ; i < n ; i++)
      if((arr[i] & best) == best) {
        cnt++;
      }
    if(cnt < 2)
      best ^= (1 << i);
  }
  cout << best << endl;
  return 0;
}
