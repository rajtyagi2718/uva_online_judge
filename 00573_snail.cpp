#include <iostream>

int climb(int goal, int up, int down, double fatigue)
{
  fatigue = up * fatigue / 100;
  double height = 0;
  int day = 0;
  double cur = up + fatigue;

  while (true)
  {
    day += 1;
    cur -= fatigue;
    std::cout << "\tday " << day << "\theight " << height << std::endl;

    // top
    if (height + cur > goal) 
    {
      std::cout << "\tsuccess " << height + cur << std::endl;
      return day;
    }

    // rest
    if (height - down > 0 && cur + cur - fatigue < up)
    {
      height -= down;
      cur = up + fatigue;
      std::cout << "\trest " << height << std::endl;
      continue;
    }
    
    height += cur - down;

    // bottom
    if (height < 0)
    {
      std::cout << "\tfailure " << height << std::endl;
      return -day;
    }
  }
}

int main()
{
  int height, up, down, fatigue;
  int result;

  while (true)
  {
    std::cin >> height >> up >> down >> fatigue;
    if (height == 0)
    {
      break;
    } 

    result = climb(height, up, down, fatigue); 
    if (result > 0)
    {
      std::cout << "success on day " << result << std::endl;
    }
    else
    {
      std::cout << "failure on day " << -result << std::endl;
    }
  }

  return 0;
}
