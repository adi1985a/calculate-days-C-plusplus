# Number of Days in a Month Calculator

## Description
A C++ console application for calculating the number of days in a given month and checking for leap years. Features a colorful interface, calculation history, and cross-platform keypress handling. Created by Adrian Lesniak.

## Features
- Calculate days in any month
- Check for leap years
- Save calculations to `calculations.txt`
- View calculation history
- Display program information

## Requirements
- Windows OS (uses `windows.h` and `conio.h` for full functionality)
- C++ compiler (e.g., g++)
- `month_calculator.h` header file (not provided)
- Optional: `calculations.txt` for storing history

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `month_calculator.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o month_calculator
   ```

## Usage
1. Run the program:
   ```bash
   ./month_calculator
   ```
2. Choose options 1-4 from the menu:
   - 1: Calculate days in a month
   - 2: View calculation history
   - 3: View program information
   - 4: Exit

## Notes
- Calculation history is saved to `calculations.txt`.
- Non-Windows systems use alternative keypress handling (requires `termios.h` and `unistd.h`).
- Ensure `month_calculator.h` implements `MonthCalculator` class with `calculateDays()`, `showHistory()`, and `showAbout()` methods.

## Author
Adrian Lesniak

## License
MIT License