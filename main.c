#include <stdio.h>
#include <string.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);
/*---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng);
/*---This function takes encrypted text and the known value it was rotated by to decode for original text---*/
void decryptRotation(int x, char *strng);
/*---This function takes a key string and a outStrng string to encode the outStrng using the substitution method---*/
void encryptSubstitution(char *key, char *strng);
/* ---This function takes a key string and a outStrng string to decode the outStrng using the substitution method---*/
void decryptSubstitution(char *key, char *strng);
/*---This function attempts to decrypt a outStrng, that was encrypted by rotation, by finding double letters and testing against common letter pairs---*/
void rotationGuess(char *strng);
/*---This function goes with rotationGuess. It is almost the same, but writes the output to a separate sting so that the input stays constant---*/
void decryptRotationNoKey(int x, char *strng, char *outStrng);



/*---Main---*/
int main()
{
    int c;
    int x;
    char z;
    printf("\n\n/-------------------------------/\n");
    printf("/---Welcome to Cipher program---/\n");
    printf("/-------------------------------/\n\n");
    printf("To use this program, a file containing a message, to encrypt or decrypt, needs to be opened.\n\n");
    /*---File I/O---*/
    int i;
    char outStrng[1000];
    char ch;
    FILE *in, *out, *key;
    char inputName[30];
    printf("Enter input file name: ");
    scanf("%s", inputName);
    in = fopen(inputName, "r");
    if (in == NULL)         //prints user friendly error outStrng
    {
        perror("ERROR : fopen()");
        return 0;
    }
    out = fopen("output.txt", "w+");
    if (out == NULL)         //prints user friendly error outStrng
    {
        perror("ERROR : fopen()");
        return 0;
    }
    for (i=0; i<1000; i++) //reads file into strng
    {
        fscanf(in, "%c", &ch);
        if ( (feof(in)) ) //not end of file
            break;
        outStrng[i] = ch;
    }
    printf("\n\n/-------------------------------/");
    textCaps(outStrng); //convert to all caps
    printf("\nFile contains: %s", outStrng); //original file contents
    printf("\n/-------------------------------/\n");
    printf("\nThis program can perform following operations:\n\n 1. Rotation Cipher\n 2. Substitution Cipher\n 3. Decrypt Rotation Without Key\n\n Please enter an option: ");
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
                encryptRotation(x, outStrng);
                printf("\nThe result is: %s\n", outStrng);
                fprintf(out, "%s", outStrng);
                printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
                scanf("%s", &z);
                if (z == 'y')
                {
                    printf("\nAre you sure? y or n: ");
                    scanf("%s", &z);
                }
                if (z == 'y')
                {
                    in = fopen(inputName, "w");
                    fprintf(in, "%s", outStrng);
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
                decryptRotation(x, outStrng);
                printf("\nThe result is: %s\n", outStrng);
                fprintf(out, "%s", outStrng);
                printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file
                scanf("%s", &z);
                if (z == 'y')
                {
                    printf("\nAre you sure? y or n: ");
                    scanf("%s", &z);
                }
                if (z == 'y')
                {
                    in = fopen(inputName, "w");
                    fprintf(in, "%s", outStrng);
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
        if (key == NULL)         //prints user friendly error outStrng
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
            encryptSubstitution(keyStrng, outStrng);
            fprintf(out, "%s", outStrng);
            printf("\nThe encrypted outStrng is: %s\n", outStrng);
            printf("\nWould you like to overwrite %s? with the encrypted text? y or n: ", inputName); //option to overwrite the input file so that the decrypt function can be tested
            scanf("%s", &z);
            if (z == 'y')
            {
                printf("\nAre you sure? y or n: ");
                scanf("%s", &z);
            }
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", outStrng);
            }
        }
        else if(q == 2)
        {
            decryptSubstitution(keyStrng, outStrng);
            fprintf(out, "%s", outStrng);
            printf("\nThe encrypted outStrng is: %s\n", outStrng);
            printf("\nWould you like to overwrite %s with the encrypted text? y or n: ", inputName); //option to overwrite the input file
            scanf("%s", &z);
            if (z == 'y')
            {
                printf("\nAre you sure? y or n: ");
                scanf("%s", &z);
            }
            if (z == 'y')
            {
                in = fopen(inputName, "w");
                fprintf(in, "%s", outStrng);
            }
        }
        fclose(key);
    }
    /*---Rotation Without Key---*/
    else if (c == 3)
    {
        char strng[1000];
        for (i=0; i<1000; i++)
        {
            strng[i] = outStrng[i];
        }
        rotationGuess(strng);
    }
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
//------------------------------------------------------
void rotationGuess(char *strng)
{
    FILE *out;
    out = fopen("output.txt", "w+");
    if (out == NULL)         //prints user friendly error message
    {
        perror("ERROR : fopen()");
    }
    int i;
    char outStrng[1000];
    int l, s, e, o, t, f, p, r; //in order of most common pairs of letters
    int counter = 0;
    for (i=0; i<1000; i++)
    {
        if (counter < 3)
        {
            if (strng[i] >= 65 && strng[i] <=90)
            {
                if (strng[i] == strng[(i)+1])
                {
                    l = 76 - strng[i];
                    if (l <= 0)
                        l = l + 26;
                    s = 83 - strng[i];
                    if (s <= 0)
                        s = s + 26;
                    e = 69 - strng[i];
                    if (e <= 0)
                        e = e + 26;
                    o = 79 - strng[i];
                    if (o <= 0)
                        o = o + 26;
                    t = 84 - strng[i];
                    if (t <= 0)
                        t = t + 26;
                    f = 70 - strng[i];
                    if (f <= 0)
                        f = f + 26;
                    p = 80 - strng[i];
                    if (p <= 0)
                        p = p + 26;
                    r = 82 - strng[i];
                    if (r <= 0)
                        r = r + 26;
                    
                    printf ("New loop\n");
                    fprintf (out, "New loop\n");
                    
                    decryptRotationNoKey(l, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", l, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", l, outStrng);
                    
                    decryptRotationNoKey(s, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", s, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", s, outStrng);
                    
                    decryptRotationNoKey(e, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", e, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", e, outStrng);
                    
                    decryptRotationNoKey(o, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", o, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", o, outStrng);
                    
                    decryptRotationNoKey(t, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", t, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", t, outStrng);
                    
                    decryptRotationNoKey(f, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", f, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", f, outStrng);
                    
                    decryptRotationNoKey(p, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", p, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", p, outStrng);
                    
                    decryptRotationNoKey(r, strng, outStrng);
                    printf("\nThe rotation could be %d: %s\n", r, outStrng);
                    fprintf(out, "Rotation: %d\n%s\n", r, outStrng);
                    
                    counter++;
                    
                }
            }
        }
    }
    printf("\n\n/-------------------------------/\n");
    printf("You can now find which rotation value worked, run the program again and select decrypt rotation to decode the original outStrng\n");
}
//------------------------------------------------------
void decryptRotationNoKey(int x, char *strng, char *outStrng)
{
    for(int i = 0; i < 1000; i++)
    {
        outStrng[i] = strng[i];
        if (outStrng[i] >= 65 && outStrng[i] <=90)
        {
            outStrng[i] = outStrng[i] + x;
            if ((outStrng[i] > 90 )&& (outStrng[i] <= 90+x))
                outStrng[i] = outStrng[i] - 26;
        }
    }
}
