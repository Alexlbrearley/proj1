#include <stdio.h>
#include <string.h>


int main()
{
    int i, l;
    char word[100];
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key[] = "QWERTYUIOPLKJHGFDSAZXCVBNM";
    char value[26];
    char strng[] = "WHAT IS GOING ON?!";
    
    
    printf("Original text: %s\n", strng);
    
    for (i=0; i<strlen(strng); i++)
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
    
    printf("Encoded text: %s\n", strng);

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
    
    printf("Original text: %s\n", strng);


    return 0;
    
}
