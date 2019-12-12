#include<stdio.h>
#include<math.h>
#include<string.h>
                                                                                                                                              

long long int p,q,n,t,flag,e[10000000],d[10000000],temp[10000000],j,m[10000000],en[10000000],i;
char msg[10000000];
long long int prime(long long int);
long long int cd(long long int);
void encrypt();
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
      if(t%i==0) continue;
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

void encrypt()
{
  FILE *ptYazma;
  FILE *ptKey;
  ptKey = fopen("Secondkey.txt","wb+");
  ptYazma = fopen("Encrypted.txt", "wb+");
  long long int pt,ct,key=e[0],k,len;
  i=0;
  len=strlen(msg);
  while(i!=len)
  {
      pt=m[i];
      pt=pt-96;
      k=1;
      for(j=0;j<key;j++)
      {
          k=k*pt;
          k=k%n;
      }
      temp[i]=k;
      fprintf(ptKey,"%d ",temp[i]);
      ct=k+96;
      fprintf(ptYazma,"%c",ct);
      en[i]=ct;
      i++;
  }
  en[i]=-1;
  printf("\nTHE ENCRYPTED MESSAGE IS\n");
  for(i=0;en[i]!=-1;i++)
   printf("%c",en[i]);
      
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

int main(){
  printf("\nENTER FIRST PRIME NUMBER\n");
  scanf("%d",&p);
  flag=prime(p);
  if(flag==0)
  {
      printf("\nWRONG INPUT\n");
      return 0;
  }
  printf("\nENTER ANOTHER PRIME NUMBER\n");
  scanf("%d",&q);
  flag=prime(q);
  if(flag==0||p==q)
  {
      printf("\nWRONG INPUT\n");
      return 0;
  }
  
  fflush(stdin);
    long long int i=0,u,o;
    FILE *ptDosya;
    char ch=0,c,filename[100];
    printf("If you want choose different file press(x): ");
    scanf("%c",&u);
    if(u=='x'){
    printf("Enter the filename to open(with extensions): "); 
    scanf("%s", filename); 
	ptDosya = fopen(filename, "r");}
    else{
    ptDosya = fopen("msg.txt", "r");}
    long long int x=0;
    printf("\nENTER MESSAGE\n");
    do {
    	ch = getc(ptDosya);
   		i = ch;
    	if(i != -1){
		printf("%c",ch);
		msg[x]=i;
		x++;}
    } while (ch != EOF);

  for(i=0;msg[i]!=NULL;i++)
    m[i]=msg[i];
  n=p*q;
  t=(p-1)*(q-1);
  ce();
  encrypt();
  return 0;
}
