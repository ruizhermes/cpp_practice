#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
    private:
        // static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
        

    public:
        CSVReader();

        /**
            this function will not rely on anything else having been created beforehand. 
            The idea is there's no statefulness to the CSV reader, this function should maintain 
            any state that it needs locally. So that means I can make it into a static function, 
            and so that means that we can call it without needing to create an instance of the CSV 
            reader before hand. We just say, CSV reader read the file and that's it. Otherwise, if 
            it's not static, we have to create instances of it.
        */
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringsToOBE(std::string price,
                                           std::string amount,
                                           std::string timestamp,
                                           std::string product,
                                           OrderBookType OrderBookType);
};