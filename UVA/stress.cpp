#include <bits/stdc++.h>

using namespace std;

int main()
{
  system("g++ -std=c++11 -O2 UVA11765.cpp -o TLE");
  ofstream cout ("in.txt");
  int T = 50;
  cout << T << endl;
  while(T--){
    int n = 200;
    cout << n << " " << n * (n - 1) / 2 << endl;
    for(int it = 0 ; it < 2 ; it++){
      for(int i = 0 ; i < n ; i++)
        cout << rand() % 100 + 1 << " ";
      cout << endl;
    }
    for(int i = 0 ; i < n ; i++)
      cout << rand() % 3 - 1 << " ";
    cout << endl;
    for(int i = 1 ; i <= n ; i++)
      for(int j = i + 1 ; j <= n ; j++)
        cout << i << " " << j << " " << rand() % 100 + 1 << endl;
  }
  cout.close();
  system("TLE < in.txt > TLE.txt");
  return 0;
}