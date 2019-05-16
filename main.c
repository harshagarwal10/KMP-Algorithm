//
//  main.c
//  kMP on a text file
//
//  Created by Harsh  Agarwal on 30/10/18.
//  Copyright © 2018 Harsh  Agarwal. All rights reserved.
//

#include<stdio.h>
#include<string.h>


char txt[1000],pat[1000],res[2000],replacement[1000];
int M ,N ,R,lps[1000],j=0,i=0,patlen,topR=0,top=0;
void computeLPSArray()
{
    int len = 0, i;
    lps[0] = 0;
    i = 1;
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if( len != 0 )
                len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch()
{
    int j=0,i=0,index[10] ,a,z=0,k=0;
    M = strlen(pat);
    N = strlen(txt);
    R = strlen(replacement);
    computeLPSArray();
    while(i < N)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }
        
        if (j == M)
        {
            printf("Found pattern at index %d \n", a=i-j+1);
            // add replacement text here
            for(int it=0;it<R;it++){
                res[topR++]=replacement[it];
            }
            index[z]=a;
            z++;
            j = lps[j-1];
        }
        else if(pat[j] != txt[i])
        {
            // add the text which is already present
            res[topR++]=txt[i];
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    for (a=0;a<z;a++){
        txt[index[a]]= pat;
    }
}


int main(int argc, char const *argv[])
{
    FILE *fptr1;
    char ch;
    top=0;
    fptr1 = fopen("data.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr1);
    
    while (ch != EOF)
    {
        txt[top++] = ch;
        ch = fgetc(fptr1);
        
    }
    fclose(fptr1);
    
    int a;
    char sentence[1000];
    FILE *fptr;
    fptr = fopen("program.txt", "w");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("%s\n", txt);
    printf("\n ENTER THE PATTERN : ");
    gets(pat);
    printf("\n ENTER THE replacement : ");
    gets(replacement);
    KMPSearch();
    printf("%s\n", res);
    fprintf(fptr,"%s\n", res);
    fclose(fptr);
    return 0;
}
