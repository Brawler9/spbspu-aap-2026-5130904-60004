#include <iostream>

namespace pechnikov
{
  void countMaxLenghtMonDec()
  {
    int countMax = 1, countMonDec = 1;
    int PrevNum,CurrentNum;
    if (!(std::cin >> PrevNum))
    {
      throw std::invalid_argument("InvalidNum");
    }
    if (PrevNum == 0)
    {
      throw std::runtime_error("Seq is too short");
    }
    if (!(std::cin >> CurrentNum))
    {
      throw std::invalid_argument("Invalid num");
    }
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
      if (!(std::cin >> CurrentNum))
      {
        throw std::invalid_argument("Invalid num");
      }
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
  try
  {
    pechnikov::countMaxLenghtMonDec();
  }
  catch (const std::invalid_argument& err)
  {
    std::cout << err.what();
    return 1;
  }
  catch (const std::runtime_error& err)
  {
    std::cout << err.what();
    return 2;
  }
  std::cout << "\n";
}
