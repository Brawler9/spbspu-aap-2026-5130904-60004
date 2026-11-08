#include <iostream>

namespace pechnikov
{
  class Count
  {
  private:
    int lenght_, current_, max_lenght_;
  public:
    void operator()(int next) const;
    int operator()();
    Count();
  };
}

int main()
{
  pechnikov::Count counter;
  int value = 0;
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

pechnikov::Count::Count()
{
  lenght_ = 0;
  current_ = 0;
  max_lenght_ = 0;
}


void pechnikov::Count::operator()(int next) const
{
  if (next == 0)
  {
    if (lenght_ > max_lenght_)
    {
      max_lenght_ = lenght_;
    }
  }
  else
  {
    if (next <= current_)
    {
      lenght_ += 1;
    }
    else
    {
      if (lenght_ > max_lenght_)
      {
        max_lenght_ = lenght_;
      }
      lenght_ = 1;
    }
    current_ = next;
  }
}

int pechnikov::Count::operator()()
{
  return max_lenght_;
}
