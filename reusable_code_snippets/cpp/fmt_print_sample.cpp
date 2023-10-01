// Prints using fmt library
#include <vector>
#include <fmt/format.h>

int main () {
fmt::print("some text\n");
fmt::print("A {} B\n", "and");
fmt::print("--------------------\n");
std::string w = "or";
fmt::print("A {} B\n", w);
fmt::print("--------------------\n");
fmt::print("A{x}B{x}C\n", fmt::arg("x",w));
fmt::print("--------------------\n");
std::vector<char> v {'a','b','c','\0'};
fmt::print("{}\n", v.data());
}