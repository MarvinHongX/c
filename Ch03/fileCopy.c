#include <stdio.h>
#include <string.h>

int main(){
    char buffer;
    FILE *filePtr = fopen("fileCopy.txt","r");
    FILE *filePtr_copy = fopen("fileCopy_copy.txt","w");

    while(fscanf(filePtr, "%c", &buffer) != EOF)
        fprintf(filePtr_copy, "%c", buffer);

    fclose(filePtr);
    fclose(filePtr_copy);
    return 0;
}