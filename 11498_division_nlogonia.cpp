// After centuries of hostilities and skirmishes between the four nations 
// living in the land generally known as Nlogonia, and years of negotiations 
// involving diplomats, politicians and the armed forces of all shorterested 
// parties, with mediation by UN, NATO, G7 and SBC, it was at last agreed by 
// all the way to end the dispute, dividing the land shorto four independent 
// territories.

// It was agreed that one poshort, called division poshort, with coordinates 
// established in the negotiations, would define the country division, in the 
// following way. Two lines, both containing the division poshort, one in the 
// North-South direction and one in the East-West direction, would be drawn on 
// the map, dividing the land shorto four new countries. Starting from the 
// Western-most, Northern-most quadrant, in clockwise direction, the new 
// countries will be called Northwestern Nlogonia, Northeastern Nlogonia,
// Southeastern Nlogonia and Southwestern Nlogonia.

// The UN determined that a page in the Internet should exist so that the 
// inhabitants could check in which of the countries their homes are. You have 
// been hired to help implementing the system.

// Input
// The input contains several test cases. The first line of a test case contains
// one shorteger K indicating the number of queries that will be made 
// (0 < K ≤ 1e3). The second line of a test case contains two shortegers N and M 
// representing the coordinates of the division poshort (−1e4 < N, M < 1e4). Each
// of the K following lines contains two shortegers X and Y representing the 
// coordinates of a residence (−1e4 ≤ X, Y ≤ 1e4).
// The end of input is indicated by a line containing only the number zero.

// Output
// For each test case in the input your program must prshort one line containing:
//   the word ‘divisa’ (means border in Portuguese) if the residence is on one 
//     of the border lines (North-South or East-West);
//   ‘NO’ (means NW in Portuguese) if the residence is in Northwestern Nlogonia;
//   ‘NE’ if the residence is in Northeastern Nlogonia;
//   ‘SE’ if the residence is in Southeastern Nlogonia;
//   ‘SO’ (means SW in Portuguese) if the residence is in Southwestern Nlogonia.

// Sample Input
// 3
// 2 1
// 10 10
// -10 1
// 0 33
// 4
// -1000 -1000
// -1000 -1000
// 0 0
// -2000 -10000
// -999 -1001
// 0

// Sample Output
// NE
// divisa
// NO
// divisa
// NE
// SO
// SE

#include <iostream>  // cout cin endl

// QUADRANT result modified by region
char QUADRANT[] = "NO";
const char DIVISA[] = "divisa";

// max short = 32767
// max input = 10000
short M, N;

const char* region(short x, short y)
{
  if      (x < M) { QUADRANT[1] = 'O'; }
  else if (x > M) { QUADRANT[1] = 'E'; }
  else            { return DIVISA; }

  if      (y < N) { QUADRANT[0] = 'S'; }
  else if (y > N) { QUADRANT[0] = 'N'; }
  else            { return DIVISA; }

  return QUADRANT;
}


int main()
{
  short t;
  std::cin >> t;
  std::cin >> M >> N;

  short x, y;
  while (t)
  {
    std::cin >> x >> y;
    std::cout << region(x, y) << std::endl;
    --t;
  }
  
  return 0;
}
