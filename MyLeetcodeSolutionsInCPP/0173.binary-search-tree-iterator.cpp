/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }

    /** @return the next smallest number */
    int next()
    {
        return vals[i++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return i < vals.size();
    }

private:
    int i = 0;
    vector<int> vals;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }
};