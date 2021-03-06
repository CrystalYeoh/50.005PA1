#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()

    FILE* fp = fopen(args[1],"r");

    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (fp ==NULL){
        printf("File does not exist.\n");
        return 1;
    }

    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    int bufsize = 1000;
    char *buffer;

    buffer = malloc(sizeof(char)*bufsize);

    if(buffer == NULL){
        return NULL;
    }

    
    int count = 0;
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    while(getline(&buffer,&bufsize,fp) != -1){
        count+=1;
    }

    // 6. Close the FILE*
    int f = fclose(fp);

    // 7. Print out how many lines are there in this particular filename
    printf("There are %d lines in %s.\n",count,args[1]);
    
    free(buffer);

    // 8. Return 1, to exit program
    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}