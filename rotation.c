#include <stdio.h>

/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);

/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);

/*---main---*/
int main()
{
    int x;
    char strng[1024];
    printf("Enter a word to encrypt:");
    scanf("%s", strng);
    
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

void encryptRotation(int x, char *strng)
{
    for(int i = 0; i < 1024; i++)
    {
        strng[i] = strng[i] + x;
    }
}

void decryptRotation(int x, char *strng)
{
    for(int i = 0; i < 1024; i++)
    {
        strng[i] = strng[i] - x;
    }
}
