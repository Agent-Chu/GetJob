struct BinaryTreeNode{
    int data;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};
BinaryTreeNode* GetNextInorder(BinaryTreeNode* pNode){
    if(pNode == nullptr){
        return nullptr;
    }
    BinaryTreeNode* pNext = nullptr;
    //有右子树，则该节点的下一个结点是这个结点的右子树中最左子节点
    if(pNode!=nullptr){
        BinaryTreeNode* pRight = pNode->m_pRight;//这是右子树
        while(pRight->m_pLeft!=nullptr){//找右子树的最左结点
            pRight = pRight->m_pLeft;
        }
        pNext = pRight;
    }
    //没有右子树，需要向上遍历(0-n次)直到找到一个结点是左孩子，这个结点的父节点就是pNode的下一个结点
    else if(pNode->m_pParent!=nullptr){
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent!=nullptr&&pCurrent == pParent->m_pRight){
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }

    return pNext;
}