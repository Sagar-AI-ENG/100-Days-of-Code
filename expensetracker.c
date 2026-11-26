#include <stdio.h>
#include <string.h>

#define MAX 100

struct Expense {
    int id;
    char category[30];
    char description[100];
    float amount;
};

void addExpense(struct Expense *e, int *count);
void viewExpenses(struct Expense e[], int count);
void totalExpense(struct Expense e[], int count);
void searchExpense(struct Expense e[], int count);
void highestExpense(struct Expense e[], int count);
void checkBudget(struct Expense e[], int count, float budget);
void deleteExpense(struct Expense e[], int *count);
void categorySummary(struct Expense e[], int count);

int main() {
    struct Expense expenses[MAX];
    int count = 0, choice;
    float budget = 0;

    do {
        printf("\n=================================\n");
        printf("      PERSONAL EXPENSE TRACKER\n");
        printf("=================================\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Search Expense by Category\n");
        printf("5. Find Highest Expense\n");
        printf("6. Set Monthly Budget\n");
        printf("7. Check Budget Status\n");
        printf("8. Delete Expense\n");
        printf("9. Category-wise Summary\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;

            case 2:
                viewExpenses(expenses, count);
                break;

            case 3:
                totalExpense(expenses, count);
                break;

            case 4:
                searchExpense(expenses, count);
                break;

            case 5:
                highestExpense(expenses, count);
                break;

            case 6:
                printf("Enter monthly budget: Rs. ");
                scanf("%f", &budget);

                if (budget > 0)
                    printf("Budget set successfully!\n");
                else {
                    budget = 0;
                    printf("Invalid budget!\n");
                }
                break;

            case 7:
                checkBudget(expenses, count, budget);
                break;

            case 8:
                deleteExpense(expenses, &count);
                break;

            case 9:
                categorySummary(expenses, count);
                break;

            case 10:
                printf("Thank you for using Expense Tracker!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 10);

    return 0;
}

void addExpense(struct Expense *e, int *count) {
    if (*count >= MAX) {
        printf("Expense storage is full!\n");
        return;
    }

    struct Expense *p = e + *count;

    p->id = *count + 1;

    printf("Enter category: ");
    scanf(" %29[^\n]", p->category);

    printf("Enter description: ");
    scanf(" %99[^\n]", p->description);

    printf("Enter amount: Rs. ");
    scanf("%f", &p->amount);

    if (p->amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    (*count)++;

    printf("Expense added successfully!\n");
}

void viewExpenses(struct Expense e[], int count) {
    if (count == 0) {
        printf("No expenses recorded!\n");
        return;
    }

    printf("\n%-5s %-20s %-25s %-10s\n",
           "ID", "Category", "Description", "Amount");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-25s Rs.%.2f\n",
               e[i].id, e[i].category,
               e[i].description, e[i].amount);
    }
}

void totalExpense(struct Expense e[], int count) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += e[i].amount;
    }

    printf("Total Expense = Rs. %.2f\n", total);
}

void searchExpense(struct Expense e[], int count) {
    char category[30];
    int found = 0;

    printf("Enter category to search: ");
    scanf(" %29[^\n]", category);

    for (int i = 0; i < count; i++) {
        if (strcmp(e[i].category, category) == 0) {
            printf("ID: %d | %s | Rs. %.2f\n",
                   e[i].id, e[i].description,
                   e[i].amount);
            found = 1;
        }
    }

    if (!found)
        printf("No expenses found!\n");
}

void highestExpense(struct Expense e[], int count) {
    if (count == 0) {
        printf("No expenses available!\n");
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < count; i++) {
        if (e[i].amount > e[maxIndex].amount) {
            maxIndex = i;
        }
    }

    printf("\nHighest Expense:\n");
    printf("Category: %s\n", e[maxIndex].category);
    printf("Description: %s\n", e[maxIndex].description);
    printf("Amount: Rs. %.2f\n", e[maxIndex].amount);
}

void checkBudget(struct Expense e[],
                 int count, float budget) {
    float total = 0;

    if (budget <= 0) {
        printf("Please set your budget first!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        total += e[i].amount;
    }

    printf("Monthly Budget: Rs. %.2f\n", budget);
    printf("Total Spent: Rs. %.2f\n", total);

    if (total > budget) {
        printf("WARNING! Budget exceeded by Rs. %.2f\n",
               total - budget);
    }
    else if (total == budget) {
        printf("You have used your entire budget!\n");
    }
    else {
        printf("Remaining Budget: Rs. %.2f\n",
               budget - total);
    }
}

void deleteExpense(struct Expense e[], int *count) {
    int id, index = -1;

    printf("Enter expense ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (e[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Expense not found!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        e[i] = e[i + 1];
    }

    (*count)--;

    for (int i = 0; i < *count; i++) {
        e[i].id = i + 1;
    }

    printf("Expense deleted successfully!\n");
}

void categorySummary(struct Expense e[], int count) {
    int visited[MAX] = {0};

    if (count == 0) {
        printf("No expenses available!\n");
        return;
    }

    printf("\nCATEGORY-WISE EXPENSE SUMMARY\n");

    for (int i = 0; i < count; i++) {
        if (visited[i])
            continue;

        float sum = 0;

        for (int j = i; j < count; j++) {
            if (strcmp(e[i].category,
                       e[j].category) == 0) {
                sum += e[j].amount;
                visited[j] = 1;
            }
        }

        printf("%s : Rs. %.2f\n",
               e[i].category, sum);
    }
}