#include <stdio.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);

/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);

/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);

/*---main---*/
int main()
{
    int x;
    char strng[30];
    printf("Enter a word to encrypt:");
    scanf("%s", strng);
    
    textCaps(strng);
    
    printf("Enter a rotation amount: ");
    scanf("%d", &x);
    encryptRotation(x, strng);
    printf("%s\n", strng);
    
    printf("Enter the rotation amount to decrypt: ");
    scanf("%d", &x);
    decryptRotation(x, strng);
    printf("%s\n", strng);
    return 0;
}

/*---functions---*/
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
        strng[i] = (strng[i] - x)%26;
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
        strng[i] = (strng[i] + x)%26;
    }
    for(int i=0; i<30; i++)
    {
        if (strng[i] > 90)
            strng[i] = strng[i] - 26;
        if (strng[i] < 65)
            strng[i] = strng[i] + 26;
    }
}

