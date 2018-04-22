#include<iostream>
#include<cstring>
using namespace std;
class ATM
{
    protected:
    int searchp[8]={1234,3897,4567,2456,3625,9875,2304};
    int pas,sel,h;
    bool valid = false;
    int line,my;
    int counter;
    public:
void choice()
        {
while (!valid)
{
    cout<<"Enter Your Password : ";
    cin>>line;
for(counter = 0; counter < 8; counter++)
{
     if(line == searchp[counter])
        valid = true;
}}
if(valid=true)
{
       cout<<"Please select an option to continue"<<endl<<endl;
       cout<<"\t1)Fast Cash\t2)Bill Payment"<<endl;
       cout<<"\t3)Cash Withdrawal\t4)Cash Deposit"<<endl;
       cout<<"\t5)Balance Inquiry\t7)Funds Transfer"<<endl;
       cout<<"\t\t7)exit"<<endl;
}
else
    {
    valid=false;
}
}
};
class operation:public ATM
{
private:
    int bmc,cho,bill,amount,bal,cwdch,mon,dep,fund,tan,selbill,sch,fip,bich,cdch;
public:
    operation(){bal=50000;}
void fastcash()
{
cout<<"Fast cash = 30000 rs "<<endl;
cout<<"Your Account Balance is :"<<bal<<endl;
cout<<"\t(0)Return to Main menu"<<endl;
cin>>bmc;
//cout<<"fast cash input"<<endl;
    myfunc(bmc);
}
    void billpayment()
{
    try
    {
    cout<<"\tPlease select an option to continue"<<endl;
    cout<<"\t1)Gas Bill\t2)Electricity Bill"<<endl;
    cout<<"\t3)Land line Bill\t0)Return to main menu"<<endl;
    cin>>bill;
   if(bill==0)
    {
       myfunc(bill);
    }
     if(bill==1 || bill ==2)
     {
    cout<<"Please enter amount"<<endl;
    cin>>amount;
    if(amount<0 || amount>bal)
    {
      throw amount;
    }
    else
    {
    cout<<"Please select your account type"<<endl;
    cout<<"\t1)Saving\t2)Checking"<<endl;
    cout<<"\t0)Return to main menu"<<endl;
    cin>>sel;
     if(sel==0)
    {
    cout<<"\tPlease select an option to continue"<<endl;
    cout<<"\t1)Gas Bill\t2)Electricity Bill"<<endl;
    cout<<"\t3)Land line Bill\t0)Return to main menu"<<endl;
    }
    cin>>selbill;

    if(selbill==0)
    {
      myfunc(selbill);
    }

    if(sel==1 || sel==2)
    {
    bal=bal-amount;
    cout<<"Bill is Successfully paid"<<endl;
    cout<<"Your account balance is :"<<bal<<endl;
    }
    }
    }
    }
    catch(int eamount)
    {
        cout<<"Error in amount"<<endl;
        cout<<"Re Enter amount"<<endl;
    }
    while(sel==0);
}
        void cashwithdrawl()
{
cout<<"Your Account Balance is :"<<bal<<endl;
while(1)
try{
cout<<"Enter money to draw"<<endl;
cin>>mon;
if(mon<=0 || mon>bal)
{
    throw mon;
}
else
{
bal=bal-mon;
cout<<"Amount :"<<mon<<endl;
cout<<"Your Account Balance is :"<<bal<<endl;
cout<<"(0)To return to main menu"<<endl;
cin>>cwdch;
myfunc(cwdch);
break;
}
}
catch(int m)
{
    cout<<"Error Occurring"<<endl;
    cout<<"Re Enter"<<endl;
}
}
        void cashdeposit()
{
    cout<<"Your Account Balance is : "<<bal<<endl;
    cout<<"Enter money to Add : ";
    cin>>dep;
    bal=bal+dep;
    cout<<"Now your Account Balance is :"<<bal<<endl;
    cout<<"\t(0)To return main menu"<<endl;
    cin>>cdch;
    myfunc((cdch));
}
        void balanceinquary()
{
    cout<<"Your Account Balance is : "<<bal<<endl;
    cout<<"Last Time Cash Draw is : "<<mon<<endl;
    cout<<"\t(0)To return main menu"<<endl;
    cin>>bich;
    myfunc((bich));
}
void fundstransfur()
{
while(1)
    {
    try
    {
        cout<<"Enter account number to transfer fund"<<endl;
        cin>>tan;
        cout<<"Enter fund to transfer"<<endl;
        cin>>fund;
        if(fund>bal || fund<=0)
        {
            throw fund;
        }
        else
        {
            cout<<"Fund is successfully transferred!"<<endl;
            cout<<"Fund transfered account number :"<<tan<<endl;
            bal=bal-fund;
            cout<<"\t(0)To return main menu"<<endl;
            cin>>fip;
            myfunc((fip));
          // call();
        }
    }
    catch(int f)
    {
    cout<<"Entered fund is greater than your Account Balance"<<endl;
    cout<<"Re enter!"<<endl;
}
}
}
void myfunc(int no)
        {
    switch(no)
    {
    case 1:
    fastcash();
    break;
    case 2:
    billpayment();
    break;
    case 3:
    cashwithdrawl();
    break;
    case 4:
    cashdeposit();
    break;
    case 5:
    balanceinquary();
    break;
    case 6:
    fundstransfur();
    break;
    case 0:
   call();
   case 7:
   endatm();
    }
        }
void call()
    {
choice();
    cin>>sch;
    myfunc(sch);
    }

    void endatm()
    {
        while(cho==7)
    {
        cout<<"Thank you for using ATM..."<<endl;
        break;
    }}
};
int main()
{
    int cho;
    operation opr;
    opr.choice();
    cin>>cho;
    opr.myfunc(cho);
}
