#include <bits/stdc++.h>
using namespace std;

//Two stacks O(N)
/*
int longestValidParentheses(string s) {
    stack<int> st;
    stack<pair<int, int>> hi;
    int ans = 0;
    for(int i = 0;  i < s.size(); i++) {
        if(s[i] == '(')
            st.push(i);
        else if(!st.empty()){
            int l = st.top();
            //Falls under the domain we are considering.
            while(!hi.empty() && l < hi.top().second) hi.pop();
            //concatnating what we have in left
            while(!hi.empty() && hi.top().second == l-1) l = hi.top().second - hi.top().first + 1, hi.pop();

            //WE have a fine candidate of l and r. Compare and then push it back to the stack.
            ans = max(ans, i-l+1);
            hi.push({i-l+1, i});
            st.pop();
        }
    }
    return ans;
}
*/

//One stack [significant constant time improvement] O(N)



int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << '\n';
}