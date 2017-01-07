/* PROJECT : NUMBER TO WORD */
/* Write code to convert a given number into words. */
/* For example, if “1234” is given as input, output should be “one thousand two hundred thirty four”. */

#include <iostream>
#include <cstring>

using namespace std;

typedef char* pchar;

void printWord (pchar w){
    for (; *w != '\0'; w++)
        cout << *w;
    cout << " ";
}

int main (){
    char ones[20][20] = {"", "One", "Two", "Three", "Four",
                          "Five", "Six", "Seven", "Eight", "Nine",
                          "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                          "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},

         tens[10][20] = {"", "", "Twenty", "Thirty", "Forty",
                          "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},

         thou[10][20] = {"", "Thousand,", "Million,", "Billion,", "Trillion,",
                          "Quadrillion,", "Quintillion,", "Sextillion,", "gg24,", "gg30,"};

    int digits[21] = {0};
    long long int number, n;
    int i, j;
/* ****************************************************************************** */
    cout << "Enter a number : ";
    cin >> number;

    for (i=0, n=number; n>0 && i<21; i++, n/=10){
        digits[i] = n%10;
    }

    for (i = (i-1)/3 * 3; i>=0; i-=3){

        if (digits[i+2] == 0 && digits[i+1] == 0 && digits[i] == 0)
            continue;

        if (digits[i+2] > 0) {
            printWord (ones[digits[i+2]]);
            cout << "hundred ";
        }

        if (digits[i+1] > 0 || digits[i] > 0) {

            if (digits[i+2] > 0) cout << "and ";

            if (digits[i+1] == 1) j = 1;
            else {
                printWord (tens[digits[i+1]]);
                j=0;
                }

            printWord (ones[j * 10 + digits[i]]);
            }

        printWord (thou[i/3]);

    }

    return 0;

}
