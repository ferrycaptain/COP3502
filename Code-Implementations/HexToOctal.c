#include <stdio.h>
#include<math.h>
#include<string.h>
int hex_octal(char hex[]);

int main()
{

char hex[20],c;
int n;
printf("Enter hexadecimal number: ");
scanf("%s",hex); printf("Octal number: %d",hex_octal(hex));
return 0;
}

int hex_octal(char hex[]) /* Function to convert hexadecimal to octal.
*/
{
int i,length, decimal=0, octal=0;

for(length=0; hex[length]!='\0'; ++length); for(i=0; hex[i]!='\0'; ++i,
--length)
{
if(hex[i]>='0' && hex[i]<='9') decimal+=(hex[i]-'0')*pow
(16,length-1);
if(hex[i]>='A' && hex[i]<='F') decimal+=(hex[i]-55)*pow(16,length-1);
if(hex[i]>='a' && hex[i]<='f') decimal+=(hex[i]-87)*pow(16,length-1);
} /* At this point decimal contains the decimal value of given
hexadecimal number. */
i=1;
while(decimal!=0)
{
octal+=(decimal%8)*i;
decimal/=8;
i*=10;
}

return octal;

}
