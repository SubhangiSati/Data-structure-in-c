#include<stdio.h> 
#include<string.h> 
int main(){ 
    char str[30];     int i;     printf("Enter the string= ");//entering element in string form     gets(str);     for(i=0;i<=strlen(str);i++)
    { //converting uppercase to lowercase 
        if(str[i]>=65&&str[i]<=90) 
        str[i]=str[i]+32; //adding 32 will make the alphabet lowecase 
    } 
    printf("String in lower case= %s",str); 
} 
