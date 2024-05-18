/*
ou are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

 

Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
Example 2:


Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.


*/

/**
 * Definition for a binary tree node. */
  struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
 
class Solution {
public:
    // int countNode(TreeNode* root){
    //     if(root==NULL)return 0;
    //     if(root->left==NULL && root->right==NULL)return 1;
    //     int leftCount = countNode(root->left);
    //     int rightCount = countNode(root->right);
    //     return leftCount+rightCount+1;
    // }
    int dfs(TreeNode *root, int & moves){
        if(root==NULL)return 0;

        int leftChild = dfs(root->left, moves);
        int rightChild = dfs(root->right, moves);
        moves+=abs(leftChild)+abs(rightChild);
        return (leftChild+rightChild+root->val)-1;
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL)return 0;

        int moves = 0;
        int ans = dfs(root, moves);
        return moves;
        
    }
};