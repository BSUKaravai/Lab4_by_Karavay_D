/*Задание 4
Ввести n (2..6) — количество тарифных планов и m (2..8) — число месяцев. Вложенными циклами сформировать таблицу накопленных выплат: в плане i ежемесячная плата составляет 10 + 5·i, а каждый третий месяц дополнительно списывается 7. В ячейке (i,j) вывести полную сумму списаний с начала обслуживания по месяц j; использовать накопитель для каждой строки.

*/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    //Constants
    static const int PLAN_LIMITATIONS[2] = {2, 6};
    static const int MONTH_LIMITATIONS[2] = {2, 8};

    static const int MONTHLY_BASE = 10;
    static const int MONTHLY_INCREMENT = 5;
    static const int EXTRA_DECRIMENT = 7;
    static const int EXTRA_DECRIMENT_PERIOD = 3;

    //Variables
    int n;
    int m;

    //Value assignment
    do {
        cout << "Please enter the number of tariff plans ["
             << PLAN_LIMITATIONS[0] << "-"
             << PLAN_LIMITATIONS[1] << "]: ";
        cin >> n;
    } while (n < PLAN_LIMITATIONS[0] || n > PLAN_LIMITATIONS[1]);

    do {
        cout << "Please enter the number of months ["
             << MONTH_LIMITATIONS[0] << "-"
             << MONTH_LIMITATIONS[1] << "]: ";
        cin >> m;
    } while (m < MONTH_LIMITATIONS[0] || m > MONTH_LIMITATIONS[1]);

    //Matrix header
    cout << "\nAccumulated payments:\n";
    cout << "Plan\t";

    for (int j = 0; j < m; j++) {
        cout << "M" << j+1 << "\t"; //Headers for months
    }

    cout << endl;

    //Cycle
    for (int i = 0; i < n; i++) {
        int accumulated_payment = 0; //init
        int monthly_payment = MONTHLY_BASE + MONTHLY_INCREMENT * (i+1);

        cout << (i + 1) << "\t\t"; //Header for plan number

        for (int j = 0; j < m; j++) {
            accumulated_payment += monthly_payment;

            if ((j+1) % EXTRA_DECRIMENT_PERIOD == 0) {
                accumulated_payment -= EXTRA_DECRIMENT;
            }

            cout << accumulated_payment << "\t";
        }

        cout << endl;
    }

    return 0;
}