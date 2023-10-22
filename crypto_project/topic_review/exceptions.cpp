#include <iostream>
#include <string>

int main()
{
    double d; 
    std::string s1 = "aaaadas";

    try
    {
        d = std::stod(s1);
        std::cout << "d: " << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}