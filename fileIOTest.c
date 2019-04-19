#include <stdio.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);


/*---Main---*/
int main()
{
    int x, y, i;
    char strng[30];
    char ch;
    FILE *in, *out;
    char inputName[30];
    
    printf("Enter input file name: ");
    scanf("%s", inputName);
    
    
    in = fopen(inputName, "r+");
    if (in == NULL)         //prints user friendly error message
    {
        perror("Error : fopen()");
        return 0;
    }
    
    for (i=0; i<30; i++)
    {
        if ( !(feof(in)) )
        {
            fscanf(in, "%c", &ch);
            strng[i] = ch;
        }
    }
    printf("File contains: %s\n", strng); //original file contents
    
    textCaps(strng); //convert to all caps
    fprintf(in, "%s", strng);
    for (i=0; i<30; i++)
    {
        if ( !(feof(in)) )
        {
            fscanf(in, "%c", &ch);
            strng[i] = ch;
        }
    }
    printf("File contains: %s\n", strng);

}

/*---Functions---*/
void textCaps(char *strng)
{
    for(int i=0; i<30; i++)
    {
        if (strng[i] > 'a' && strng[i] < 'z')
            strng[i] = strng[i] - 32;
    }
}

