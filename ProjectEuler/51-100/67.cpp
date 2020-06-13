// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;


int n;
int arr[100][100];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= i; j++) {
        cin >> arr[i][j];
        int add = 0;
        if(i > 0 && j < i) add = max(add, arr[i - 1][j]);
        if(i > 0 && j > 0) add = max(add, arr[i - 1][j - 1]);
        arr[i][j] += add;
      }
    }
    int best = 0;
    for(int i = 0; i < n; i++)
      best = max(best, arr[n - 1][i]);
    cout << best << endl;
  }
  return 0;
}
