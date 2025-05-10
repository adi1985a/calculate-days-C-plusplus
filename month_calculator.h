#ifndef MONTH_CALCULATOR_H
#define MONTH_CALCULATOR_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class MonthCalculator {
private:
    struct Calculation {
        int month;
        int year;
        int days;
        std::string timestamp;
    };
    
    void logCalculation(int month, int year, int days);
    bool isLeapYear(int year);
    void writeToFile(const Calculation& calc);
    std::string getCurrentTimestamp();
    
public:
    void calculateDays();
    void showHistory();
    void showAbout();
};

#endif
