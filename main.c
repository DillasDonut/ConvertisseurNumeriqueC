#include<stdio.h>
#include<string.h>


char* reversestring(char *a)
{
    int i,l;
    char *r;

    l=strlen(a);
    r=(char*)
    malloc(l*sizeof(char));

    for(i=0;i<l;i++)

    r[i]=*(a+l-i-1);
    r[i]='\0';

    return r;
}


//Fonction de calcul de decimal a hexadecimal
char* DecToHex(int dec)
{
    char hex[10];
    int i=0,tnum,rem;
    tnum=dec;
    while(tnum!=0)
    {
        rem=tnum%16;
        hex[i++]=rem<=9?'0'+rem:'A'+rem-10;
        tnum/=16;
    }
    hex[i]='\0';
    return(reversestring(hex));
}


//Fonction de calcul de decimal a octal
int DecToOct(int dec)
{
    int oct=0;
    int i=1,tnum,rem;
    tnum=dec;

    while(tnum!=0)
    {
        rem=tnum%8;
        oct=i*rem+oct;
        tnum/=8;
        i=i*10;
    }

    return(oct);
}

//Fonction de calcul de decimal a binaire
int DecToBin(int dec)
{
    int bin=0;
    int i=1,tnum,rem;
    tnum=dec;

    while(tnum!=0)
    {
        rem=tnum%2;
        bin=i*rem+bin;
        tnum/=2;
        i*=10;
    }

    return(bin);
}


//Fonction de calcul de binaire a decimal
int BinToDec(int bin)
{
    int rem,dec=0,base=1;
    int num;
    num=bin;

    while(num>0)
    {
      rem = num % 10;
      dec = dec + rem * base;
      num = num / 10 ;
      base = base * 2;
    }

    return dec;
}


//Fonction de calcul de hexadecimal a decimal
int HexToDec(char* hex)
{
    int dec=0,base=1,i,d;
    char c;
    i=strlen(hex)-1;

    while(i>=0)
    {
        c=*(hex+i);
        if(c>='A'&&c<='F')
          d=10+c-'A';
        else if(c>='a'&&c<='f')
          d=10+c-'a';
        else
          d=c-'0';

        dec+=d*base;
        base*=16;
        i--;
    }

    return dec;
}


//Fonction de calccul de octal a decimal
int OctToDec(int oct)
{
    int dec=0,base=1;
    int t;
    t=oct;

    while(t>0)
    {
        dec+=(t%10)*base;
        t/=10;
        base*=8;
    }

    return dec;
}


int
 main()
{
    int inputnum,from,to,fromto,out;
    char inputs[10];
    char *outs;

    printf("\nChoose the number system to convert from.\n");
    printf("From:\n1.Decimal\n2.Binary\n3.Octal\n4.Hexadecimal\n");
    scanf("%d", &from);
    printf("\nenter the number.\n");

    if(from<4)
      scanf("%d",&inputnum);
    else
      scanf("%s",inputs);

    printf("Choose the number system to convert to.\n");
    printf("To:\n1.Decimal\n2.Binary\n3.Octal\n4.Hexadecimal\n");
    scanf("%d", &to);

    fromto=from*10+to;
    switch(fromto)
      {
          case 12:out=DecToBin(inputnum);
          break;

          case 13:out=DecToOct(inputnum);
          break;

          case 14:outs=DecToHex(inputnum);
          break;

          case 21:out=BinToDec(inputnum);
          break;

          case 23:out=DecToOct(BinToDec(inputnum));
          break;

          case 24:outs=DecToHex(BinToDec(inputnum));
          break;

          case 31:out=OctToDec(inputnum);
          break;

          case 32:out=DecToBin(OctToDec(inputnum));
          break;

          case 34:outs=DecToHex(OctToDec(inputnum));
          break;

          case 41:out=HexToDec(inputs);
          break;

          case 42:out=DecToBin(HexToDec(inputs));
          break;

          case 43:out=DecToOct(HexToDec(inputs));
          break;
      }

    if(to==4)
      printf("\n%s",outs);
    else
      printf("\n%d",out);

}
