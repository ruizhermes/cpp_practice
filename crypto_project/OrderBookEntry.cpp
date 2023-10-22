#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry()
{
    price_ = 0.0;
    amount_ = 0.0;
    timestamp_ = "";
    product_ = "";
    orderType_ = OrderBookType::ask;
}

OrderBookEntry::OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType orderType):
price_(price),
amount_(amount),
timestamp_(timestamp),
product_(product),
orderType_(orderType)
{
}


OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if (s == "ask")
    {
        return OrderBookType::ask;
    }

    if (s == "bid")
    {
        return OrderBookType::bid;
    }

    return OrderBookType::unknown;
}