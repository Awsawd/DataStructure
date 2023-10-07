void trans(Node* root)
{
		if (root = NULL) return;
		Node* temp;
		if (!root->left && !root->right)
			return;
			temp = root->left;
			root->left = root->right;
			root->right = temp;
			trans(root->left);
			trans(root->right);
			
}
