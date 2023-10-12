/// Extracts file name from file path
#include <iostream>
#include <string_view>


static std::string extractFilename(std::string_view file_path)
{
    const size_t slash_index{file_path.find_last_of("/\\")};
    if (slash_index != std::string::npos)
    {
        constexpr size_t slash_char_length{1};
        return std::string{file_path.substr(slash_index + slash_char_length)};
    }  
    return std::string{file_path};
}

int main()
{
    auto file{extractFilename("C:/Honey/sample.cpp")};
    std::cout<<file;
    return 0;
}