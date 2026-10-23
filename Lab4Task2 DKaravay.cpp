/*Задание 2
Ввести правильный PIN из четырёх цифр (1000..9999). Затем дать пользователю не более трёх попыток ввода PIN через while. После каждой неверной попытки выводить, сколько попыток осталось. При совпадении прекратить ввод досрочно; в конце вывести «Доступ открыт» или «Карта заблокирована». Любое неверное число считается попыткой.
*/

#include <iostream>
#include <cmath>
using namespace std;

int simple_cipher(int* n, int decimal_num) {
    int ciphered_code = 0;

    for (int i = 0; i < decimal_num; i++){
        ciphered_code += ( (n[i] < 9) ? (n[i] + 1) : 0 ) * pow(10, 
                ( (i != decimal_num - 1) ? (decimal_num - 2 - i) : (decimal_num - 1) ) );
    //     cout << ( (n[i] < 9) ? (n[i] + 1) : 0 ) * pow(10, 
    //             ( (i != decimal_num - 1) ? (decimal_num - 2 - i) : (decimal_num - 1) ) ) << endl;
    //     cout << "\tcr:" << ciphered_code << endl;
    }
    cout << ciphered_code << endl;
    return ciphered_code;
}

int* helper(int n, int decimal_num) {
    int* code = new int[decimal_num];

    for (int i = 0; i < decimal_num; i++) {
        int current_power = static_cast<int>(pow(10, i + 1));
        int prev_power = static_cast<int>(pow(10, i));

        int digit = (n % current_power) / prev_power;
        // cout << "\tdigit " << digit << endl; 

        code[decimal_num - 1 - i] = digit;
    }

    // for (int i = 0; i < decimal_num; i++) {
    //     cout << code[i] << " ";
    // }
    // cout << endl;

    return code;
}

int main() {
    const int CIPHERED_CODE = 5234;
    const int DECIMAL_NUM = 4;
    const int NUM_ATTEMPTS = 3;

    int entered_code;
    int attempt = 0;
    while (attempt < NUM_ATTEMPTS) {

        
        cout << "Enter a code: ";
        cin >> entered_code;
            
        
        if ((entered_code < 1000 || entered_code > 9999) || simple_cipher(helper(entered_code, DECIMAL_NUM), DECIMAL_NUM) != CIPHERED_CODE) {
            attempt++;
            cout << endl << "You have " << NUM_ATTEMPTS - attempt << " attempts left" << endl;
        } else {
            cout << endl << "\tAccess granted" << endl;
            return 0;
        }
    }
    
    cout << "You been blocked sowwy womp womp";
    return 0;
}




