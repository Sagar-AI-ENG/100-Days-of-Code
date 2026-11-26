# Personal Expense Tracker (C)

A simple, menu-driven command-line application written in C to record, manage, and analyze personal expenses.

## Features

- **Add Expense:** Record new expenses with a category, description, and amount (in Rs.).
- **View All Expenses:** Display all recorded expenses in a formatted table with auto-generated IDs.
- **Calculate Total Expense:** View the sum of all recorded expenses.
- **Search by Category:** Filter and view expenses belonging to a specific category.
- **Find Highest Expense:** Quickly identify your single largest expense.
- **Budget Management:** Set a monthly budget and check your remaining balance or overspending status.
- **Delete Expense:** Remove an expense by its ID (automatically re-indexes remaining IDs).
- **Category-wise Summary:** View total spending grouped by each unique category.

## Prerequisites

To compile and run this program, you need a C compiler such as **GCC** (GNU Compiler Collection) installed on your system.

## Getting Started

### 1. Clone the repository
```bash
git clone https://github.com
cd personal-expense-tracker
```

### 2. Compile the code
Assuming your source file is named `expense_tracker.c`:
```bash
gcc expense_tracker.c -o expense_tracker
```

### 3. Run the application
- **On Linux / macOS:**
  ```bash
  ./expense_tracker
  ```
- **On Windows:**
  ```cmd
  expense_tracker.exe
  ```

## Usage

Once running, select an option from the menu by entering the corresponding number (`1` to `10`):

```text
=================================
 PERSONAL EXPENSE TRACKER
=================================
1. Add Expense
2. View All Expenses
3. Calculate Total Expense
4. Search Expense by Category
5. Find Highest Expense
6. Set Monthly Budget
7. Check Budget Status
8. Delete Expense
9. Category-wise Summary
10. Exit
```

## Limitations & Future Improvements

- **In-Memory Storage:** Expenses are stored in an array (up to `100` entries) and are cleared when the program exits.
- **Planned Enhancements:**
  - Add file handling (`fopen`, `fwrite`, `fread`) to save expenses permanently.
  - Add case-insensitive category matching.
  - Export summaries to a CSV file.
