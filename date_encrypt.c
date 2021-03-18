#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define STR_LEN 100
#define LI_LEN 10000
#define N 6
//Anton Shepelev. U28654378. This program encrypts a message with a date entered by the user.             //
//The plain text message will be read from a file. The encrypted message will be written to an output file//
void encrypt(char *message, int date[], int n);
int main()
{
    char file_name[STR_LEN],end_file[STR_LEN]; int chislo[N],i;
    char context[LI_LEN+1];

    //!Prompt File Name//
    printf("Enter the file name: ");
    fgets(file_name, STR_LEN, stdin);
    printf("\n %s",file_name);
        //Input Validation(of file name)//
        FILE* container = fopen("input_message.txt", "r");
        if(container == NULL)
        {
            printf("\nError opening the file.");
            return 1;
        }
    //!Prompt the Date//
    printf("Enter date in the format of 6 digit: ");
    for(i=0;i<6;i++)
        scanf("%1d",&chislo[i]);
    //!Copying the text for the encryption and sending it to encrypt function//
        //appending the extension to the file_name
        strcpy(end_file,file_name);
        strncat(end_file,".txt",4);
        FILE* conec = fopen(end_file,"w");
        while(fgets(context,sizeof(context),container)!=NULL)
        {
            encrypt(context,chislo,N);
            fprintf(conec,"%s",context);
        }
    return 0;
}
//!Encrypts the text using 6 digits from date array. We add digit to given letter and write the result
//!message = given text; date = prompted date ; n = number of digits in date(6)
    // for example, to encrypt “Hello World” with 121846, the letter H shifts 1 space,
    //making it I; e shifts two spaces, making it g,
    //and so on until you have finished enciphering.The shifted message is “Igmts Cptml”.
void encrypt(char *message, int date[], int n)
{
    int i=0; char* ch; char temp;
    //!Conversion//
    for(i = 0,ch = message; *ch!='\0';ch++)
    {//after date array reaches n, we reset it
        if(i == n)
            i = 0;
        //Validation of Characters (alphabetic letters only)//
        if(*ch>=65 && *ch<=90)
        {
            *ch+=date[i];
            //OVERFLOW check//
            if(*ch>90)
            {
              temp = *ch;
              temp=temp%90+65;
              *ch = temp;
            }
            i++;
        }
        if(*ch>=97 && *ch<=122)
        {
            *ch+=date[i];
            //OVERFLOW check//
            if(*ch>122)
            {
              temp = *ch;
              temp=temp%122+97;
              *ch = temp;
            }
            i++;
        }
        //writes down the result of encryption of a character
        *(message+i) = *ch;
    }
}
