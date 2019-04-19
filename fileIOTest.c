#include <stdio.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);


/*---Main---*/
int main()
{
    int i;
    char strng[30];
    char ch;
    FILE *in, *out;
    char inputName[30];
    
    printf("Enter input file name: ");
    scanf("%s", inputName);
    
    
    in = fopen(inputName, "r");
    if (in == NULL)         //prints user friendly error message
    {
        perror("ERROR : fopen()");
        return 0;
    }
    
    out = fopen("output.txt", "w");
    if (in == NULL)         //prints user friendly error message
    {
        perror("ERROR : fopen()");
        return 0;
    }
    
    for (i=0; i<30; i++) //reads file into strng (only single words, stops at first white space)
    {
        fscanf(in, "%c", &ch); 
        if ( (feof(in)) ) //not end of file
            break;
        strng[i] = ch;
    }
    printf("File contains: %s\n", strng); //original file contents
    
    textCaps(strng); //convert to all caps
    
    fprintf(out, "%s", strng); //prints strng to output file
    for (i=0; i<30; i++)

    fclose(in);
    fclose(out);
    return 0;
}

/*---Functions---*/
void textCaps(char *strng)
{
    for(int i=0; i<30; i++)
    {
        if (strng[i] >= 'a' && strng[i] <= 'z')
            strng[i] = strng[i] - 32;
    }
}

