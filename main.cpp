#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "month_calculator.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayHeader() {
    system("cls");
    setConsoleColor(14); // Yellow
    std::cout << "****************************************************\n";
    std::cout << "*           Number of Days in a Month              *\n";
    std::cout << "*           Created by: Adrian Lesniak            *\n";
    std::cout << "****************************************************\n\n";
    
    setConsoleColor(11); // Light Cyan
    std::cout << "Program features:\n";
    std::cout << "1. Calculate days in any month\n";
    std::cout << "2. Check for leap years\n";
    std::cout << "3. Save calculations to history\n";
    std::cout << "4. View calculation history\n\n";
    
    setConsoleColor(7); // White
}

void displayMenu() {
    std::cout << "+------------------MENU------------------+\n";
    std::cout << "| 1. Calculate days in month            |\n";
    std::cout << "| 2. View calculation history           |\n";
    std::cout << "| 3. About program                      |\n";
    std::cout << "| 4. Exit                              |\n";
    std::cout << "+---------------------------------------+\n";
}

int main() {
    MonthCalculator calculator;
    char choice;
    
    do {
        displayHeader();
        displayMenu();
        
        std::cout << "\nSelect option: ";
        std::cin >> choice;
        
        switch(choice) {
            case '1':
                calculator.calculateDays();
                break;
            case '2':
                calculator.showHistory();
                break;
            case '3':
                calculator.showAbout();
                break;
            case '4':
                setConsoleColor(14);
                std::cout << "\nThank you for using the program!\n";
                return 0;
            default:
                setConsoleColor(12);
                std::cout << "\nInvalid option!\n";
        }
        
        setConsoleColor(7);
        std::cout << "\nPress any key to continue...";
        #ifdef _WIN32
            _getch();
        #else
            std::cin.ignore().get();
        #endif
        
    } while (true);
    
    return 0;
}
