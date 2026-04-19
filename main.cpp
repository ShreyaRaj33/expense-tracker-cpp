#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Transaction {
    string description;
    float amount;
};

// Load data from file
void loadFromFile(vector<Transaction>& t) {
    ifstream file("data.txt");
    Transaction temp;

    while (file >> temp.description >> temp.amount) {
        t.push_back(temp);
    }

    file.close();
}

// Save data to file
void saveToFile(const vector<Transaction>& t) {
    ofstream file("data.txt");

    for (auto &x : t) {
        file << x.description << " " << x.amount << endl;
    }

    file.close();
}

// Add transaction
void addTransaction(vector<Transaction>& t) {
    Transaction temp;
    cout << "Enter description: ";
    cin >> temp.description;
    cout << "Enter amount (+income, -expense): ";
    cin >> temp.amount;

    t.push_back(temp);
    saveToFile(t);

    cout << "Transaction added successfully!\n";
}

// Show transactions
void showTransactions(const vector<Transaction>& t) {
    cout << "\n--- Transactions ---\n";

    for (int i = 0; i < t.size(); i++) {
        cout << i + 1 << ". " << t[i].description 
             << " : " << t[i].amount << endl;
    }
}

// Delete transaction
void deleteTransaction(vector<Transaction>& t) {
    int index;
    cout << "Enter transaction number to delete: ";
    cin >> index;

    if (index > 0 && index <= t.size()) {
        t.erase(t.begin() + index - 1);
        saveToFile(t);
        cout << "Deleted successfully!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// Calculate balance
float getBalance(const vector<Transaction>& t) {
    float total = 0;
    for (auto &x : t) {
        total += x.amount;
    }
    return total;
}

// Main function
int main() {
    vector<Transaction> transactions;
    int choice;

    loadFromFile(transactions);

    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Transaction\n";
        cout << "2. Show Transactions\n";
        cout << "3. Delete Transaction\n";
        cout << "4. Show Balance\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTransaction(transactions); break;
            case 2: showTransactions(transactions); break;
            case 3: deleteTransaction(transactions); break;
            case 4: cout << "Balance: " << getBalance(transactions) << endl; break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}