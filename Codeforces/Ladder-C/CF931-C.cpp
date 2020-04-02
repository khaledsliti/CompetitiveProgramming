// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if(arr[0] + 2 != arr[n - 1]) {
    cout << n << endl;
    for(int i = 0 ; i < n ; i++)
      cout << arr[i] << " ";
    cout << endl;
  } else {
    int a = 0, b = 0, c = 0;
    for(int i = 0 ; i < n ; i++)
      if(arr[i] == arr[0]) a++;
      else if(arr[i] == arr[0] + 1) b++;
      else c++;
    int ch1 = b / 2 * 2;
    int ch2 = min(a, c) * 2;
    if(ch1 > ch2) {
      for(int i = 0 ; i < n - 1 ; i++) {
        if(arr[i] == arr[i + 1] && arr[i] == arr[0] + 1)
          arr[i] = arr[0], arr[i + 1] = arr[0] + 2;
      }
    } else {
      int mn = arr[0];
      for(int i = 0 ; i < n / 2 ; i++)
        if(arr[i] == arr[n - i - 1] - 2 && arr[i] == mn)
          arr[i] = arr[n - i - 1] = mn + 1;
    }
    cout << n - max(ch1, ch2) << endl;
    for(int i = 0 ; i < n ; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}
