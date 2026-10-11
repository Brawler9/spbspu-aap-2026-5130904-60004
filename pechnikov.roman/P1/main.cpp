#include <iostream>
#include <stdexcept>

namespace pechnikov
{
  void countMaxLenghtMonDec()
  {
    int count_max = 1, count_mon_dec = 1;
    int prev_num = 0, current_num = 0;
    if (!(std::cin >> prev_num))
    {
      throw std::invalid_argument("Invalid num");
    }
    if (prev_num == 0)
    {
      throw std::runtime_error("Seq is too short");
    }
    if (!(std::cin >> current_num))
    {
      throw std::invalid_argument("Invalid num");
    }
    while (current_num != 0)
    {
      if (prev_num >= current_num)
      {
        count_mon_dec += 1;
      }
      else
      {
        if (count_max < count_mon_dec)
        {
          count_max = count_mon_dec;
        }
        count_mon_dec = 1;
      }
      prev_num = current_num;
      if (!(std::cin >> current_num))
      {
        throw std::invalid_argument("Invalid num");
      }
    }
    if (count_max < count_mon_dec)
    {
      count_max = count_mon_dec;
    }
    std::cout << count_max;
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
