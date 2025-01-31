# Banking System Console Application

A simple console-based banking system that allows users to create accounts, log in, and perform basic financial transactions such as deposits, withdrawals, and money transfers.

## Features

- **Create Account**: Users can create a new account with a username, password, and initial balance.
- **Log In**: Existing users can log in using their credentials.
- **Transactions**:
    - **Deposit**: Add funds to the account.
    - **Withdraw**: Remove funds from the account.
    - **Send Money**: Transfer funds to another registered user.
- **Balance Tracking**: View the current account balance and transaction history.

## Technologies Used

- **C++**: Core programming language.
- **File I/O**: Stores account data (passwords, balances, transaction history) in text files.
- **Console I/O**: Menu-driven user interface.
- **Procedural Programming**: Uses functions and modular code structure.

## How to Run

### Prerequisites

- A C++ compiler (e.g., `g++` for Linux/macOS, or MinGW for Windows).
- Terminal/Command Prompt access.

### Steps

1. **Save the Code**:
    - Copy the code into a file named `banking_system.cpp`.
2. **Compile**:
    
    ```bash
    g++ banking_system.cpp -o banking_system
    
    ```
    
    (On Windows with MinGW, use `g++ banking_system.cpp -o banking_system.exe`.)
    
3. **Run**:
    
    ```bash
    ./banking_system      # Linux/macOS
    .\banking_system.exe    # Windows
    
    ```
    
4. **Follow On-Screen Instructions**:
    - Use numeric keys to navigate menus.
    - Accounts are stored in files like `logIn[username].txt` in the same directory.

## Notes

- **Data Storage**:
    - Account details (password, balance, transactions) are saved in `logIn[username].txt`.
    - All registered usernames are listed in `accaunts.txt`.
- **Security**:
    - Passwords and balances are stored in plaintext (not secure for real-world use).
- **OS Compatibility**:
    - Uses `system("cls")` to clear the screen, which is Windows-specific. Replace with `system("clear")` for Linux/macOS if needed.

## Limitations

- No input validation for non-numeric entries (e.g., entering text instead of numbers may crash the program).
- Minimal error handling for edge cases (e.g., negative balances).
- Basic UI with limited formatting.

## Example Workflow

1. **Create Account**:
    - Choose **Option 2** from the main menu.
    - Enter a username, password, and initial balance.
2. **Log In**:
    - Choose **Option 1** from the main menu.
    - Enter your username and password.
3. **Perform Transactions**:
    - Select **Deposit**, **Withdraw**, or **Send to** from the account menu.
    - Follow prompts to complete the action.
4. **Exit**:
    - Choose **Option 4** to log out and return to the main menu.
