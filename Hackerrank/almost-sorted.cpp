#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;

int n;
int arr[N];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int peek = -1, valley = -1;
    for(int i = 0; i < n && peek == -1; i++)
      if((!i || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i + 1] < arr[i]))
        peek = i;
    for(int i = n - 1; i >= 0 && valley == -1; i--)
      if((!i || arr[i - 1] > arr[i]) && (i == n - 1 || arr[i + 1] > arr[i]))
        valley = i;
    if(peek != -1 && valley != -1 && peek < valley) {
      swap(arr[peek], arr[valley]);
      if(is_sorted(arr, arr + n)) {
        cout << "yes\nswap " << peek + 1 << " " << valley + 1 << endl;
        return 0;
      }
      swap(arr[peek], arr[valley]);
      reverse(arr + peek, arr + valley + 1);
      if(is_sorted(arr, arr + n)) {
        cout << "yes\nreverse " << peek + 1 << " " << valley + 1 << endl;
        return 0;
      }
    }
    cout << "no" << endl;
    return 0;
}
