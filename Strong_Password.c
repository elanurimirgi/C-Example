#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16
#define MIN_PASSWORD_LENGTH 8

int main() {
    char password[20];
    int c;

    for (int i = 1; i <= 3; i++) {

        int len = 0;
        while ((c = getchar()) != '\n' && c != EOF && len < 20) {
            password[len++] = c;
        }
        password[len] = '\0';

        if (strlen(password) == 0) {
            continue;
        }

        int has_alnum = 0;
        int has_upper = 0;
        int has_punct = 0;

        for (int j = 0; j < strlen(password); j++) {
             if (!isalnum(password[j]) && !ispunct(password[j]) && !isspace(password[j])) {
                printf("INVALID ");
                return EXIT_FAILURE;
            }

            // Check for Turkish characters
            if (password[j] == 305 || password[j] == 304 || password[j] == 287 || password[j] == 286 ||
                password[j] == 252 || password[j] == 220 || password[j] == 351 || password[j] == 350 ||
                password[j] == 246 || password[j] == 214 || password[j] == 231 || password[j] == 199) {

                printf("INVALID ");
                return EXIT_FAILURE;
            }


            if (password[j] >= 'A' && password[j] <= 'Z') {
                has_upper = 1;
            }
            else if (isalnum(password[j])) {
                has_alnum = 1;
            }
            else if (ispunct(password[j])) {
                has_punct = 1;
            }

        }

        if (strlen(password) < MIN_PASSWORD_LENGTH ) {
            printf("TOOSHORT ");
        }
        if (strlen(password) > MAX_PASSWORD_LENGTH ) {
            printf("TOOLONG ");
            if (!has_alnum) {
                printf("NOALNUM ");
            }
            if (!has_upper) {
                printf("NOUPPER ");
            }
            if (!has_punct) {
                printf("NOPUNCT ");
            }
            break;
        }
        if (!has_alnum) {
            printf("NOALNUM ");
            return EXIT_FAILURE;
        }
        if (!has_upper) {
            printf("NOUPPER ");
            return EXIT_FAILURE; 
        }
        if (!has_punct) {
            printf("NOPUNCT ");
             return EXIT_FAILURE;
        }

        if (strlen(password) >= MIN_PASSWORD_LENGTH && strlen(password) <= MAX_PASSWORD_LENGTH &&
            has_alnum && has_upper && has_punct) {

            int strength;
            strength = 6.55 * len;

            if (strength < 60.0) {
                printf("WEAK ");
            }
            else {
                printf("STRONG ");
            }
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}
