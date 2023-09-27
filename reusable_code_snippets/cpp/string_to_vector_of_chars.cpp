//Converts string to vector of characters
//Tried converting to array of characters, but array can't be initialized with size() of string as it is not a constexpr function

#include <vector>
#include <iostream>

int main()
{
    std::string const str = "Hello World!";

    // Create vector with size
    std::vector<char> list(str.size());

    std::copy(str.begin(), str.end(), list.begin());

    for(auto const& s : list)
    {
        std::cout << s;
    }
}