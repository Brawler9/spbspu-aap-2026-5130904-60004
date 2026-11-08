#include <iostream>
#include <stdexcept>
#include <exception>
namespace pechnikov
{
  class Count
  {
  private:
    int lenght, current, max_lenght;
  public:
    void operator()(int next);
    int operator()();
    Count();
  };
}

pechnikov::Count::Count()
{
  lenght = 0;
  current = 0;
  max_lenght = 0;
}


void pechnikov::Count::operator()(int next)
{
  if (next == 0)
  {
    if (lenght > max_lenght)
    {
      max_lenght = lenght;
    }
  }
  else
  {
    if (next <= current)
    {
      lenght += 1;
    }
    else
    {
      if (lenght > max_lenght)
      {
        max_lenght = lenght;
      }
      lenght = 1;
    }
    current = next;
  }
}

int pechnikov::Count::operator()()
{
  return max_lenght;
}

int main()
{
  pechnikov::Count counter;
  int value;
  try
  {

    while (true)
    {
      if (!(std::cin >> value))
      {
        throw std::invalid_argument("Invalid argument");
      }
      counter(value);
      if (value == 0)
      {
        break;
      }
    }
  }
  catch (const std::invalid_argument& err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what() << "\n";
    return 2;
  }

  std::cout << counter();
}
