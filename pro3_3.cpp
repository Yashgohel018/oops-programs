//Yash Gohel-24CE035
//Program No:3.3
#include <iostream>
#include <vector>
using namespace std;
//make class of BankAccount
class BankAccount
{
public:
    int accnum;
    string holder_name;
    double balance;

    void add_account(vector<BankAccount> &arr);
    void display_accounts(const vector<BankAccount> &arr);
    void money_transfer(vector<BankAccount> &arr);
};

void BankAccount::add_account(vector<BankAccount> &arr)//Making function of Bankaccount class using scope resolution operator.
{
    BankAccount new_acc;

    cout << "Enter the account number: ";
    cin >> new_acc.accnum;

    cout << "Enter the holder name: ";
    cin.ignore();
    getline(cin, new_acc.holder_name);

    cout << "Enter initial balance: ";
    cin >> new_acc.balance;

    arr.push_back(new_acc);
    cout << "Account added successfully...\n";
}

void BankAccount::display_accounts(const vector<BankAccount> &arr)
{
    cout << "\nAccount Details:\n";

    if (arr.empty())
    {
        cout << "There are no accounts to display.\n";
        return;
    }

    for (const auto &account : arr)
    {
        cout << "Account number: " << account.accnum << endl;
        cout << "Holder's name: " << account.holder_name << endl;
        cout << "Balance: " << account.balance << endl;
        cout << "------------------------------------\n";
    }
}

void BankAccount::money_transfer(vector<BankAccount> &arr)
{
    int from_acc, to_acc;
    double money;
    cout << "From account number: ";
    cin >> from_acc;
    cout << "To account number: ";
    cin >> to_acc;
    cout << "How much money: ";
    cin >> money;

    BankAccount *from = nullptr, *to = nullptr;

    for (auto &acc : arr)
    {
        if (acc.accnum == from_acc)
            from = &acc;
        if (acc.accnum == to_acc)
            to = &acc;
    }

    if (from == nullptr || to == nullptr)
    {
        cout << "One or both account numbers are invalid.\n";
        return;
    }

    if (from->balance < money)
    {
        cout << "Insufficient balance in source account.\n";
        return;
    }

    from->balance -= money;
    to->balance += money;
    cout << "Transfer successful!\n";
}

int main()
{
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n1. Add Account\n2. Display Accounts\n3. Transfer Money\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                BankAccount acc;
                acc.add_account(accounts);
            }
            break;

            case 2:
            {
                BankAccount acc;
                acc.display_accounts(accounts);
            }
            break;

            case 3:
            {
                BankAccount acc;
                acc.money_transfer(accounts);
            }
            break;

            case 4:
                cout << "Exiting the Program...\n";
                break;

            default:
                cout << "Invalid Input...\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
