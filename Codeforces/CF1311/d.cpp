// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 40000;

int main()
{
  int t;
  cin >> t;
  while(t--){
    int a, b, c;
    cin >> a >> b >> c;
    int best = 1e9;
    int b_a, b_b, b_c;
    for(int A = 1 ; A <= N ; A++){
      for(int B = A ; B <= N ; B += A){
        for(int C = B ; C <= N ; C += B){
          int cur = abs(A - a) + abs(B - b) + abs(C - c);
          if(cur < best){
            best = cur;
            b_a = A, b_b = B, b_c = C;
          }
        }
      }
    }
    cout << best << endl;
    cout << b_a << " " << b_b << " " << b_c << endl;
  }
  return 0;
}
