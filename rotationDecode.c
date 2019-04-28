#include <stdio.h>
#include <string.h>

/*---This function takes the input text and converts everything to capital---*/
void textCaps(char *strng);
/* ---This function takes a variable x to rotate the value for each character---*/
void encryptRotation(int x, char *strng, char *outstrng);

/*---Main---*/
int main()
{
    int x;
    char z;
    char constantMessage[1000];
    int i;
    char message[1000];
    char ch;
    FILE *in, *out;
    //char inputName[30];
   // printf("Enter input file name: ");
   // scanf("%s", inputName);
    in = fopen("input.txt", "r");
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

    //---------------------------------------------------------------
    for (i=0; i<1000; i++)
    {
        constantMessage[i] = message[i];
    }
    int a, b, c, d, e, f;
    int counter = 0;
        for (i=0; i<1000; i++)
        {
            if (counter < 2)
            {
                if (constantMessage[i] >= 65 && constantMessage[i] <=90)
                {
                    if (constantMessage[i] == constantMessage[(i)+1])
                    {
                        a = 76 - constantMessage[i]; //l
                        b = 82 - constantMessage[i]; //r
                        c = 84 - constantMessage[i]; //t
                        d = 79 - constantMessage[i]; //o
                        e = 69 - constantMessage[i]; //e
                        f = 83 - constantMessage[i]; //s
                    
                        printf ("message[i] = %d\n", constantMessage[i]);
                        printf ("a: %d, b: %d, c: %d d: %d e: %d f: %d\n", a, b, c, d, e, f);
                        
                        
                        
                        encryptRotation(a, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", a, message);
                        fprintf(out, "%s", message);
                        
                        encryptRotation(b, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", b, message);
                        fprintf(out, "%s", message);
                        
                        encryptRotation(c, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", c, message);
                        fprintf(out, "%s", message);
                        
                        encryptRotation(d, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", d, message);
                        fprintf(out, "%s", message);
                        
                        encryptRotation(e, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", e, message);
                        fprintf(out, "%s", message);
                        
                        encryptRotation(f, constantMessage, message);
                        printf("\nThe rotation could be %d: %s\n", f, message);
                        fprintf(out, "%s", message);
                        
                        counter++;
                        
                    }
                }
            }
        }
    

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
void encryptRotation(int x, char *strng, char *outstrng)
{
    for(int i = 0; i < 1000; i++)
    {
        outstrng[i] = strng[i];
        if (outstrng[i] >= 65 && outstrng[i] <=90)
        {
            outstrng[i] = outstrng[i] + (x);
            if (outstrng[i] > 90 && outstrng[i] <= 90+(x))
                outstrng[i] = outstrng[i] - 26;
            if (outstrng[i] < 65 && outstrng[i] >= 65-(x))
                outstrng[i] = outstrng[i] + 26;
        }
    }
}
]
