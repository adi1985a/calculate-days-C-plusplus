# 📅🗓️ DaysInMonth Pro: Your Calendar Companion ⏳
_A C++ console application for accurately calculating the number of days in a given month, leap year checks, and history tracking._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows (Full) / Cross-platform (Basic)](https://img.shields.io/badge/Platform-Windows%20%7C%20Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Project Description](#-project-description)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Running](#️-installation-and-running)
6.  [How to Use](#️-how-to-use)
7.  [Technical Details & Program Logic](#-technical-details--program-logic)
8.  [Contributing](#-contributing)
9.  [Author](#️-author)
10. [License](#-license)

## 📝 Project Description

**DaysInMonth Pro** is a practical C++ console application designed to provide quick and accurate information about the number of days in any given month and year. It correctly identifies leap years to ensure precise calculations for February. The application features a user-friendly, colorful interface (enhanced on Windows), maintains a history of calculations that can be saved to and viewed from `calculations.txt`, and includes cross-platform considerations for basic keypress handling. It's a handy utility for anyone needing quick calendar-related information.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🗓️ **Days in Month Calculation**: Accurately determines the number of days for any specified month and year.
*   ✅ **Leap Year Detection**: Correctly identifies whether a given year is a leap year, crucial for February calculations.
*   💾 **Calculation History**:
    *   Saves a log of each calculation (input month/year and result) to `calculations.txt`.
    *   Allows users to view the previously saved calculation history.
*   ℹ️ **Program Information**: Displays basic information about the application.
*   🌈 **Colorful Console Interface**: Provides an enhanced visual experience with colored text, especially on Windows.
*   ⌨️ **Cross-Platform Keypress (Basic)**: Implements basic non-buffered keypress handling using `conio.h` on Windows and attempts alternatives like `termios.h` on other systems for "press any key" prompts.
*   📋 **Menu-Driven Operation**: Simple and intuitive menu for easy navigation.

## 🖼️ Screenshots

_Screenshots showcasing the main menu, input prompts for month/year, calculation results, history view, and the program information screen._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**:
    *   **Windows**: Recommended for full functionality, including enhanced console colors and specific keypress handling (via `windows.h`, `conio.h`).
    *   **Linux/macOS**: Basic functionality with alternative keypress handling (may require `termios.h`, `unistd.h`). Color support might be limited to standard ANSI escape codes if implemented.
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`month_calculator.h` Header File (User-Provided)**: This project **critically requires** a header file named `month_calculator.h`. **This file is not included in the repository and must be created by the user.** It should define a `MonthCalculator` class (or equivalent structure/namespace) containing the core logic. See the "Installation and Running" section for more details.
*   **Optional File**: `calculations.txt` will be created/used by the program to store calculation history.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `month_calculator.h`**:
    Before compiling, you **must** create a file named `month_calculator.h` in the project's root directory. This file should define the `MonthCalculator` class and its methods. Here's an illustrative example:
    ```cpp
    #ifndef MONTH_CALCULATOR_H
    #define MONTH_CALCULATOR_H

    #include <string>
    #include <vector>   // For storing history
    #include <fstream>  // For file I/O
    #include <iostream> // For display within methods if needed

    // Potentially include utility headers for color/keypress if not in main
    // #ifdef _WIN32
    // #include <windows.h>
    // #include <conio.h>
    // #else
    // #include <termios.h>
    // #include <unistd.h>
    // #endif

    class MonthCalculator {
    private:
        std::string historyFilePath = "calculations.txt";
        std::vector<std::string> calculationHistory; // To hold history in memory

        bool isLeapYear(int year) const;
        void loadHistoryFromFile(); // Called by constructor or explicitly
        void saveHistoryToFile() const; // Called on exit or after each calculation

    public:
        MonthCalculator(); // Constructor might load history
        ~MonthCalculator(); // Destructor might save history

        int calculateDays(int month, int year); // Returns days, logs to history
        void showHistory() const;
        void showAbout() const;

        // Helper for colors (might be better in a separate utils.h)
        // void setColor(int colorCode);
    };

    #endif // MONTH_CALCULATOR_H
    ```
    *This is an **example**. You must implement the class methods (e.g., `calculateDays`, `isLeapYear`, `showHistory`, file operations) in a corresponding `month_calculator.cpp` file. The color and cross-platform keypress logic might be part of this class, a separate utility file, or directly in `main.cpp`.*

4.  **Compile the Program**:
    Open a terminal in the project directory.
    **Example using g++ (MinGW for Windows, or standard g++ on Linux/macOS):**
    ```bash
    g++ main.cpp month_calculator.cpp -o month_calculator -static-libgcc -static-libstdc++
    ```
    *(This assumes you have `month_calculator.cpp` for implementations. Adjust the command based on your compiler and OS. For instance, on Linux, you might not need `-static-libgcc -static-libstdc++` or might link other libraries if `termios.h` is used extensively).*

5.  **Run the Application**:
    After successful compilation, execute the generated program:
    *   On Windows: `.\month_calculator.exe` or `month_calculator.exe`
    *   On Linux/macOS: `./month_calculator`

## ▶️ How to Use

Upon launching **DaysInMonth Pro**, you will be presented with a main menu:

1.  **Calculate days in a month**:
    *   Prompts you to enter the **month** (e.g., 1-12) and the **year**.
    *   The program will calculate and display the number of days in that specific month, considering if the year is a leap year.
    *   This calculation will be added to the history.
2.  **View calculation history**:
    *   Displays all previously performed calculations that have been saved to `calculations.txt`.
3.  **View program information**:
    *   Shows basic details about the application, its purpose, and possibly the author.
4.  **Exit**:
    *   Saves the current calculation history (if any new entries) and terminates the application.

## 💡 Technical Details & Program Logic

*   **`MonthCalculator` Class (in `month_calculator.h`)**: This class encapsulates the core logic:
    *   `isLeapYear(int year)`: Implements the rules for determining a leap year (divisible by 4, unless divisible by 100 but not by 400).
    *   `calculateDays(int month, int year)`: Uses `isLeapYear` and a lookup (e.g., array or switch statement) for the number of days in each month.
    *   File I/O methods for loading and saving `calculationHistory` to `calculations.txt`.
*   **Date Logic**: Standard calendar rules are applied for days in months and leap year conditions.
*   **History Management**: Calculations are stored, likely as strings, in a `std::vector` in memory and periodically synchronized with `calculations.txt`.
*   **Cross-Platform Keypress**:
    *   **Windows**: Uses `_getch()` from `conio.h` for "press any key" prompts.
    *   **Linux/macOS**: May use `termios.h` and `unistd.h` to achieve similar non-buffered input, or fall back to simpler `std::cin.get()`. This can be complex to make truly robust across all terminals.
*   **Console Colors**:
    *   **Windows**: Likely uses `SetConsoleTextAttribute` from `windows.h`.
    *   **Linux/macOS**: Might use ANSI escape codes for basic color support if implemented.

## 🤝 Contributing

Contributions to **DaysInMonth Pro** are welcome! If you have ideas for features like displaying a full month calendar, adding internationalization for month names, improving the cross-platform support, or enhancing the UI:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-calendar-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your calendar enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-calendar-enhancement`
5.  Open a Pull Request.

Please ensure your code is well-commented and aligns with the project's existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Utility Software Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🌍 _Making time-telling simple, one month at a time._
