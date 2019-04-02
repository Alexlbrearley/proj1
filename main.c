#include <stdio.h>

int menu();
void rotation();
void substitution();

int main()
{
    char selection;
    printf("Welcome to Cipher program\n\n");
    printf("This program has the following options:\n\n a)Rotation Cypher\n b)Substitution Cypher\n c)Decryption\n\n Please choose one:\n");
    scanf("%c", &c);
    while(c < 'a' || c > 'c')
    {
        switch(c)
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            default: printf("Invalid option, please enter a), b), c) or d) : \n", c);

        }
        
    }
    
return 0;
}

void rotation()
{
    
    
}

void substitution()
{
    
    
}
