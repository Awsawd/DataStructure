queue<Node*> t;


bool  isCompleteTree_0(Node* root)
{

    bool flag = false;//检测是否为叶子节点
    if (root == NULL) return true;
    t.push(root);

    while (!t.empty())
    {
        Node* cur = t.front();
        t.pop();
        if (cur->lchild) {
            if (flag) return false;
            t.push(cur->lchild);
        }
        else { flag = true; }

        if (cur->rchild) {
            if (flag) return false;
            t.push(cur->rchild);
        }
        else { flag = true; }

    }
    return true;
}
