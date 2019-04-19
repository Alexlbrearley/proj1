#include <stdio.h>
#include <string.h>

/*fprintf(out, "%s", strng); //prints strng to output file*/


/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);

/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);

/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);

void encryptSubstitution(char *keyStrng, char *strng);

void decryptSubstitution(char *keyStrng, char *strng);

              
/*---Main---*/
int main()
{
    int c;
    int x;
    char z;
    printf("\n\n/-------------------------------/\n");
    printf("/---Welcome to Cipher program---/\n");
    printf("/-------------------------------/\n\n");
    printf("To use this program, a file containing a message to encrypt or decrypt needs to be opened.\n\n");

    /*---File I/O---*/
    int i;
    char strng[100];
    char ch;
    FILE *in, *out, *key;
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
    
    for (i=0; i<100; i++) //reads file into strng
    {
        fscanf(in, "%c", &ch);
        if ( (feof(in)) ) //not end of file
            break;
        strng[i] = ch;
    }
    printf("\n\n/-------------------------------/");
    printf("\nFile contains: %s", strng); //original file contents
    textCaps(strng); //convert to all caps
    printf("\n/-------------------------------/\n");
    printf("\nThis program can perform following operations:\n\n 1. Rotation Cipher\n 2. Substitution Cipher\n 3. Decrypt Without Key\n\n Please enter an option: ");
    scanf("%d", &c);
    /*---Rotation Program---*/
    if (c == 1)
    {
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &c);
        if (c == 1) //encrypt rotation
        {
            printf("\nEnter a rotation amount: ");
            scanf("%d", &x);
            encryptRotation(x, strng);
            printf("\nThe result is: %s\n", strng);
            fprintf(out, "%s", strng);
            printf("\nWould you like to overwrite %s? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
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
            printf("\nWould you like to overwrite %s? y or n: ", inputName); //option to overwrite the input file
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
        char keyStrng[26];
        key = fopen("key.txt", "r");
        if (key == NULL)         //prints user friendly error message
        {
            perror("ERROR : fopen()");
            return 0;
        }
        for (i=0; i<26; i++) //reads file into keyStrng
        {
            fscanf(key, "%c", &ch);
            if ( (feof(key)) ) //stops at end of file
                break;
            keyStrng[i] = ch;
        }
        
        printf("\nFound key: %s\n", keyStrng);
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &c);
        
        if(c == 1)
        {
            encryptSubstitution(keyStrng, strng);
            printf("\nThe encrypted message is: %s\n", strng);
            printf("\nWould you like to overwrite %s? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", strng);
            }
        }
        else if(c == 2)
        {
            decryptSubstitution(keyStrng, strng);
            printf("\nThe encrypted message is: %s\n", strng);
            printf("\nWould you like to overwrite %s? y or n: ", inputName); //option to overwrite the input file
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", strng);
            }
        }
        
        
        
        
        
    }
    /*---newprogram---*/
    else if (c==3)
    {
    }
    else
        printf("%d is invalid\n", c);
    
    
    /*---End Main---*/
    
    fclose(in);
    fclose(out);
    fclose(key);
    printf("\n\n/-------------------------------/\n");
    printf("/------------Goodbye!-----------/");
    printf("\n/-------------------------------/\n\n");

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

void encryptSubstitution(char *keyStrng, char *strng)
{
    int i, l;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; i<strlen(strng); i++)
    {
        for (l=0; l<26; l++)
        {
            if (alphabet[l] == strng[i])
            {
                strng[i] = keyStrng[l];
                break;
            }
            
        }
    }
}

void decryptSubstitution(char *keyStrng, char *strng)
{
    int i, l;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i=0; i<strlen(strng); i++)
    {
        for (l=0; l<26; l++)
        {
            if (keyStrng[l] == strng[i])
            {
                strng[i] = alphabet[l];
                break;
            }
            
        }
    }
}
