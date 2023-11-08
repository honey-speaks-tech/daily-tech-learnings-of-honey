// Simple test program to check string is empty.

#include <string>
#include <string_view>
#include <iostream>

static inline std::string extractFilename(std::string_view file_path)
{
    static std::string local_filename;
    if (!local_filename.empty()) 
    {
        return local_filename;
    }
    return "NON_EMPTY";
}

int main()
{
    std::cout << extractFilename("/home/honey");
    return 0;
}