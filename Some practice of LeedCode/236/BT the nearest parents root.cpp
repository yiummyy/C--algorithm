#include <iostream>
/*
在左、右子树中分别查找是否包含p或q：
如果以下两种情况（左子树包含p，右子树包含q/左子树包含q，右子树包含p），那么此时的根节点就是最近公共祖先
如果左子树包含p和q，那么到root->left中继续查找，最近公共祖先在左子树里面
如果右子树包含p和q，那么到root->right中继续查找，最近公共祖先在右子树里面
*/ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){return root; }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return left == nullptr? right : (right == nullptr? left : root); //it's impossible that left and right are all nullptr
    }
    
int main(int argc, char** argv) {
	return 0;
}
