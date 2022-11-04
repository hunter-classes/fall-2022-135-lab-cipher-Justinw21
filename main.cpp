#include <iostream>
#include "funcs.h"
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  std::string strings = "Douglas figured the best way to succeed was to do the opposite of what he'd been doing all his life.";
  std::string encryptedString = encryptCaesar(strings,10);
  std::cout << encryptedString << std::endl << std::endl;
  encryptedString = solve(encryptedString);
  std::cout << strings << "\n";
  return 0;
  
}
