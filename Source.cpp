#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    BankAccount(int accountNumber, string accountHolderName, double balance) {}
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << accountNumber << endl;
        }
        else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }
    void checkBalance() {
        cout << "Account " << accountNumber << " balance: " << balance << endl;
    }
	~BankAccount() {}
};

int main() {
    int accountNumber, initialBalance, withdrawAmount, depositAmount;
    string accountHolderName;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, accountHolderName);
    cout << "Enter initial balance (default is 0.0): ";
    cin >> initialBalance;
    BankAccount account(accountNumber, accountHolderName, initialBalance);
    cout << "Enter amount to deposit (or 0 to skip): ";
    cin >> depositAmount;
    if (depositAmount > 0) {
        account.deposit(depositAmount);
    }
    cout << "Enter amount to withdraw (or 0 to skip): ";
    cin >> withdrawAmount;
    if (withdrawAmount > 0) {
        account.withdraw(withdrawAmount);
    }
    account.checkBalance();
    return 0;
}