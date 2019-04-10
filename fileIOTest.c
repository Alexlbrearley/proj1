#include <stdio.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);

/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);

/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);

/*---Main---*/
int main()
{
    int x, y;
    char strng[30];
    
    FILE *input;
    input = fopen("input.txt", "r+");
    if (input == NULL)
    {
        perror("fopen()");
        return 0;
    }
    printf("File contians: %s\n", input);

    //fscanf("%s", strng);
    
    //textCaps(input);
    
    
    printf("Please choose an option:\n1: Encrypt\n2: Decrypt\n");
    scanf("%d", &y);
    
    if (y==1)
        {
            printf("Enter a rotation value: ");
            scanf("%d", &x);
            encryptRotation(x, strng);
            //fprintf(FILE *output,"%s", strng);
        }
     else if (y==2)
        {
            printf("Enter a rotation value: ");
            scanf("%d", &x);
            printf("Enter a rotation value: ");
            scanf("%d", &x);
            decryptRotation(x, strng);
            //fprintf(FILE *output,"%s", strng);
        }
}

/*---Functions---*/
void textCaps(char *strng)
{
    for(int i=0; i<30; i++)
    {
        if (strng[i] > 'a' || strng[i] < 'z')
            strng[i] = strng[i] - 32;
    }
}

void encryptRotation(int x, char *strng)
{
    for(int i = 0; i < 30; i++)
    {
        strng[i] = strng[i] - x;
    }
    for(int i=0; i<30; i++)
    {
        if (strng[i] > 90)
            strng[i] = strng[i] - 26;
        if (strng[i] < 65)
            strng[i] = strng[i] + 26;
    }
}

void decryptRotation(int x, char *strng)
{
    for(int i = 0; i < 30; i++)
    {
        strng[i] = strng[i] + x;
    }
    for(int i=0; i<30; i++)
    {
        if (strng[i] > 90)
            strng[i] = strng[i] - 26;
        if ( strng[i] < 65)
            strng[i] = strng[i] + 26;
    }
}
