#include <iostream>  // cin, cout, endl;

int main()
{
  int tests;
  std::cin >> tests;
  int test = 1;
  int num, speed;
  int maxspeed;
  for (int test = 1; test <= tests; ++test)
  {
    maxspeed = -1;
    std::cin >> num;
    while (num)
    {
      std::cin >> speed;
      if (speed > maxspeed)
      {
        maxspeed = speed;
      }
      --num;
    }
    std::cout << "Case " << test << ": " << maxspeed << std::endl;
  } 

  return 0;
}
