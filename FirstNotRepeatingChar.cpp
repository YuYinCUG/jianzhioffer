//第一个只出现一次的字符

char FirstNotRepeatingChar(char* pString)
{
  if(pString == NULL)
    return '\0';

  const int tablesize = 256;

  unsigned int hashTable[tablesize];
  for(unsigned int i = 0; i<tablesize; ++i)
    hashTable[i] = 0;
  char* pHashKey = pString;
  while(*(pHashKey) != '\0')
    hashTable[*(pHashKey++)] ++;

  pHashKey = pString;
  while(*pHashKey != '\0')
  {
    if(hashTable[*pHashKey] == 1)
      return *pHashKey;
    pHashKey++;
  }
  return '\0';
}
