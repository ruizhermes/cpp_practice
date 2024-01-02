#pragma once 

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelApp{

    public:
        MerkelApp();
        void init();
    
    private:

        // void loadOrderBook();
        void printMenu();
        int getUserOption();
        void processUserOption(int userOption);
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();

        std::string currentTime;

        OrderBook orderBook{"crypto_order_book.csv"};

        Wallet wallet;

        // std::vector<OrderBookEntry> orders;

};