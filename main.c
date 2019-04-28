#include <stdio.h>
#include <string.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);
/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);
/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);
/* ---This function takes a key string and a message string to encode the message---*/
void encryptSubstitution(char *key, char *strng);
/* ---This function takes a key string and a message string to decode the message---*/
void decryptSubstitution(char *key, char *strng);
              
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
    char message[1000];
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
    for (i=0; i<1000; i++) //reads file into strng
    {
        fscanf(in, "%c", &ch);
        if ( (feof(in)) ) //not end of file
            break;
        message[i] = ch;
    }
    printf("\n\n/-------------------------------/");
    textCaps(message); //convert to all caps
    printf("\nFile contains: %s", message); //original file contents
    printf("\n/-------------------------------/\n");
    printf("\nThis program can perform following operations:\n\n 1. Rotation Cipher\n 2. Substitution Cipher\n 3. Decrypt Without Key\n\n Please enter an option: ");
    scanf("%d", &c);
/*---Rotation Program---*/
    if (c == 1)
    {
        int q;
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &q);
        if (q == 1) //encrypt rotation
        {
            printf("\nEnter a rotation amount between 1 and 26: ");
            scanf("%d", &x);
            if (x < 1 || x > 26)
            {
                printf("\n ERROR: The rotation must be between 1 and 26, you entered %d\n", x);
            }
            else
            {
                encryptRotation(x, message);
                printf("\nThe result is: %s\n", message);
                fprintf(out, "%s", message);
                printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
                scanf("%s", &z);
                if (z == 'y')
                {
                    in = fopen(inputName, "w");
                    fprintf(in, "%s", message);
                }
            }
        }
        else if (q == 2) //decrypt rotation
        {
            printf("\nEnter the rotation amount between 1 and 26 that the text was encrypted with: ");
            scanf("%d", &x);
            if (x < 1 || x > 26)
            {
                printf("\n ERROR: The rotation must be between 1 and 26, you entered %d\n", x);
            }
            else
            {
                decryptRotation(x, message);
                printf("\nThe result is: %s\n", message);
                fprintf(out, "%s", message);
                printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file
                scanf("%s", &z);
                if (z == 'y')
                {
                    in = fopen(inputName, "w");
                    fprintf(in, "%s", message);
                }
            }
        }
    }
/*---Substitution Program---*/
    else if (c == 2)
    {
        int q;
        char keyStrng[25];
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
        textCaps(keyStrng);
        
        printf("\nFound key: %s\n", keyStrng);
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &q);
        if(q == 1)
        {
            encryptSubstitution(keyStrng, message);
            fprintf(out, "%s", message);
            printf("\nThe encrypted message is: %s\n", message);
            printf("\nWould you like to overwrite %s? with the encrypted text? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", message);
            }
        }
        else if(q == 2)
        {
            decryptSubstitution(keyStrng, message);
            fprintf(out, "%s", message);
            printf("\nThe encrypted message is: %s\n", message);
            printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file
            scanf("%s", &z);
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", message);
            }
        }
        fclose(key);
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
    printf("\n\n/-------------------------------/\n");
    printf("/------------Goodbye!-----------/");
    printf("\n/-------------------------------/\n\n");
    return 0;
}
              
/*---Functions---*/
void textCaps(char *strng)
{
    for(int i=0; i<1000; i++)
    {
        if (strng[i] >= 'a' && strng[i] <= 'z')
            strng[i] = strng[i] - 32;
    }
}
//------------------------------------------------------
void encryptRotation(int x, char *strng)
{
    for(int i = 0; i < 1000; i++)
    {
        if (strng[i] >= 65 && strng[i] <=90)
        {
            strng[i] = strng[i] - x;
            if (strng[i] < 65 && strng[i] >= 65-x)
               strng[i] = strng[i] + 26;
        }
    }
}
//------------------------------------------------------
void decryptRotation(int x, char *strng)
{
    for(int i = 0; i < 1000; i++)
    {
        if (strng[i] >= 65 && strng[i] <=90)
        {
            strng[i] = strng[i] + x;
            if (strng[i] > 90 && strng[i] <= 90+x)
                strng[i] = strng[i] - 26;
        }
    }
}
//------------------------------------------------------
void encryptSubstitution(char *key, char *strng)
{
    int i, l;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; i<strlen(strng); i++)
    {
        for (l=0; l<26; l++)
        {
            if (alphabet[l] == strng[i])
            {
                strng[i] = key[l];
                break;
            }
            
        }
    }
}
//------------------------------------------------------
void decryptSubstitution(char *key, char *strng)
{
    int i, l;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i=0; i<strlen(strng); i++)
    {
        for (l=0; l<26; l++)
        {
            if (key[l] == strng[i])
            {
                strng[i] = alphabet[l];
                break;
            }
            
        }
    }
}
