#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TXT 1024;
#define WORD 30;

const char UP[27]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char LOW[27]= "abcdefghijklmnopqrstuvwxyz";


int gematria(char mot[]){
    int i = 0;
    int sum = 0;
    while (mot[i]!= '\0')
    {
        if (strchr(UP , mot[i])!= NULL)
        {
            sum+= (mot[i]+1-'A');
            //printf("%c->%d\n",mot[i],mot[i]+1-'A');
            
        }
        else if ((strchr(LOW , mot[i])!= NULL))
        {
            sum+= (mot[i]+1-'a');
            //printf("%c->%d\n",mot[i],mot[i]+1-'a');
            
        }else
        {
            i++;
            continue;
        }
        i++;
        // sum += (mot[i]-96);
        // printf("%c->%d\n",mot[i],mot[i]-'A');
        // i++;
    }
    return sum;
}

int gematrialettr(char lettre){
    if (strchr(UP , lettre))
    {
        return (lettre+1-'A');
    }
    else if (strchr(LOW , lettre))
    {
        return (lettre+1-'a');
    }
    else
    {
        return 0;
    }    
}

int minimalGematria(char* phrase,char* mot){
int ref_val = gematria(mot);
int mark = 0;
for (int  i = 0; phrase[i]!='\0'; i++)
{
    if ( (phrase[i]<='Z' && phrase[i]>='A') || (phrase[i]<='z' && phrase[i]>='a'))
    {
        int sum = 0;
        for (int  j = i; phrase[j]!='\0'; j++)
        {
            sum+=gematrialettr(phrase[j]);
            if (sum == ref_val)
            {
                if (mark == 1)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c",phrase[k]);
                }
                mark=1;
                break;
            }
            else if (sum < ref_val)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
}
return 1;
}

char atbashlettr( char lettr ){
    if (strchr(UP,lettr)!=NULL)
    {
        int gap = lettr - 'A';
        int ans = 'Z'-gap;
        return (char)ans;
    }
    else if (strchr(LOW , lettr)!=NULL)
    {
        int gap = lettr - 'a';
        int ans = 'z'-gap;
        return (char)ans;
    }
else
{
    return '\0';
}

}

void atbash(char* mot){
    
    //int sizeM = strlen(mot);
    // char newM[sizeM];

    for (int i = 0; mot[i]!='\0'; i++)
    {
       mot[i] = atbashlettr(mot[i]); 
       //printf("%c",mot[i]);
    }
    
    
}

void reverse(char* mot){
    
    int sizeM = strlen(mot);
    //printf("%d\n",sizeM);
    char* mot_copy = calloc(sizeM,sizeof(char));
    strcpy(mot_copy,mot);
    for (int i = sizeM; i > 0; i--)
    {
        mot[sizeM-i] = mot_copy[i-1];
    }
    //printf("\n%s\n",mot);
    
}

void atbashrunner(char* sequence , char* word){

    int sizeW = strlen(word);
    //printf("mot = %s\n",word);
    // printf("%d",sizeW);
    char* atbash_word = calloc(sizeW,sizeof(char)) ;
    strcpy(atbash_word,word);
    atbash(atbash_word);
    //printf("mot = %s\n",atbash_word);
    
    char* reverseAtbash = calloc(sizeW,sizeof(char));
    strcpy(reverseAtbash,atbash_word);
    reverse(reverseAtbash);
    //printf("mot = %s\n",reverseAtbash);
    // printf("%s",sequence);



    int mark = 0 ;
    int sizeS = strlen(sequence);
    for (int i = 0; sequence[i]!='\0'; i++)
    {
        //printf("1");

        if ( (sizeS - i) >= sizeW )
        {   
            //printf("2");
            char* newAtbashWord = calloc(sizeW,sizeof(char));
            strcpy(newAtbashWord,atbash_word);
            char* curr = calloc(sizeW,sizeof(char));
            if (strchr(newAtbashWord,sequence[i])!=NULL)
            {   
                //printf("2");

                for (int j = i; j < (i + sizeW); j++)
                {
                    curr[j-i] = sequence[j];
                }
                // printf("%s , %s \n",curr , atbash_word);
            
                if ( (strcmp(curr , atbash_word ) == 0 ) || (strcmp(curr , reverseAtbash) == 0) )
                {
                    //printf("1");

                    if (mark == 1)
                    {
                    printf("~");    
                        }
                        for (int k = i; k < (i+sizeW) ; k++)
                        {
                            printf("%c",sequence[k]);
                        }
                        mark = 1;
                        free(newAtbashWord);
                        free(curr);
                } 
                else
                {
                     continue;
                }
                
            }
            else
            {
                continue;
            }
              
        }
        else
        {
            break;
        }
    
    
    }
    free(atbash_word);
    free(reverseAtbash);
    
}

int compareWord(char * mot1 , char* mot2){

    int size1 = strlen(mot1);
    int size2 = strlen(mot2);

    // char* copy1 = calloc(size1,sizeof(char));
    // strcpy(copy1,mot1);

    //  char* copy2 = calloc(size2,sizeof(char));
    // strcpy(copy2,mot2);

    int count[27] = {0};

    if (strchr(mot2,mot1[0])==NULL)
    {
        return 0;
    }
    
    

    for (int i = 0; i < size1; i++)
    {
        int gem = gematrialettr(mot1[i]);
        count[gem]++;
        //printf("place %d = %d\n",gem,count[gem]);
    }
    
    for (int i = 0; i < size2; i++)
    {
       int gem = gematrialettr(mot2[i]);
        count[gem]--;
        //printf("place %d = %d\n",gem,count[gem]);
    }
    
    int check =1;
    for (int i = 1; i < 27; i++)
    {
        if (count[i]!=0)
        {
            check = 0;
        }
        
    }
    // free(copy1);
    // free(copy2);
    return check ; 
    



}

void anagramm( char* string , char* word)
{
    //size sequence 
    int sizeW = strlen(word);
    //word = realloc(word,(sizeW-1)*sizeof(char));
    int sizeS = strlen(string);
    

    //size of the word 
    
    

    // char * copy = calloc(sizeW,sizeof(char));
    // strcpy(copy,word);
    //printf("1");

    
    if (sizeS == 0 || sizeW == 0)
    {
        ;
    }else
    {
        //printf("1");

         
        // initialize counters for sliding windows 
        int left = 0;
        int right = sizeW-1;
        //int count = sizeW ;
        int mark = 0;


        while (right < sizeS)
        {
            //printf("2");
            //check if there is enough letters
            int j = 0;
            for (int i = left; i <= right; i++)
            {
                //if (gematrialettr(string[i]) > 0)
                //{
                    //printf("3");
                    j++;
                //}
                
            }
                if (j == sizeW)
                {
                    
                    //printf("4");
            
                    // get curr word 
                    char * curr_word = calloc((right-left)+1,sizeof(char));
                    int count_curr  = 0;
                    for (int i = left; i <= right; i++)
                    {
                        curr_word[count_curr] = string[i];
                        count_curr++;
                    }
                    //printf("%s\n",curr_word);
                    //check if the word is anagramm
                    //printf("\ncurr = %s , word = %s",curr_word,word);
                    int ans = compareWord(curr_word,word);
                    if (ans == 1)
                    {
                        //printf("5");
                        if (mark == 1)
                        {
                            printf("~");
                        }
                        //printf("\n%s\n",curr_word);
                        for (int  i = left; i <= right; i++)
                        {
                            if (i == right && gematrialettr(string[i]) == 0)
                            {
                                break;
                            }
                            printf("%c",string[i]);
                            mark=1;
                        }
                        
                        
                    }
                    left++;
                    right++;
                free(curr_word);    
                }
                
                else if (j>sizeW)
                {
                    //printf("6");
                    right--;
                }
                else
                {
                   // printf("7");
                    right++;
                }
            
        }
    }
}

