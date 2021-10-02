#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){

char
cipher[]="PXPXKXENVDRUXVTNLXHYMXGMAXYKXJNXGVRFXMAHWGXXWLEHGZXKVBIAXKMXQM";
printf("18bce0420\n");
for(int i=0;i<26;i++){
printf("Key: %d\n",i);
for(int j=0;cipher[j];j++){
printf("%c",((cipher[j]-65-i+26)%26+65));
}
printf("\n");
}
}
