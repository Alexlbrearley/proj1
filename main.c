#include <stdio.h>
/*fprintf(out, "%s", strng); //prints strng to output file*/


/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);

/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);

/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);
              
/*---Main---*/
int main()
{
    int c;
    printf("\n\n/---Welcome to Cipher program---/\n");
    printf("To use this program, a file containing a message to encrypt or decrypt needs to be opened.\n\n");

    /*---File I/O---*/
    int i;
    char strng[100];
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
    out = fopen("output.txt", "w+");
    if (in == NULL)         //prints user friendly error message
    {
        perror("ERROR : fopen()");
        return 0;
    }
    for (i=0; i<100; i++) //reads file into strng (only single words, stops at first white space)
    {
        fscanf(in, "%c", &ch);
        if ( (feof(in)) ) //not end of file
            break;
        strng[i] = ch;
    }
    printf("\nFile contains: %s\n", strng); //original file contents
    
    textCaps(strng); //convert to all caps
    
    printf("This program can perform following operations:\n\n 1. Rotation Cipher\n 2. Substitution Cipher\n 3. Decrypt Without Key\n Please enter an option:");
    scanf("%d", &c);
    /*---Rotation Program---*/
    if (c == 1)
    {
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &c);
        int x;
        char z;
        if (c == 1) //encrypt rotation
        {
            printf("\nEnter a rotation amount: ");
            scanf("%d", &x);
            encryptRotation(x, strng);
            printf("\nThe result is: %s\n", strng);
            fprintf(out, "%s", strng);
            printf("\nWould you like to overwrite %s? y or n: ", inputName);
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", strng);
            }

        }
        else if (c == 2) //decrypt rotation
        {
            printf("\nEnter the rotation amount to decrypt: ");
            scanf("%d", &x);
            decryptRotation(x, strng);
            printf("\nThe result is: %s\n", strng);
            fprintf(out, "%s", strng);
            printf("\nWould you like to overwrite %s? y or n: ", inputName);
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", strng);
            }
        }
        else
            printf("%d is not valid", c);
    }
    /*---Substitution Program---*/
    else if (c == 2)
    {
    }
    else if (c==3)
    {
    }
    else
        printf("%d is invalid\n", c);
    
    
    /*---End Main---*/
    fclose(in);
    fclose(out);
    return 0;
}
              
/*---Functions---*/
void textCaps(char *strng)
{
    for(int i=0; i<100; i++)
    {
        if (strng[i] >= 'a' && strng[i] <= 'z')
            strng[i] = strng[i] - 32;
    }
}
              
void encryptRotation(int x, char *strng)
{
    for(int i = 0; i < 100; i++)
    {
        if (strng[i] >= 65 && strng[i] <=90)
        {
            strng[i] = strng[i] - x;
        }
    }
    for(int i=0; i<100; i++)
    {
        if (strng[i] < 65 && strng[i] >= 65-x)
            strng[i] = strng[i] + 26;
    }
}

void decryptRotation(int x, char *strng)
{
    for(int i = 0; i < 100; i++)
    {
        if (strng[i] >= 65 && strng[i] <=90)
        {
            strng[i] = strng[i] + x;
        }
    }
    for(int i=0; i<100; i++)
    {
        if (strng[i] > 90 && strng[i] <= 90+x)
            strng[i] = strng[i] - 26;
    }
}
