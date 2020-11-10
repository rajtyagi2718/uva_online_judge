#include <iostream>  // cout cin endl
#include <limits>  // numeric_limits

int main()
{
  // read set up
  int people, budget, hotels, weeks;
  std::cin >> people >> budget >> hotels >> weeks;

  // read price, availability
  int mincost = std::numeric_limits<int>::max();
  int price, beds;
  int cost;
  bool fits;
  while (hotels)
  {
    std::cin >> price;
    cost = people * price;
    if (cost >= mincost)
    {
      // clear beds buffer
      std::cin.ignore(1000, '\n');
      continue;
    }
    
    fits = false; 
    int i = 0; 
    while (i < weeks)
    {
      std::cin >> beds;
      if (beds >= people)
      {
        fits = true;
        break;
      }
      ++i;
    }
    if (i < weeks)
    {
      // clear beds buffer
      std::cin.ignore(1000, '\n');
    }  
    if (fits && cost < mincost)
    {
      mincost = cost;
    }
    --hotels;
  }
  if (mincost < budget)
  {
    std::cout << mincost << std::endl;
  }
  else
  {
    std::cout << "stay home" << std::endl;
  }
     
  return 0;
}
