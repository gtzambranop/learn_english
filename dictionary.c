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

void createFile (char *name) {
    FILE *fl;

    fl = fopen (name, "w");
    ON_ERROR_EXIT (fl == NULL, "Error fopen");
    fclose (fl);
}

int fileExists (char *name) {
    FILE *fl;

    fl = fopen (name, "r");
    if (fl == NULL) return 0;
    fclose (fl);
    return 1;
}

void addWord (char *word, char *meaning) {
    FILE *fl;
    char line[64];
    char *fileName = (char *) NAMEFILE;
    int result = 0;

    if (!fileExists (fileName)) createFile (fileName);
    sprintf (line, "%s - %s\n", word, meaning);

    fl = fopen (fileName, "a");
    ON_ERROR_EXIT (fl == NULL, "Error opening file.");

    result = fputs (line, fl);
    ON_ERROR_EXIT (result == EOF, "Error writing to file");
    fclose (fl);
}

int main () {
    char *test = "Hello";
    char *mean = "Hola";
    addWord (test, mean);
    return 0;
}