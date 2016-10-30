struct ListNode
{
  int m_nKey;
  ListNode* m_pNext;
};

//两个链表的第一个公共结点
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
  //得到两个链表的长度
  unsigned int nLength1 = GetListLength(pHead1);
  unsigned int nLength2 = GetListLength(pHead2);

  int nLengthDif = nLength1 - nLength2;

  ListNode* pListHeadLong = pHead1;
  ListNode* pListHeadShort = pHead2;
  if(nLength1 < nLength2)
  {
    pListHeadLong = pHead2;
    pListHeadShort = pHead1;
    nLengthDif = pListHeadLong - pListHeadShort;
  }

  //先在长链表上走几步，再在两个链表上同时遍历
  for(int i = 0; i < nLengthDif; ++ i)
    pListHeadLong = pListHeadLong->m_pNext;

  while((pListHeadLong != NULL) &&
        (pListHeadShort != NULL) &&
        (pListHeadShort != pListHeadLong)
        )
  {
    pListHeadLong = pListHeadLong->m_pNext;
    pListHeadShort = pListHeadShort->m_pNext;
  }
  ListNode* pFirstCommonNode = pListHeadLong;

  return pFirstCommonNode;
}

//得到链表的长度
unsigned int GetListLength(ListNode* pHead)
{
  unsigned int nLength = 0;
  ListNode* pNode = pHead;
  while(pNode != NULL)
  {
    ++ nLength;
    pNode = pNode->m_pNext;
  }

  return nLength;
}
