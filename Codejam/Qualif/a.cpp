#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int arr[N][N];

void solve(int tc) {
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> arr[i][j];
    int r = 0, t = 0, c = 0;
    for(int i = 0 ; i < n ; i++) {
        t += arr[i][i];
        unordered_set<int> s;
        for(int j = 0 ; j < n ; j++)
            s.insert(arr[i][j]);
        r += s.size() != n;
    }
    for(int j = 0 ; j < n ; j++) {
        unordered_set<int> s;
        for(int i = 0 ; i < n ; i++)
            s.insert(arr[i][j]);
        c += s.size() != n;
    }
    cout << "Case #" << tc << ": " << t << " " << r <<" "<< c << endl;
}

int main()
{
    int t, tc = 1;
    cin >> t;
    while(t--)  
        solve(tc++);
    return 0;
}