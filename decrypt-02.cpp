#include<stdio.h>
#include<math.h>

long long int p,q,n,t,flag,e[10000000],d[10000000],temp[10000000],j,m[10000000],en[10000000],i;
char msg[10000000];
long long int prime(long long int);
long long int cd(long long int);
void encrypt();
void decrypt();
void ce();

long long int prime(long long int pr){
  long long int i;
  j=sqrt(pr);
  for(i=2;i<=j;i++)
  {
      if(pr%i==0)
      return 0;
  }
  return 1;}
  
void ce()
{
  long long int k;
  k=0;
  for(i=2;i<t;i++)
  {
      if(t%i==0)
      continue;
      flag=prime(i);
      if(flag==1&&i!=p&&i!=q)
      {
          e[k]=i;
          flag=cd(e[k]);
          if(flag>0)
          {
              d[k]=flag;
              k++;
          }
          if(k==99)
          break;
      }
  }
}

void decrypt()
{
  FILE*ptYazma;
  FILE*ptKey;
  FILE*ptResult;
  ptResult = fopen("Result.txt","wb+");
  ptYazma = fopen("Encrypted.txt","r");
  ptKey = fopen("Secondkey.txt","r");
  long long int pt,ct,key=d[0],k;
  i=0;
    long long int x=0,eks,sum=0,zt=0;
    char ch=0;
    do {
    	ch = getc(ptKey);
    	if(ch =='-'){
    		zt=1;
		}
    	if(ch !=' '){
    		if(ch>='0' && ch<='9'){
    	long long int real=ch-48;
        sum=real+sum;
        sum=sum*10;
		}
		
	}
		else{
			if(zt==1){
			sum=sum/10;
			sum=sum-(sum*2);
			zt=0;
			temp[x]= sum;
			x++;
			sum=0;}
			else{
			sum=sum/10;
			temp[x]= sum;
			x++;
			sum=0;}	
		}
}
		
     while (ch != EOF);
  while(en[i]!=-1)
  {
      ct=temp[i];
      k=1;
      for(j=0;j<key;j++)
      {
          k=k*ct;
          k=k%n;
      }
      pt=k+96;
      msg[i]=pt;
      i++;
  }
  msg[i]=-1;
  printf("\nTHE DECRYPTED MESSAGE IS\n");
  for(i=0;msg[i]!=-1;i++){
  fprintf(ptResult,"%c",msg[i]);
  printf("%c",msg[i]);}
  printf("\n");
}

long long int cd(long long int x)
{
  long long int k=1;
  while(1)
  {
      k=k+t;
      if(k%x==0)
      return(k/x);
  }
}

int main()
{
  printf("\nENTER FIRST PRIME NUMBER\n");
  scanf("%d",&p);
  flag=prime(p);
  if(flag==0)
  {
      printf("\nWRONG INPUT\n");
      return 1;
  }
  printf("\nENTER ANOTHER PRIME NUMBER\n");
  scanf("%d",&q);
  flag=prime(q);
  if(flag==0||p==q)
  {
      printf("\nWRONG INPUT\n");
      return 1;
  }
  printf("\nENTER MESSAGE\n");
  fflush(stdin);
    long long int i=0;
    FILE *ptDosya;
    char ch=0;
    ptDosya = fopen("Encrypted.txt", "r");
    long long int x=0;
    do {
    	ch = getc(ptDosya);
   		i = ch;
    	if(i != -1){
		printf("%c",ch);
		msg[x]=i;
		x++;
	}
		
    } while (ch != EOF);
    printf("\n");
    en[x]=-1;
  n=p*q;
  t=(p-1)*(q-1);
  ce();
  decrypt();
  return 0;
}
