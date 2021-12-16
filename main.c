#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

#define TXT 1024
#define WORD 30



int main()
{
   // initialize memory for txt and word 
   char txt[TXT] = {0};
   char word[WORD] = {0};


    //get the word
   int i = 0; 
   while (i<WORD)
   {
       scanf("%c",&word[i]);
        //condition to stop the word
       if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n')
       {     
            i++;
           word[i]='\0';
           break;
       }
      
        i++;
   }
 
   //get the text
   int j = 0;
   while (j<TXT)
   {
       scanf("%c",&txt[j]);
       //condition to stop the text
       if (txt[j] == '~' ){
            break;
       }
      j++;
   }
   printf("Gematria Sequences: ");
   minimalGematria(txt,word);
   printf("\n");
   printf("Atbash Sequences: ");
   atbashrunner(txt,word);
   printf("\n");
   printf("Anagram Sequences: ");
   anagramm(txt,word);
   
   return 0;

}
