#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Expense
{
public:
    string category;
    string description;
    double amount;

    Expense(string category, string description, double amount)
    {
        this->category = category;
        this->description = description;
        this->amount = amount;
    }
};

void addExpense(vector<Expense>& expenses)
{
    string category;
    string description;
    double amount;

    cout << "\nEnter category: ";
    cin >> category;

    cout << "Enter description: ";
    cin >> description;

    cout << "Enter amount: ";
    cin >> amount;

    Expense newExpense(category, description, amount);
    expenses.push_back(newExpense);

    cout << "Expense added successfully!\n";
}

void viewExpenses(const vector<Expense>& expenses)
{
    if (expenses.empty())
    {
        cout << "\nNo expenses recorded yet.\n";
        return;
    }

    cout << "\n--- Expenses ---\n";

    for (int i = 0; i < expenses.size(); i++)
    {
        cout << i + 1 << ". "
             << expenses[i].category << " | "
             << expenses[i].description << " | "
             << fixed << setprecision(2)
             << expenses[i].amount << "\n";
    }
}

void showTotal(const vector<Expense>& expenses)
{
    double total = 0;

    for (const Expense& expense : expenses)
    {
        total += expense.amount;
    }

    cout << "\nTotal spending: "
         << fixed << setprecision(2)
         << total << "\n";
}

int main()
{
    vector<Expense> expenses;

    int choice;

    do
    {
        cout << "\n===== Budget Manager =====\n";
        cout << "1. Add expense\n";
        cout << "2. View expenses\n";
        cout << "3. Show total spending\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addExpense(expenses);
                break;

            case 2:
                viewExpenses(expenses);
                break;

            case 3:
                showTotal(expenses);
                break;

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}