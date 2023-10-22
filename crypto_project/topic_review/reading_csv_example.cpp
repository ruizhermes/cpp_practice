#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::string token;


    signed int start, end;

    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end)
        {
            break;
        }

        if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        tokens.push_back(token);

        start = end + 1;

    }while(end != std::string::npos);


    return tokens;
}

int main()
{


    std::ifstream csvFile{"crypto_order_book_course_03.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {
        std::cout << "FILE OPEN " << std::endl;

        
       while(std::getline(csvFile, line))
       {
            std::cout << "Line: " << line << std::endl;

            tokens = tokenise(line, ',');
            std::cout << "Size: " << tokens.size() << std::endl;

            if (tokens.size() != 5)
            {
                std::cout << "BAD LINE" << std::endl;
                continue;
            }
            double price;
            double amount;
            try{

                double price  = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << " " << amount << std::endl;
            }
            catch(std::exception e)
            {
                std::cout << "Bad Line" << std::endl;
                std::cout << price << " " << amount << std::endl;
              
            }

            

       }
        
        csvFile.close();
    }
    else
    {
        std::cout << "FILE NOT OPEN" << std::endl;
    }


    return 0;
}