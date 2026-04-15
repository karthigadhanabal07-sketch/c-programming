#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char str[]) {
    int len = strlen(str);
    printf("Reversed String: ");
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void checkPalindrome(char str[]) {
    int len = strlen(str);
    int flag = 1;

    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

void countCharacters(char str[]) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i]))
            digits++;
        else if(str[i] == ' ')
            spaces++;
        else if(strchr("aeiouAEIOU", str[i]))
            vowels++;
        else if(isalpha(str[i]))
            consonants++;
    }

    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\n",
           vowels, consonants, digits, spaces);
}

void toUpperCase(char str[]) {
    for(int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase: %s\n", str);
}

void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase: %s\n", str);
}

int main() {
    char str[100];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline
    str[strcspn(str, "\n")] = '\0';

    do {
        printf("\n--- STRING UTILITY BOX ---\n");
        printf("1. Reverse String\n");
        printf("2. Check Palindrome\n");
        printf("3. Count Characters\n");
        printf("4. Convert to Uppercase\n");
        printf("5. Convert to Lowercase\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                reverseString(str);
                break;
            case 2:
                checkPalindrome(str);
                break;
            case 3:
                countCharacters(str);
                break;
            case 4:
                toUpperCase(str);
                break;
            case 5:
                toLowerCase(str);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
