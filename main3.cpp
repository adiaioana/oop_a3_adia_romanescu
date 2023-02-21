/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>

bool litera (char ch)
{
    return ((ch>='a' &&ch<='z') || (ch>='A' && ch<='Z'));
}

int comparing (char cuv1[230], char cuv2[230])
{
    if(strlen(cuv1)<strlen(cuv2))
        return -1;
    if(strlen(cuv1)>strlen(cuv2))
        return 1;
        
    for(int i=0; i<strlen(cuv1); ++i)
        if(cuv1[i]>cuv2[i])
            return 1;
        else if(cuv1[i]<cuv2[i])
            return -1;
    return 0;
}

char cuv[230][230];
char str[20000];
char aux[230];

int main()
{
    
    
    int ind=0;
    int nrcuv=0;
    scanf("%[^\n]",str);
    char *p=str;
    int lgstr=strlen(str);
    while(ind<lgstr)
    {
        if(litera(str[ind]) && (ind==0 || !litera(str[ind-1])))
        {
            nrcuv++;
            //prima litera
            int j=ind, poz=0;
            while(j<lgstr && litera(str[j]))
            {
                cuv[nrcuv][poz++]=str[j++];
            }
            ind=j;
            cuv[nrcuv][poz]='\0';
        }
        else ind++;
    }
    
    for(int i=1; i<nrcuv; ++i)
        for(int j=i+1; j<=nrcuv; ++j)
            if(comparing(cuv[i],cuv[j])<0)
            {
                strcpy(aux, cuv[i]);
                strcpy(cuv[i],cuv[j]);
                strcpy(cuv[j],aux);
            }

    for(int i=1; i<=nrcuv; ++i)
        printf("%s\n", cuv[i]);
    return 0;
}
