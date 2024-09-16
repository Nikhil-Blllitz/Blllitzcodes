#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertString(char *string1, const char *string2, int position) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if (position < 0 || position > len1) {
        printf("Invalid position for insertion.\n");
        return;
    }

    char *result = (char *)malloc(len1 + len2 + 1);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strncpy(result, string1, position);
    result[position] = '\0';

    strcat(result, string2);
    strcat(result, string1 + position);

    printf("Result: %s\n", result);

    free(result);
}

int main() {
    char string1[100];
    char string2[100];
    int position;

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0'; 

    printf("Enter the position for insertion: ");
    scanf("%d", &position);

    insertString(string1,string2,position);

    return (0);
}
