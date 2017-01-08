// This program counts pecentages of chars
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// check if this char is printable
int isNotPrint(int ch) {
    return !isprint(ch);
}

// jump table
static int (*testFunc[])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    isNotPrint
};
#define N_CATEGORIES (sizeof(testFunc) / sizeof(testFunc)[0])

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
    int N_CATE = N_CATEGORIES;
    printf("N_CATEGORIES is %d\n", N_CATE);
    while((ch = getchar()) != EOF) {
        ++total;

        for(category = 0; category < N_CATEGORIES; ++category) {
            if(testFunc[category](ch))
                ++count[category];
        }
    }

    // print result
    if(0 == total) {
        printf("No char in the input.");
        return EXIT_SUCCESS;
    }
    for(category = 0; category < N_CATEGORIES; ++category) {
        printf("%3.0f%% %s chars\n",
            count[category] * 100.0 / total,
            lable[category]);
    }
    return EXIT_SUCCESS;
}
