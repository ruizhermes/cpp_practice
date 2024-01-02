#include <iostream>
#include <limits>
#include "MerkelApp.h"
#include "CSVReader.h"


MerkelApp::MerkelApp()
{

}

void MerkelApp::init()
{

    int userInput;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

    while(true)
    {
        printMenu();
        userInput = getUserOption();
        processUserOption(userInput);
    }

}

// void MerkelApp::loadOrderBook()
// {
//     // orders = CSVReader::readCSV("crypto_order_book_course_03.csv");
// }

void MerkelApp::printMenu()
{
    std::cout << std::endl;
    std::cout << "1: Print Help"            << std::endl;
    std::cout << "2: Print exchange stats"  << std::endl;
    std::cout << "3: Make an offer"         << std::endl;
    std::cout << "4. Make a bid"            << std::endl;
    std::cout << "5. Print wallet"          << std::endl;
    std::cout << "6. Continue"              << std::endl;

    std::cout << std::endl;
    std::cout << "Current Time: " << currentTime << std::endl;
}

int MerkelApp::getUserOption()
{
    int userOption = 0; 
    std::string line;
    std::cout << "Select option above (1 - 6): ";
    std::getline(std::cin, line);

    try{
        userOption = std::stoi(line);
    }
    catch(const std::exception e)
    {
        std::cout << "MerkelApp::getUserOption " << std::endl << std::endl;
    }

    

    return userOption; 

}
void MerkelApp::processUserOption(int userOption)
{
    switch (userOption)
    {
    case 2:
        printMarketStats();
        break;

    case 3: 
        enterAsk();
        break;

    case 5:
        printWallet();
        break;

    case 6:
        gotoNextTimeFrame();
        break;
    
    default:
        std::cout << "Invalid Choice " << std::endl;
        break;
    }

}

void MerkelApp::printHelp()
{

}

void MerkelApp::printMarketStats()
{

    for (std::string const p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;

        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);

        std::cout << "Asks seen : " << entries.size() << std::endl;
        std::cout << "Max ask   : " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask   : " << OrderBook::getHighPrice(entries) << std::endl;

        std::cout << "-----------------------------------------" << std::endl;
    }

    // std::cout << std::endl;
}

void MerkelApp::enterAsk(){

    std::cout << "Make an ask - enter the amount: product,price, amount, eg: ETH/BTC,200,0.5 " << std::endl;
    
    std::string input;

    // This is used to clear the cin buffer that has the new line '\n' 
    // that was input by the user when entering the selection from the
    // menu

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);
    
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cout << "MerkelApp::enterAsk Bad input: " << input << std::endl << std::endl;
    }
    else
    {
        try{
        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                     tokens[2],
                                                     currentTime,
                                                     tokens[0],
                                                     OrderBookType::ask);

        
        orderBook.insertOrder(obe);

        }
        catch(const std::exception& e)
        {
            std::cout << "MerkelApp::enterAsk Bad input! " << std::endl << std::endl;
        }
    }

    std::cout << "Entered: " << input << std::endl;
    std::cout << "-----------------------------------------\n" << std::endl;


}

void MerkelApp::enterBid(){

}

void MerkelApp::printWallet(){

    std::cout << wallet.toString() << std::endl;

}

void MerkelApp::gotoNextTimeFrame(){

    currentTime = orderBook.getNextTime(currentTime);

}