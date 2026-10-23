
/*Задание 1
Ввести первоначальный вклад S (100..10 000) и срок n (1..24) месяцев. В цикле for в конце каждого месяца сначала начислять 2% на текущую сумму, затем добавлять 50. Вывести баланс после каждого месяца, итоговый баланс и чистый доход от процентов (итоговый баланс минус S и минус 50·n). Использовать тип double; округлять на каждом месяце не нужно.
*/
#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

int main() {
    //Constants
    static const double MONTHLY_PERCENT = 0.02d;
    static const double MONTHLY_ONTOP = 50.0d;

    static const double DEPOSIT_LIMITATIONS[2] = {100.0d, 10000.0d};
    static const int TERM_LIMITATIONS[2] = {1, 24};
    //Variables
    double initial_deposit;
    int term;

    double balance = 0;
    //Value assignment
    do {
        cout << endl << "Please enter the initial deposit [" << DEPOSIT_LIMITATIONS[0] << "-" << DEPOSIT_LIMITATIONS[1] << "]: ";
        cin >> initial_deposit;
        
    } while (initial_deposit > DEPOSIT_LIMITATIONS[1] || initial_deposit < DEPOSIT_LIMITATIONS[0]);
    balance += initial_deposit;

    do {
        cout << endl << "Please enter the number of months [bewarned they are automatically converted to 1-24 range by the means of mod]: ";
        cin >> term;

        if (term% (TERM_LIMITATIONS[1] + 1) != 0) {term = ((term>0) && (term<=TERM_LIMITATIONS[1])) ? term : ((term%(TERM_LIMITATIONS[1] + 1) > 0) ? (term%(TERM_LIMITATIONS[1] + 1)) : ((TERM_LIMITATIONS[1] + 1) + term%(TERM_LIMITATIONS[1] + 1)));}
    } while (term%(TERM_LIMITATIONS[1] + 1) == 0);

    //cout << endl << term << endl;
    //cout << endl << initial_deposit << endl;

    //Cycle
    for (int i = 0; i < term; i++){
        balance += MONTHLY_PERCENT*balance;
        balance += MONTHLY_ONTOP;

        cout << "\n\t\tThe " << i + 1 << (((i + 1)%10 != 1) ? 
            ( ((i + 1)%10 != 2) ? 
              ( ((i + 1)%10 != 3) ? "th" : "rd") : "nd") : "st") << " month results:";
        cout << endl << "Current balance: \t" << balance;
        cout << endl << "Percentile bonus: \t" << balance - initial_deposit - MONTHLY_ONTOP*(i+1) << endl;
    }
    
    return 0;
}