class Solution {
public:
  string removeDuplicateLetters(string s){
    vector<int> pos[26];
    vector<int> done(26, 1);
    for(int i = (int) s.size() - 1 ; i >= 0 ; i--){
      int c = s[i] - 'a';
      pos[c].push_back(i);
      done[c] = 0;
    }
    int cnt = 0;
    for(int i = 0 ; i < 26 ; i++)
      cnt += done[i] == 0;
    string r = "";
    while(cnt--){
      for(int i = 0 ; i < 26 ; i++){
        if(!done[i]){
          int good = true;
          for(int j = 0 ; j < 26 && good ; j++){
            if(i != j && !done[j]){
              if(pos[j][0] < pos[i].back())
                good = false;
            }
          }
          if(good){
            r += char('a' + i);
            for(int j = 0 ; j < 26 ; j++){
              if(i != j && !done[j]){
                while(pos[j].back() < pos[i].back())
                  pos[j].pop_back();
              }
            }
            done[i] = 1;
            break;
          }
        }
      }
    }
    return r;
  }
};