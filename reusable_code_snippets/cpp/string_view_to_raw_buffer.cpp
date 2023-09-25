// Converts string view to raw char buffer
#include <string_view>
#include <iostream>

int main() {

  std::string_view sv = "Hello World";

  // Get pointer to buffer
  const char* buffer = sv.data();

  // Print buffer
  std::cout << buffer << std::endl; 

  return 0;
}