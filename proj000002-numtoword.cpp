/* PROJECT : NUMBER TO WORD */
/* Write code to convert a given number into words. */
/* For example, if “1234” is given as input, output should be “one thousand two hundred thirty four”. */

#include <iostream>
#include <cstring>

using namespace std;

void printWord (char w[][20], int d){
    int i;

    for (i=0; w[d][i] != '\0'; i++){
            cout << w[d][i];
    }
    cout << " ";
}

int main (){
    char ones [20][20] = {"", "one", "two", "three", "four",
                          "five", "six", "seven", "eight", "nine",
                          "ten", "eleven", "twelve", "thirteen", "fourteen",
                          "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},

         tens [10][20] = {"", "", "twenty", "thirty", "forty",
                          "fifty", "sixty", "seventy", "eighty", "ninety"},

         thou [10][20] = {"", "thousand", "million,", "billion,", "trillion,",
                          "quadrillion,", "quintillion,", "sextillion,", "gg24,", "gg30,"};

    int digits[21] = {0};
    long int number, n;
    int i, j;
/* ****************************************************************************** */
    cout << "Enter a number : ";
    cin >> number;

    for (i=0, n=number; n>0 && i<21; i++, n/=10){
        digits[i] = n%10;
    }

    for (i = (i-1)/3 * 3; i>=0; i-=3){

        if (digits[i+2] > 0) {
            printWord (ones, digits[i+2]);
            cout << "hundred ";
        }

        if (digits[i+1] > 0 || digits[i] > 0) {
            cout << "and ";

            if (digits[i+1] > 1) {
                printWord (tens, digits[i+1]);
                j=0;
                }
            else j=1;

            printWord (ones, j * 10 + digits[i]);
            }

        printWord (thou, i/3);

    }

    return 0;

}
