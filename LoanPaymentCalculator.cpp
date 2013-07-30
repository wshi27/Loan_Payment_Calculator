#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class loan
{
              double _principal;
              int _term;
              double _rate;
              double _payment;
              double _paymentDue;
              
      public:
             double calculateInterest (void);
             int remainingMonths (void);
             double currentPrincipal (void);
             double paymentDue(void);
             void paymentMade (double payment);
             loan(double, int, double);
             
};

loan::loan(double principal, int term, double rate)
{ 
  _principal = principal;
  _term = term;
  _rate = rate;  
  _payment = 0;
  _paymentDue = 0;
  
};

double loan::calculateInterest (void)
{
    
    return _rate * _principal;

}

int loan::remainingMonths (void)
{
    return _term;
}

double loan::currentPrincipal (void)
{
       return _principal;
}

double loan::paymentDue(void)
{    
     
     double a = _rate+1;
    _paymentDue = (_principal * _rate * (pow(1+_rate, _term)
				/(pow (1+_rate, _term)-1)));
        return _paymentDue+.005;
}

void loan::paymentMade (double payment)
{    
     if (payment >= _paymentDue)
        _principal = _principal - payment+calculateInterest();
     else 
        {
          cout<<"**Insufficient payment** -- Fee of $25.00 applied"<<endl<<endl;
          _principal = _principal - payment+calculateInterest() + 25.00;
         }
         _term-=1;
}  

int main()
{
    double principal, rate, payment;
    int term;
  
    cout<<"Loan Repayment Calculator Program"<<endl<<endl;
    cout<<"Enter initial loan principal: ";
    cin>>principal;
    cout<<"Enter term of loan in months: ";
    cin>>term;
    cout<<"Enter monthly interest rate: ";
    cin>>rate;
    cout<<endl;
    loan one (principal, term, rate);
      while (true)
   {
    cout<<fixed<<setprecision(2);
    cout<<"Number of months left for loan payment: "
        <<one.remainingMonths()<<endl;
    cout<<"Remaining loan principal: "<<one.currentPrincipal()<<endl;
    cout<<"Interest applied this month: "
        <<one.calculateInterest()<<endl;
    cout<<"Total owed: "<<one.currentPrincipal()+one.calculateInterest()<<endl;
    cout<<"Minimum payment due this month -- "<<one.paymentDue()<<endl<<endl;
    cout<<"Enter payment made this month: ";
    cin>>payment;
    cout<<endl;
    one.paymentMade (payment);
    
    if (0<one.currentPrincipal()<0.01)
    {  
        cout<<"Final loan principal: "<<one.currentPrincipal()<<endl;
        break;
    }
   }

system ("PAUSE");
return 0;
}
