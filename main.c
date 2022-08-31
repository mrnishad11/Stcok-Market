#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
details()
{
FILE *fptr; 
char filename[100], c; 
printf("Enter Your user ID: \n"); 
scanf("%s", filename); 
fptr = fopen(filename, "r"); 
if (fptr == NULL) 
{ 
printf("\n Invalid User ID: \n"); 
exit(0); 
} 
c = fgetc(fptr); 
do
{ 
printf ("%c", c);
c = fgetc(fptr); 
}while (c != EOF); 
fclose(fptr); 
}
login()
{
FILE *p;
char log[20];	
int pass,choice;
printf("\nEnter Your Login ID:");
scanf("%s",&log);
p=fopen(log,"r");
if(p==NULL)
{
printf("\nYou Entered Wrong User Id:");
main();
}
fclose(p);
printf("\nEnter Your Password:");
scanf("%d",&pass);
if(pass==123)
{
printf("\n you are successfullly logged In...:");
do{
printf("\n1.View Your Details:");
printf("\n2.Trade");
printf("\n3.Exit");
printf("\nPlease enter your choice:");
scanf("\n%d",&choice);
switch(choice)
{
case 1:details();
break;
case 2:trade();
break;
case 3:continue;
break;
default:printf("\nWrong Input Please Enter Again:");
}
}while(choice!=3);
}
else
{
printf("\nWrong Password \n Redirecting to main menu Press any key:");
getch();
}	
}
signup()
{
FILE *w;
int pass=123;
char f_name[10],l_name[10],email[30],id[15],ac_no[25],bank_name[20];
printf("\nEnter Your First Name :");
scanf("%s",&f_name);
printf("\nEnter Your Last Name :");
scanf("%s",&l_name);
printf("\nEnter Your Email :");
scanf("%s",&email);
printf("\nEnter Your Bank Name:");
scanf("%s",bank_name);
printf("\nEnter Your Bank Account No:");
scanf("%s",&ac_no);
printf("\nEnter Your User ID(combination of number & letter)(not more than 10 letters):");
scanf("%s",&id);
printf("\nYour are Id and Password Successfully Genrated:");
printf("\nUse This For Login:\nID=%s\nPassword=123",id);
w=fopen(id,"w");
fprintf(w,"\nName =%s %s\nE-mail=%s\nID=%s\nPassword=%d\nBank Name=%s\nAccount No=%s",f_name,l_name,email,id,pass,bank_name,ac_no);
fclose(w);
getch();
}
trade()
{
	FILE *f,*q;
int withdraw=0;
char fname[20];
int amount=0,buy_choice,sell_choice,choice;
int shares=0,total_share=0;
float y=0,avg_price=0,share_price=187.25,total_invest_amount=0,invest_amount=0;
int t_shares=0,t_total_share=0;
float t_avg_price=0,t_share_price=134.78,t_total_invest_amount=0,t_invest_amount=0;
int a_shares=0,a_total_share=0;
float a_avg_price=0,a_share_price=24.13,a_total_invest_amount=0,a_invest_amount=0;
printf("\nFor securities reason please Enter your login id:");
scanf("%s",&fname);
q=fopen(fname,"r");
if(q==NULL)
{
printf("\nYou entered wrong user id");
main();
}
fclose(q);
f=fopen(fname,"a");
printf("\nAdd Balance To Your Account:");
scanf("%d",&amount);
fprintf(f,"\nCredit Balance:%d",amount);
fclose(f);
while(choice!=3)
{
buy_sell:
printf("\n1.Buy");
printf("\n2.Sell");
printf("\n3.Back");
printf("\nPlease Enter Your Choice:");
scanf("%d",&choice);	
switch(choice)
{
case 1:printf("\n1.SBI\n2.TATA\n3.Alok Industries\n4.Back\n");
scanf("%d",&buy_choice);
switch(buy_choice)
{
case 1:real();
y=buy();
share_price=y+share_price;
printf("\nAmount:%d",amount);
printf("\nEnter amount to invest:");
scanf("%f",&invest_amount);
f=fopen(fname,"a");
if(invest_amount<=amount && invest_amount>=share_price)
{
fprintf(f,"\nBuy:SBI\n");
fprintf(f,"\nInvest:%f",invest_amount);
amount=amount-invest_amount;
total_invest_amount=total_invest_amount+invest_amount;
shares=invest_amount/share_price;
total_share=total_share+shares;
avg_price=total_invest_amount/total_share;
printf("\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",total_share,avg_price,total_invest_amount);
fprintf(f,"\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",total_share,avg_price,total_invest_amount);
}
else{
	printf("\nInsufficient Balance:");
}
fclose(f);
break;
case 2:real();
y=buy();
t_share_price=y+t_share_price;
printf("\nAmount:%d",amount);
printf("\nEnter amount to invest:");
scanf("%f",&t_invest_amount);
f=fopen(fname,"a");
if(t_invest_amount<=amount && t_invest_amount>=t_share_price)
{
fprintf(f,"\nBuy:TATA\n");
fprintf(f,"\nInvest:%f",t_invest_amount);
amount=amount-t_invest_amount;
t_total_invest_amount=t_total_invest_amount+t_invest_amount;
t_shares=t_invest_amount/t_share_price;
t_total_share=t_total_share+t_shares;
t_avg_price=t_total_invest_amount/t_total_share;
printf("\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",t_total_share,t_avg_price,t_total_invest_amount);
fprintf(f,"\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",t_total_share,t_avg_price,t_total_invest_amount);
}
else{
	printf("\nInsufficient Balance:");
}
fclose(f);

	break;
case 3:real();
y=buy();
a_share_price=y+a_share_price;
printf("\nAmount:%d",amount);
printf("\nEnter amount to invest:");
scanf("%f",&a_invest_amount);
f=fopen(fname,"a");
if(a_invest_amount<=amount && a_invest_amount>=a_share_price)
{
fprintf(f,"\nBuy:ALOK\n");
fprintf(f,"\nInvest:%f",a_invest_amount);
amount=amount-a_invest_amount;
a_total_invest_amount=a_total_invest_amount+a_invest_amount;
a_shares=a_invest_amount/a_share_price;
a_total_share=a_total_share+a_shares;
a_avg_price=a_total_invest_amount/a_total_share;
printf("\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",a_total_share,a_avg_price,a_total_invest_amount);
fprintf(f,"\ntotal share=%d\n Average price=%f\ntotal invest amount=%f\n",a_total_share,a_avg_price,a_total_invest_amount);
}
else{
	printf("\nInsufficient Balance:");
}
fclose(f);
break;
case 4:goto buy_sell;
break;
}
break;
case 2:
printf("\n1.SBI\n2.TATA\n3.Alok Industries\n4.Back\n");
scanf("%d",&sell_choice);
switch(sell_choice)
{
case 1:
if(total_share>0)
{
real();
y=sell();
share_price=y+share_price;
total_invest_amount=total_share*share_price;
printf("\nshare price=%f\ntotal share=%d\nNow invest amount=%f",share_price,total_share,total_invest_amount);
amount=amount+total_invest_amount;
printf("\nAmount=%d",amount);
f=fopen(fname,"a");
fprintf(f,"\nSELL:SBI\n");
fprintf(f,"\nSELL:\nShare price:%f\nTotal Share:%d",share_price,total_share);
fprintf(f,"\nAfter sell invest amount:%f\nTotal Amount:%d",total_invest_amount,amount);
fclose(f);
}
else
{
	printf("\nYou dont't have any SBI Share");
}
break;
case 2:
if(t_total_share>0)
{
	real();
y=sell();
t_share_price=y+t_share_price;
t_total_invest_amount=t_total_share*t_share_price;
printf("\nshare price=%f\ntotal share=%d\nNow invest amount=%f",t_share_price,t_total_share,t_total_invest_amount);
amount=amount+t_total_invest_amount;
printf("\nAmount=%d",amount);
f=fopen(fname,"a");
fprintf(f,"\nSELL:TATA\n");
fprintf(f,"\nSELL:\nShare price:%f\nTotal Share:%d\n",t_share_price,t_total_share);
fprintf(f,"\nAfter sell invest amount:%f\nTotal Amount:%d",t_total_invest_amount,amount);
fclose(f);	
}
else
{
	printf("\nYou dont't have any TATA Share");
}
break;
case 3:
if(a_total_share>0)
{
real();
y=sell();
a_share_price=y+a_share_price;
a_total_invest_amount=a_total_share*a_share_price;
printf("\nshare price=%f\ntotal share=%d\nNow invest amount=%f",a_share_price,a_total_share,a_total_invest_amount);
amount=amount+a_total_invest_amount;
printf("\nAmount=%d",amount);
f=fopen(fname,"a");
fprintf(f,"\nSELL:Alok Industries\n");
fprintf(f,"\nSELL:\nShare price:%f\nTotal Share:%d",a_share_price,a_total_share);
fprintf(f,"\nAfter sell invest amount:%f\nTotal Amount:%d",a_total_invest_amount,amount);
fclose(f);
}
else
{
	printf("\nYou dont't have any Alok Industries Share");
}
break;
case 4:goto buy_sell;
break;
}
break;
case 3:continue;
}
}
while(withdraw!=amount)
{
printf("\nAmount:%d\n",amount);
	printf("\nPlease withdraw all your money...");
scanf("%d",&withdraw);
}
printf("\nAmount successfully transfered to your bank in 2-3 minutes:");
printf("\nThank you for choosing us As your Broker!!!");
}
void real(void)
{
time_t t=time(NULL);
struct tm *tm=localtime(&t);
printf("%s",asctime(tm));
}
int buy()
{
int i;	
srand(time(NULL)); 
i=rand();
i=i-5;
i=i*2;
i=i+13;
i=i%10;
return i; 
}
int sell()
{
int i;	
srand(time(NULL)); 
i=rand();
i=i+11;
i=i*3;
i=i-23;
i=i%10;
return i; 
}
int main()
{
int choice;
do{
	printf("\n.............TRADING...............");
printf("\n1.Login");
printf("\n2.Create a demat account");
printf("\n3.Exit\nPlease Enter Your Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:login();
break;
case 2:signup();
	break;
case 3:exit(0);
break;
default:printf("\nWrong Input Please Enter Correct choice:");
}
}while(choice!=3);
return 0;
}

