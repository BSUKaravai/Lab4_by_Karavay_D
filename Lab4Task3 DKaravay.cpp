/*Задание 3
Ввести стартовый баланс B (0..10000). Создать меню do-while: 1 — пополнить на положительную целую сумму, 2 — снять положительную целую сумму, 3 — показать баланс, 0 — выход. Отклонять снятие сверх баланса и неположительные суммы. После выхода вывести баланс и общее количество успешно выполненных пополнений и снятий.
*/


#include <iostream>

using namespace std;

int main() {
    //Constants
    static const int BALANCE_LIMITATIONS[2] = {0, 10000};

    //Variables
    int balance, choice, amount;

    int successful_deposits = 0;
    int successful_withdrawals = 0;

    //Initial balance
    do {
        cout << "Please enter the initial balance ["
             << BALANCE_LIMITATIONS[0] << "-"
             << BALANCE_LIMITATIONS[1] << "]: ";
        cin >> balance;
    } while (balance < BALANCE_LIMITATIONS[0]
          || balance > BALANCE_LIMITATIONS[1]);

    //Menu
    do {
        cout << "\n\n\tMENU";
        cout << "\n1 - Deposit";
        cout << "\n2 - Withdraw";
        cout << "\n3 - Show balance";
        cout << "\n0 - Exit";
        cout << "\nPlease select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Please enter the deposit amount: ";
                cin >> amount;

                balance += amount;
                successful_deposits++;

                cout << "Deposit successful.";
                break;

            case 2:
                cout << "Please enter the withdrawal amount: ";
                cin >> amount;

                if (amount > balance) {
                    cout << "Insufficient balance. Withdrawal rejected.";
                } else {
                    balance -= amount;
                    successful_withdrawals++;

                    cout << "Withdrawal successful.";
                }
                break;

            case 3:
                cout << "Current balance: " << balance;
                break;

            case 0:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid menu option.";
                break;
        }

    } while (choice != 0);

    //Final results
    cout << "\n\nFinal balance: " << balance;
    cout << "\nSuccessful deposits: " << successful_deposits;
    cout << "\nSuccessful withdrawals: " << successful_withdrawals;
    cout << endl;

    return 0;
}


