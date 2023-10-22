#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <algorithm>


OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;


    std::map<std::string, bool> prodMap;

    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product_] = true;
    }

    for (auto const& e : prodMap)
    {
        products.push_back(e.first);

    }
    
    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;

    for (OrderBookEntry& e : orders)
    {
        if (e.orderType_ == type &&
            e.product_   == product &&
            e.timestamp_ == timestamp)

            {
                orders_sub.push_back(e);
            }

    }

    return orders_sub;

}


double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price_;

    for (OrderBookEntry& e : orders)
    {
        if (e.price_ > max)
        {
            max = e.price_;
        }
    }

    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price_;

    for (OrderBookEntry& e : orders)
    {
        if (e.price_ < min)
        {
            min = e.price_;
        }
    }

    return min;
}

std::string OrderBook::getEarliestTime()
{
    // assumes the order book is ordered. So we return the first one
    // in this case. 
    return orders[0].timestamp_; 
}


std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";

    for(OrderBookEntry& e : orders)
    {
        if (e.timestamp_ > timestamp)
        {
            next_timestamp = e.timestamp_;
            break;
        }
    }

    if (next_timestamp == "")
    {
        next_timestamp = orders[0].timestamp_;
    }


    return next_timestamp;
}


void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);

    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp );
}

std::vector<OrderBookEntry> OrderBook:: matchAsksToBids(std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);

    std::vector<OrderBookEntry> sales;


    // Sort Asks and bids
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDes);

    for (OrderBookEntry& ask : asks)
    {

        for (OrderBookEntry& bid : bids)
        {

            if (bid.price_ >= ask.price_)
            {

                OrderBookEntry sale{ask.price_, 0, timestamp, product, OrderBookType::sale};
            

                if (bid.amount_ == ask.amount_)
                {
                    sale.amount_ = ask.amount_;
                    sales.push_back(sale);
                    bid.amount_ = 0;
                    break;

                }

                if (bid.amount_ > ask.amount_)
                {
                    sale.amount_ = ask.amount_;
                    sales.push_back(sale);
                    bid.amount_ = bid.amount_ - ask.amount_;
                    break;

                }

                if (bid.amount_ < ask.amount_)
                {
                    sale.amount_ = bid.amount_;
                    sales.push_back(sale);
                    ask.amount_ = ask.amount_ - bid.amount_;
                    bid.amount_ = 0;

                    continue;
                }
            }

        }

    }

    return sales;

}