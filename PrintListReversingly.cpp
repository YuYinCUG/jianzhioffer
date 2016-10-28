struct ListNode
{
  int m_nKey;
  ListNode* m_pNext;
};

//从尾到头打印链表

//用栈实现
void PrintListReversingly_Iteratively(ListNode* pHead)
{
  std::stack<ListNode*> nodes;

  ListNode* pNode = pHead;

  while(pNode != NULL)
  {
    nodes.push(pNode);
    pNode = pNode->m_pNext;
  }

  while(!nodes.empty())
  {
    pNode = nodes.top();
    printf("%d\t", pNode->m_nKey);
    nodes.pop();
  }
}

//用递归实现
void PrintListReversingly_Recursively(ListNode* pHead)
{
  if(pHead != NULL)
  {
    if(pHead->m_pNext!=NULL)
    {
      PrintListReversingly_Recursively(pHead->m_pNext);
    }
    printf("%d\t",pHead->m_nKey);
  }
}
