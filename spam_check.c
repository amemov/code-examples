#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//Anton Shepelev. U28654378. This program checks if there are any spam words in the string
int read_line(char *str, int n);
int main()
{
    int spamNUM = 0; char input[500];
    //!Prompt Input//
    printf("Input: ");
    read_line(input,500);
    //!Tokenization. Excludes spaces and: !?,.;:^*_=+- //
    char *tiktok = strtok(input," !?,.;:^*_=+-"); // need to include () "" '' 
    //!Checks if the token is spam word//
    while(tiktok!=NULL)
    {
        if(strcmp(tiktok,"suspended")==0)   spamNUM++;
        if(strcmp(tiktok,"locked")==0)      spamNUM++;
        if(strcmp(tiktok,"bank")==0)        spamNUM++;
        if(strcmp(tiktok,"update")==0)      spamNUM++;
        if(strcmp(tiktok,"statement")==0)   spamNUM++;
        if(strcmp(tiktok,"personal")==0)    spamNUM++;

        if(strcmp(tiktok,"click")==0)       spamNUM++;
        if(strcmp(tiktok,"compromised")==0) spamNUM++;
        if(strcmp(tiktok,"deactivated")==0) spamNUM++;
        if(strcmp(tiktok,"reactivate")==0)  spamNUM++;
        if(strcmp(tiktok,"account")==0)     spamNUM++;

        if(strcmp(tiktok,"alert")==0)       spamNUM++;
        if(strcmp(tiktok,"confirm")==0)     spamNUM++;
        if(strcmp(tiktok,"won")==0)         spamNUM++;
        if(strcmp(tiktok,"winner")==0)      spamNUM++;
        if(strcmp(tiktok,"selected")==0)    spamNUM++;
        if(strcmp(tiktok,"claim")==0)       spamNUM++;
        if(strcmp(tiktok,"urgent")==0)      spamNUM++;

        if(strcmp(tiktok,"disabled")==0)    spamNUM++;
        if(strcmp(tiktok,"expire")==0)      spamNUM++;
        if(strcmp(tiktok,"investment")==0)  spamNUM++;
        if(strcmp(tiktok,"refinance")==0)   spamNUM++;
        if(strcmp(tiktok,"pre-approved")==0)spamNUM++;
    tiktok = strtok(NULL," !?,.;:");
    }
    //!OUTPUT//
    printf("Output: %d spam words were found.",spamNUM);
    return 0;
}
int read_line(char *str, int n)
{//!The function stores user's input
          int ch; int i = 0;

          while ((ch = getchar()) != '\n')
          {  if (i < n)
             { *str++= ch;
                i++;
             }
          }
          *str = '\0';   /* terminates string */
          return i;        /* number of characters stored */
}
