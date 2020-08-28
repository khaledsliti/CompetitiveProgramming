// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n;
int arr[N];

int main()
{
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0 ; i < n ; i++)
      cin >> arr[i];
    sort(arr , arr + n);
    reverse(arr , arr + n);
    for(int i = 0 ; i < n ; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}
