// This program counts pecentages of chars
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// check if this char is printable
bool isNotPrint() {
    return !isPrint();
}

// jump table
static int (*testFunc[])(int) = {
    isCtrl;
    isSpace;
    isDigit;
    isLower;
    isUpper;
    isPunct;
    isNotPrint;
};
#define N_CATEGORIES (sizeof(test_func) / sizeof(test_func)[0])

// names of characters
char *lable[] = {
    "control",
    "whiteSpace",
    "digit",
    "lowerCase",
    "upperCase",
    "punctuation",
    "nonPrintable"
};

// current count of char, and total count of chars
int count[N_CATEGORIES];
int total;

main() {
    int ch;
    int category;

    while(ch = getchar() != EOF) {
        ++total;

        for(category = 0; category < N_CATEGORIES; ++category) {
            if(test_func[category](ch))
                ++count[category];
        }
    }

    // print result
    if(0 == total) {
        printf("No char in the input.");
        return EXIT_SUCCESS;
    }
    for(category = 0; category < N_CATEGORIES; ++category) {
        printf("%3.0f%% %s chars\n", count[category] * 100.0 / total)
    }
}










