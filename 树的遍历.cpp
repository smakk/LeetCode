//树的4种遍历方式的递归和非递归解法
void Preorder(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->val << endl;
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(TreeNode* root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->val << endl;
    Inorder(root->right);
}
void Postorder(TreeNode* root) {
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << endl;
}

//树的遍历非递归解法
void Preorder2(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode * t = s.top();
        s.pop(); 
        cout << t->val << endl;
        if (t->right != NULL) s.push(t->right);
        if (t->left != NULL) s.push(t->left);
    }
}
void Preorder3(TreeNode* root) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            cout << root->val << endl;
            s.push(root);
            root = root->left;
        }else {
            root = s.top()->right;
            s.pop();
        }
    }
}
void Inorder2(TreeNode* root) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            cout << s.top()->val << endl;
            root = s.top()->right;
            s.pop();
        }
    }
}
void Postorder2(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* pre = NULL;
    while (!s.empty()) {
        TreeNode* t = s.top();
        if ((t->left == NULL && t->right == NULL) || (pre != NULL && (pre == t->left || pre == t->right))) {
            cout << t->val << endl;
            s.pop();
            pre = t;
        }
        else {
            if (t->right != NULL)
                s.push(t->right);
            if (t->left != NULL)
                s.push(t->left);
        }
    }
}

//层次遍历的递归解法，实际上还是利用的dfs的思想，对层次相等的节点进行输出
void dfs(vector<vector<int>>& result,int level,TreeNode* root) {
    if (root == NULL) return;
    while (result.size() <= level)
        result.emplace_back(vector<int>());
    result[level].emplace_back(root->val);
    dfs(result, level + 1, root->left);
    dfs(result, level + 1, root->right);
}
void Levelorder2(TreeNode* root) {
    vector<vector<int>> result;
    dfs(result,0,root);
    for (auto i : result)
        for (auto j : i)
            cout << j << endl;
}

void dfs_out(TreeNode* root,int level, int target) {
    if (root == NULL) return;
    if (level == target)
        cout << root->val << endl;
    dfs_out(root->left, level + 1, target);
    dfs_out(root->right, level + 1, target);
}
int depth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}
void Levelorder3(TreeNode* root) {
    int d = depth(root);
    for (int i = 0; i < d; i++) {
        dfs_out(root, 0, i);
    }
}

//这是测试用例
//while循环退出条件的时候转化成for时来看
int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);
    TreeNode t8(8);
    TreeNode t9(9);
    TreeNode t10(10);
    TreeNode t11(11);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t5.left = &t8;
    t5.right = &t9;
    t9.left = &t10;
    t9.right = &t11;
    Levelorder3(&t1);

    system("pause");
    return 0;
}