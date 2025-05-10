#include "month_calculator.h"
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <fstream>

void MonthCalculator::calculateDays() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "**** Calculate Days in Month ****\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    
    int month, year;
    
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    
    if (month < 1 || month > 12) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "Invalid month!\n";
        return;
    }
    
    int days;
    if (month == 2) {
        std::cout << "Enter year: ";
        std::cin >> year;
        days = isLeapYear(year) ? 29 : 28;
    } else {
        days = (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
        year = 0;
    }
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    std::cout << "\nResult: Month " << month << " has " << days << " days\n";
    
    logCalculation(month, year, days);
}

bool MonthCalculator::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void MonthCalculator::logCalculation(int month, int year, int days) {
    Calculation calc{month, year, days, getCurrentTimestamp()};
    writeToFile(calc);
}

std::string MonthCalculator::getCurrentTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

void MonthCalculator::writeToFile(const Calculation& calc) {
    std::ofstream file("calculations_history.txt", std::ios::app);
    if (file.is_open()) {
        file << "Date: " << calc.timestamp << " | Month: " << calc.month 
             << " | Year: " << (calc.year ? std::to_string(calc.year) : "N/A")
             << " | Days: " << calc.days << "\n";
        file.close();
    }
}

void MonthCalculator::showHistory() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "**** Calculation History ****\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    std::ifstream file("calculations_history.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cout << "No calculation history available.\n";
    }
}

void MonthCalculator::showAbout() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "**** About Program ****\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "This program calculates the number of days in any month\n";
    std::cout << "and takes into account leap years for February.\n\n";
    std::cout << "Features:\n";
    std::cout << "- Accurate day calculation\n";
    std::cout << "- Leap year detection\n";
    std::cout << "- History tracking\n";
    std::cout << "- User-friendly interface\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
