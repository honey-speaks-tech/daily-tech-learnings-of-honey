// Converts stringstream to string to raw char buffer
#include <sstream>
#include <string>
#include <iostream>

int main() {
  std::stringstream ss;
  ss << "Hello World";

  // Get the string from the stringstream
  std::string str = ss.str(); 

  // Get the c-string from the string
  const char* cstr = str.c_str();

  // Print out character buffer
  std::cout << cstr << std::endl;

  return 0;
}