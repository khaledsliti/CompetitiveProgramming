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

const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int last = arr[n - 1];
  for(int i = 1; i < n; i++) {
    if(arr[i - 1] > arr[i]) {
      last = arr[i - 1];
      break;
    }
  }

  for(int i = 0; i < n; i++) {
    if(arr[i] != last) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;


  return 0;
}
