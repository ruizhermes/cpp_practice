#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelApp.h"
#include "CSVReader.h"



int main()
{

    MerkelApp app{};
    app.init();

    // CSVReader::readCSV("crypto_order_book_course_03.csv");

    return 0;
}