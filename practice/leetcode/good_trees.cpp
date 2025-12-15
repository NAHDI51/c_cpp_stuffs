#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
int cnt;
map<int, int> mp;
public:
Solution() {cnt = 0;}
int highest() {
    auto it = mp.end();
    it--;
    return it->first;
}
int goodNodes(TreeNode* root) {
    GoodNodes(root);
    return cnt;
}
int GoodNodes(TreeNode* root) {
    if(root == NULL) return;

    if(mp.empty() || (highest() <= root->val)) cnt++;
    mp[root->val]++;
    GoodNodes(root->left), GoodNodes(root->right);
    mp[root->val]--;
    if(mp[root->val] == 0) mp.erase(root->val);
}
};

int main() {

}