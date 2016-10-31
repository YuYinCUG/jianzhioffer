//二进制中1的个数

int Numberof1(int n)
{
  int count = 0;
  while(n)
  {
    n = (n - 1) & n;
    ++ count;
  }
  return count;
}
