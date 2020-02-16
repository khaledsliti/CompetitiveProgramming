class NestedIterator {
  typedef vector<NestedInteger>::iterator it;
  stack<pair<it, it>> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList){
    st.push(make_pair(nestedList.begin(), nestedList.end()));
    advance();
  }
  void advance(){
    while(!st.empty()){
      auto top = st.top();
      if(top.first == top.second){
        st.pop();
        if(!st.empty())
          st.top().first++;
      }else if(top.first->isInteger()){
        break;
      }else{
        vector<NestedInteger>& next_vector = top.first->getList();
        it first = next_vector.begin();
        it second = next_vector.end();
        st.push(make_pair(first, second));
      }
    }
  }
  int next(){
    if(!hasNext())
      return 0;
    int nxt = st.top().first->getInteger();
    st.top().first++;
    advance();
    return nxt;
  }
  bool hasNext(){
    return !st.empty();
  }
};