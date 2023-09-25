/// Generic function template for logging
#include <iostream>
#include <fmt/core.h>
#include <exception>

template <typename Exception>
void logException(Exception const& e, std::string str)
{
    std::cout << str;
    throw Exception(e);        
}

int main()
{

    try
    {
        //This line is just for testing if it works
        throw std::runtime_error("");
    }

    catch(const std::runtime_error& e)
    {
        logException(e, fmt::format("std::runtime_error {}", e.what()));
    }

    catch(const std::out_of_range& e)
    {
        logException(e, fmt::format("std::out_of_range {}", e.what()));
    }

    catch(...)
    {
        std::cout << fmt::format("Unknown exception");
    }

    return 0;

}