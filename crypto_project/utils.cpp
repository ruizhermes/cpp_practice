#include <iostream>
#include <limits>

void printMenu()
{
    std::cout << std::endl;
    std::cout << "1. Print Help " << std::endl;
    std::cout << "2. Print exchange stats " << std::endl;
    std::cout << "3. Make an Offer " << std::endl;
    std::cout << "4. Make a bit " << std::endl;
    std::cout << "5. Print Wallet " << std::endl;
    std::cout << "6. Continue " << std::endl;
}

int getUserOption()
{
    int userOption;
    std::cout << "Choose an option 1-6 " << std::endl;
    std::cin >> userOption;


    if (std::cin.fail() || std::cin.peek() != '\n')
    {
      
        // Clear the error state and ignore the remaining characters in the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // return getUserOption(); // Prompt for input again
        userOption = 0;
    }

    if (userOption > 6 || userOption < 0)
    {
        userOption = 0;
    }


    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}


void printHelp()
{
    std::cout << "Help is to Make Money " << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks promissing today" << std::endl;
}

void enterOffer()
{
    std::cout << "Offer is okay " << std::endl; 
}

void enterBid()
{
    std::cout << "Your bid is too low " << std::endl;
}

void printWallet()
{
    std::cout << "Your Balance is : 0.00" << std::endl;
}

void gotoNextTimeFrame()
{
    std::cout << "Looking into the Next Frame " << std::endl;
}


void processUserOption(int userOption)
{
    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeFrame();
    }
    
}