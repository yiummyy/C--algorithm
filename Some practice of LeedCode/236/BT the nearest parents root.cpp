#include <iostream>
/*
�����������зֱ�����Ƿ����p��q��
��������������������������p������������q/����������q������������p������ô��ʱ�ĸ��ڵ���������������
�������������p��q����ô��root->left�м������ң������������������������
�������������p��q����ô��root->right�м������ң������������������������
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
