//数组中只出现一次的数字
//一个整型数组中有两个只出现一次的数字，其他的数字均出现两次。时间复杂度O(n)，空间复杂度O(1)

//判断num的二进制从右边数起的indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
  num = num >> indexBit;
  return (num & 1);
}

//在整数num的二进制找到右边数起的indexBit位是不是1
unsigned int FindFirstBitIs1(int num)
{
  int indexBit = 0;
  while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
  {
    num = num >> 1;
    ++ indexBit;
  }

  return indexBit;
}

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
  if (data == NULL || length < 2)
    return;

  int resultExclusiveOR = 0;
  for (int i = 0; i < length; ++ i)
    resultExclusiveOR ^= data[i];

  unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

  *num1 = *num2 = 0;
  for (int j = 0; j < length; ++ j)
  {
    if(IsBit1(data[j]), indexOf1)
      *num1 ^= data[j];
    else:
      *num2 ^= data[j];
  }
}
