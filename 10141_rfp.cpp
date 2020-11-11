#include <iostream>  // count, cin, endl
#include <string>    // string
#include <limits>    // numeric_limits

int main()
{
  int reqs, props;
  int rfp = 1;
  std::string name;
  std::string bestname;
  double price, met;
  
  while (true)
  {
    // set default bounds
    double minprice = std::numeric_limits<double>::max();
    int maxmet = 0;

    // read in requirements and proposals
    std::cin >> reqs >> props;

    // end if '0 0'
    if (reqs == 0 && props == 0)
    {
      break;
    }

    // ignore requirement names
    for (int i=0; i < reqs; ++i)
    {
      std::cin.ignore(80, '\n'); 
    }

    for (int i = 0; i < props; ++i)
    {
      // read in proposal
      std::cin >> name >> price >> met;
      if (met > maxmet)
      {
        maxmet = met;
        minprice = price;
        bestname = name;
      }
      else if (met == maxmet && price < minprice)
      {
        minprice = price;
        bestname = name;
      } 

      // ignore met requirement names
      for (int j=0; j < met; ++j)
      {
        std::cin.ignore(80, '\n');
      }
    }

    // cout best proposal
    std::cout << "\nRFP #" << rfp << '\n' << bestname << std::endl;
    rfp += 1;
  }

  return 0;
}
