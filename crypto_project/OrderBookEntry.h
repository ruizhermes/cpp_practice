#pragma once 

#include <iostream>
#include <string>
enum class OrderBookType{bid, ask, unknown, sale};

class OrderBookEntry
{
    public:
        double price_;
        double amount_;
        std::string timestamp_;
        std::string product_;
        OrderBookType orderType_;

    public:
        OrderBookEntry();
        OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType orderType);

        static OrderBookType stringToOrderBookType(std::string s); 
        static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.timestamp_ < e2.timestamp_;
        }
       
       static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.price_ < e2.price_;
        }

        static bool compareByPriceDes(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.price_ > e2.price_;
        }

};
