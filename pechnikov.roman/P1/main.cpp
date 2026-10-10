#include <iostream>

namespace pechnikov
{
  void countMaxLenghtMonDec()
  {
    int countMax = 1, countMonDec = 1;
    int PrevNum, CurrentNum;
    std::cin >> PrevNum;
    std::cin >> CurrentNum;
    while (CurrentNum != 0)
    {
      if (PrevNum >= CurrentNum)
      {
        countMonDec += 1;
      }
      else
      {
        if (countMax < countMonDec)
        {
	  countMax = countMonDec;
 	}
	countMonDec = 1;
      }
      PrevNum = CurrentNum;
      std::cin >> CurrentNum;
    }
    if (countMax < countMonDec)
    {
      countMax = countMonDec;
    }
    std::cout << countMax;
  }
}
int main()
{
  pechnikov::countMaxLenghtMonDec();
  std::cout << "\n";
}
