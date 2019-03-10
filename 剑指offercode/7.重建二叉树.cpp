struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
    if(preorder == nullptr || inorder == nullptr || length<=0){
        return nullptr;
    }
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder){
    //找根节点或者子树的根节点的值 并构建结点
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    //结束递归的条件
    //前序和中序都遍历完
    if(startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder){//值也要相等
            return root;
        }
        else
            throw std::exception("invalid input");
    }

    //在中序遍历中找到根节点
    int* rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder!=rootValue){
        rootInorder++;
    }

    //如果找到的根节点的值，和前序中的根节点的值不同，则说明输入有问题
    if(rootInorder == endInorder && *rootInorder!=rootValue){
        throw std::exception("invalid input");
    }

    //中序中的左边长度
    int leftLength = rootInorder - startInorder;
    //前序中的左边结点
    int* leftPreorderEnd = startPreorder + leftLength;

    if(leftLength>0){//构建左子树
        root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }
    if(leftLength<endPreorder-startPreorder){
        root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    return root;
}