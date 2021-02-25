# include <stdio.h>
# include <stdlib.h>

// Error utility macro
#define ON_ERROR_EXIT(cond, message) \
do { \
    if ((cond)) { \
        printf ("Error in function %s at line %d\n", __func__, __LINE__); \
        perror ((message)); \
        exit (1); \
    } \
} while (0);

const char *NAMEFILE = "dictionary.md";

void createFile () {
    FILE *fl;

    fl = fopen(NAMEFILE, "w");
    ON_ERROR_EXIT (fl == NULL, "Error fopen");
    fclose(fl);
}

void addWord (char *word) {
    FILE *fl;

    fl = fopen (NAMEFILE, "r");
    if (fl == NULL) {
        createFile ();
        printf("H\n");
    }
}

int main () {
    char *test = "Hello";
    addWord (test);
    return 0;
}