/* PROJECT : NUMBER TO WORD */
/* Write code to convert a given number into words. */
/* For example, if “1234” is given as input, output should be “one thousand, two hundred and thirty four”. */

#include <iostream>
#include <cstring>

using namespace std;

typedef char* pchar;
typedef long long int bignum;

/* ****************************************************************************** */

void printWord (pchar w){
    for (; *w != '\0'; w++)
        cout << *w;
    cout << " ";
}

void numberToWord (bignum n){

    char dec0[20][20] = {"", "One", "Two", "Three", "Four",
                          "Five", "Six", "Seven", "Eight", "Nine",
                          "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                          "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},

         dec1[10][20] = {"", "", "Twenty", "Thirty", "Forty",
                          "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},

         dec3[10][20] = {"", "Thousand,", "Million,", "Billion,", "Trillion,",
                          "Quadrillion,", "Quintillion,", "Sextillion,", "gg24,", "gg30,"};

    int d[21] = {0};                                    // array holding the digits, d, of the number
    int i, j;

    for (i=0; n>0 && i<21; i++, n/=10){                 // Splitting the number into digits
        d[i] = n%10;
    }

    for (i = (i-1)/3 * 3; i>=0; i-=3){                  // Dividing the number into bocks of thousands

        if (d[i+2] == 0 && d[i+1] == 0 && d[i] == 0)
            continue;

        if (d[i+2] > 0) {
            printWord (dec0[d[i+2]]);
            cout << "Hundred ";
        }

        if (d[i+1] > 0 || d[i] > 0) {

            if (d[i+2] > 0) cout << "and ";

            if (d[i+1] == 1) j = 1;
            else {
                printWord (dec1[d[i+1]]);
                j = 0;
                }

            printWord (dec0[j * 10 + d[i]]);
            }

        printWord (dec3[i/3]);
    }
}

/* ****************************************************************************** */

int main (){

    bignum number;

    cout << "Enter a number : ";
    cin >> number;

    numberToWord (number);

    return 0;

}
