struct ListNode
{
  int m_nValue;
  ListNode* m_pNext;
}

//在O(1)时间内删除链表结点
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
  //如果链表为空或被删除结点为空
  if(!pListHead || !pToBeDeleted)
    return;

  //要删除结点不是链表尾结点
  if(pToBeDeleted->m_pNext != NULL)
  {
    ListNode* pNext = pToBeDeleted->m_pNext;
    pToBeDeleted->m_nValue = pNext->m_nValue;
    pToBeDeleted->m_pNext = pNext->m_pNext;

    delete pNext;
    pNext = NULL;
  }
  //链表只有一个结点，删除头结点也是删除尾结点
  else if(*pListHead == pToBeDeleted)
  {
    delete pToBeDeleted;
    pToBeDeleted = NULL;
    *pListHead = NULL;
  }
  //链表中有多个结点，删除尾结点
  else
  {
    ListNode* pNode = *pListHead;
    while(pNode->m_pNext != pToBeDeleted)
    {
      pNode = pNode->m_pNext;
    }
    pNode->m_pNext = NULL;
    delete pToBeDeleted;
    pToBeDeleted = NULL;
  }
}
