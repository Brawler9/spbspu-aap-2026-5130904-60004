#include <iostream>
#include <fstream>
#include <stdexcept>

namespace pechnikov
{
  int count(int* data, int row, int column);
}

int main(int argc, char** argv)
{
  int* data = nullptr;
  try
  {
    if (argc != 4)
    {
      throw std::runtime_error("Not 3 argument");
    }
    if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
    {
      throw std::runtime_error("First argument out of range");
    }
    int row = 0, column = 0;

    std::ifstream file(argv[2]);
    if (!file)
    {
      throw std::runtime_error("File not opened");
    }
    if (!(file >> row >> column))
    {
      throw std::logic_error("can't read size");
    }
    if ((row <= 0 || column <= 0) && !(row == 0 && column == 0))
    {
      throw std::logic_error("Length error");
    }
    if (row * column > 10000)
    {
      throw std::logic_error("Matrix is too large");
    }
    int stackdata[10000] = {};
    if (argv[1][0] == '1')
    {
      data = stackdata;
    }
    if (argv[1][0] == '2')
    {
      data = new int[row * column];
    }
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        if (!(file >> data[i * column + j]))
	{
	  throw std::logic_error("Invalid element");
        }
      }
    }
    file >> std::ws;
    if (!file.eof())
    {
      throw std::logic_error("Extra nums");
    }
    file.close();

    int result = pechnikov::count(data, row, column);
    if (argv[1][0] == '2')
    {
      delete[] data;
    }
    std::ofstream fileo(argv[3]);
    if (!fileo)
    {
      throw std::runtime_error("Error open file");
    }
    fileo << result << "\n";
    fileo.close();
    return 0;
  }
  catch (const std::runtime_error &err)
  {
    if (argv[1][0] == '2')
    {
      delete[] data;
    }
    std::cerr << err.what() << "\n";
    return 1;
  }
  catch (const std::logic_error &err)
  {
    if (argv[1][0] == '2')
    {
      delete[] data;
    }
    std::cerr << err.what() << "\n";
    return 2;
  }
}

int pechnikov::count(int* data, int row, int column)
{
  int* minrow = new int[row];
  int* maxcolumn = new int[column];
  int** arr = new int* [row];
  for (int i = 0; i < row; i++)
  {
    arr[i] = new int[column];
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      arr[i][j] = data[i * column + j];
    }
  }
  for (int i = 0; i < row; i++)
  {
    minrow[i] = arr[i][0];
  }
  for (int i = 0; i < column; i++)
  {
    maxcolumn[i] = arr[0][i];
  }

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      if (arr[i][j] < minrow[i])
      {
        minrow[i] = arr[i][j];
      }
    }
  }
  for (int i = 0; i < column; i++)
  {
    for (int j = 0; j < row; j++)
    {
      if (arr[j][i] > maxcolumn[i])
      {
        maxcolumn[i] = arr[j][i];
      }
    }
  }	
  int k = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      if (arr[i][j] == minrow[i] && arr[i][j] == maxcolumn[j])
      {
        k += 1;
      }
    }
  }
  for (int i = 0; i < row; ++i)
  {
    delete[] arr[i];
  }
  delete[] arr;
  arr = nullptr;
  delete[] minrow;
  minrow = nullptr;
  delete[] maxcolumn;
  maxcolumn = nullptr;
  return k;
}
