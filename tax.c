#include <stdio.h>
#include <math.h>
// tax according to old regime
float old(int x,long long d,float tx){
    int t;
     if(x<5){
      t = (d - 250000)/20;
      tx = (float) t;
     }
     else if(x<10){
      t = 12500 + (d-500000)/5;
      tx = (float) t;
      
     }
     else {
      t = 12500 + 50000 + ((d-1000000)*3/10);
      tx = (float) t;
     }
     return tx;
}
// tax according to new regime
float new(int x,long long d,float tx){
  int l;
    if(x==3){
      tx = 0;
     }
    else if(x<6){
      l = (d-300000)/20;
      tx = (float) l;
     }
    else if(x<9){
      l = 15000 + (d-600000)/10;
      tx = (float) l;
     }
    else if(x<12){
      l =15000 + 30000 + ((d-1200000)*15/100);
      tx = (float) l;
     }
    else if(x<15){
      l = 15000 + 30000 + (d-1500000)/5;
      tx = (float) l;
     }
    else {
      l = 15000 + 30000 + 60000 + ((d-1000000)*3/10);
      tx = (float) l;
     }
     return tx;
  
}
// choosing regime
float regime(int x,char t,long long d,float tax){
     if(x<3){
      tax = 0;
     }
     else{
      switch(t){
        case 'o':
        tax = old(x,d,tax);
        break ;
        case 'n':
        tax = new(x,d,tax);
        break ;
      }

    }
    return tax;
  }
// the amount on which tax can be imported
long long taxableamount(int r, int g,long long m){
  long long d;
   r = r - (r*3/10);
   g = g - (g*15/100);
   d = m + g + r;
   return d;

}


int main() {
    int a,r,g,x;
    long long m,d;
    float tax;
    char h,t,k,u,v;
    printf(" enter your income excluding land property and capital gain\n");
    scanf("%lld", &m);
    x = m/100000;
    printf("enter the number of your itr \n");
    scanf("%d", &a);
    if(a<5){//  for itr 1 to 4
      printf("do you have any of  these \n");
      printf(" type y for yes and n for no\n");
      printf("1 - more than one house\n");
      printf("2 - capital gain\n");
      scanf(" %c", &h);
       if(h=='n'){
        printf("choose you regime\n");
        printf("write o for old, n for new\n");
        scanf(" %c",&t);
        tax = regime(x,t,m,tax);
        tax = tax + (tax/25);
      }
      else if(h=='y'){
        printf("enter house rental income\n");
        scanf("%d",&r);
        printf("enter your capital gain\n");
        scanf("%d",&g);
        d = taxableamount(r,g,m);
        printf("choose you regime\n");
        printf("write o for old, n for new\n");
        scanf(" %c",&t);
        tax = regime(x,t,m,tax);
        tax = tax + (tax/25);
        
      }
      else{
        printf("not valid\n");
      }

    }
    else if (a=5){// for itr 5
        printf("enter house rental income\n");
        scanf("%d",&r);
        printf("enter your capital gain\n");
        scanf("%d",&g);
        d = taxableamount(r,g,m);
        tax = m*3/10;
        tax = tax + (tax/25);
        
    }
    else if (a=6){// for itr 6
      printf("enter house rental income\n");
      scanf("%d",&r);
      printf("enter your capital gain\n");
      scanf("%d",&g);
      d = taxableamount(r,g,m);
      printf(" is company is new\n");
      printf(" type y for yes and n for no\n");
      if (k='y'){
      tax = m*22/100;
      tax = tax + (tax*10);
      }
      if(k='n'){
        tax = m/4;
        tax = tax + (tax*10);
      }
      else printf("not valid");
      tax = tax + (tax/25);
    }
    else if(a=7){// for itr 7
      printf("enter house rental income\n");
      scanf("%d",&r);
      printf("enter your capital gain\n");
      scanf("%d",&g);
      d = taxableamount(r,g,m);
      printf("taxable amount is %d\n", d);
      printf("is it a charitable trust\n");
      printf(" type y for yes and n for no\n");
      scanf(" %c",&v);
      if (u='y'){
        tax = 0;
      }
      else if(u='n'){
        tax = d*3/10;
      }
    }
  printf(" tax is %f",tax);
  return 0;
}