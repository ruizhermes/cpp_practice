#include <iostream>
#include <vector>
#include "OrderBook.h"

int main()
{

    OrderBookEntry order1;

    std::vector<OrderBookEntry> orders;

    orders.push_back( OrderBookEntry{1000,
                                     0.03,
                                     "2020/03/17 17:01:24.884492",
                                     "BTC/USDT",
                                     OrderBookType::bid} );

    orders.push_back(OrderBookEntry{2000,
                                    0.05,
                                    "2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                    OrderBookType::bid});


    for (OrderBookEntry order : orders)
    {
        std::cout << "Price : " << order.price_ << std::endl;
    }
    // In this for loop, we are wasting memory. Basically it is copying the object into order 
    // and process on that copy. Instead use the following for loop

    for (OrderBookEntry& order: orders)
    {
        std::cout << "Price : " << order.price_ << std::endl;
    }
    // this is call by reference instead of by copying. Much better and efficient

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price : " << orders[i].price_ << std::endl;
    }

    // ++i is more efficient than i++ in the for loop.
    // i++ makes 2 operations than ++i
    //      1. It makes a copy of the data, increments the copy
    //      2. and assigns the copy back to i
    // ++i increments directly in place

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price : " << orders.at(i).price_ << std::endl;
    }

}