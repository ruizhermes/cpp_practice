#include <iostream>

int main()
{
    enum class Colours {blue, green, red};

    Colours currentColor = Colours::blue;

    switch (currentColor)
    {
    case Colours::blue:
        std::cout << "BLUE" << std::endl;
        break;
    
    default:
        break;
    }

}