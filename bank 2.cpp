#include <iostream>
#include <unordered_map>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNum, string holder, double initialBalance = 0.0) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    unordered_map<string, BankAccount> accounts;
    int choice;
    string accNum, name;
    double amount;

    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                accounts[accNum] = BankAccount(accNum, name);
                cout << "Account created successfully!\n";
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                if (accounts.find(accNum) != accounts.end()) {
                    cout << "Enter Amount to Deposit: ";
                    cin >> amount;
                    accounts[accNum].deposit(amount);
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                if (accounts.find(accNum) != accounts.end()) {
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amount;
                    accounts[accNum].withdraw(amount);
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                if (accounts.find(accNum) != accounts.end()) {
                    accounts[accNum].displayBalance();
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
