#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
void Arithmetic_operations();
void power();
void squareRoot();
void cubeRoot();
void percentage();
void factorial();
void sinval();
void cosval();
void tanval();
void pi_value();
void base10_log();
void Natural_log();
void degreeToRadian();
double DegreeToRadian(double b);
void radianToDegree();
double Inputcheck(double);

int main()
{
        string repeat;
    do 
    {
    cout<<endl<<"   *  Which function do you want to use, Select from the numbers assigned below"<<endl<<endl;
    cout<<"    ________________________________________________________________________________________"<<endl;
    cout<<"    ||  "<<" 1: (+,-,*,/) operations              2: Cube Root              3: Square Root    ||"<<endl;
    cout<<"    ||  "<<" 4: Raised Power                      5: Factorial              6: Percentage     ||"<<endl;
    cout<<"    ||  "<<" 7: Cosine Value                      8: Sine value             9: Tangent value  ||"<<endl;
    cout<<"    ||  "<<"10: Natural log value                11: Log10 value           12: Pi value       ||"<<endl;
    cout<<"    ||  "<<"13: Convert Radians into Degrees     14: Convert Degree into radian               ||"<<endl;
    cout<<"    ||____________________________________________________________________________________||"<<endl;
    int select;
    for (int i=0;i<50;i++)
    {
        cin>>select;        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (select>=1 && select<=14)
        break;
        else
        {
        cout<<"Invalid number, Please try again and make sure you input the correct assigned number"<<endl;
        }
    }
    if (select==1)
    {
        Arithmetic_operations();
    }
    if (select==2)
    {
       cubeRoot();
    }
    if (select==3)
    {
        squareRoot();
    }
    if (select==4)
    {
        power();
    }
    if (select==5)
    {
        factorial();
    }
    if (select==6)
    {
        percentage();
    }
    if (select==7)
    {
        cosval();
    }
    if (select==8)
    {
        sinval();
    }
    if (select==9)
    {
        tanval();
    }
    if (select==10)
    {
        Natural_log();
    }
    if (select==11)
    {
        base10_log();
    }
    if (select==12)
    {
        pi_value();
    }
    if (select==13)
    {
        radianToDegree();
    }
    if (select==14)
    {
        degreeToRadian();
    }
    cout<<"\nDo you want to use calculator again, Press 'yes' if so"<<endl;
    cin>>repeat;
    }
    while (repeat == "yes" || repeat == "YES" || repeat == "Yes");
    return 0;
}
double Inputcheck(double a)
{
    for (int i=1;i<50;i++)
        {
            cin>>a;
            if (cin.fail())
            {
                cerr<<"Invalid input, please enter correct numeric number"<<endl;
                cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            break;
        }
return a;
}
void Arithmetic_operations() 
{
    string input;
    cout << "Enter your desired values and operator[+,-,*,/],Use only single type of operator at a time\n";
    getline(cin, input);
    for (int i=0;i<input.length();i++)
    {
        if (input[i]==' ')
        {
            input.erase(i);
        }
    }
    stringstream ss(input);
    double n;
    vector<double> values;
    while (ss >> n)
    {
        values.push_back(n);
        if (ss.peek() == '*') 
        {
            ss.ignore();
        }
        if (ss.peek() == '/') 
        {
            ss.ignore();
        }
    }

    if (input.find('-') != string::npos) 
    {
        double result = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            result += values[i];
        }
        cout << "=" << result;
    } 
    else if (input.find('+') != string::npos) 
    {
        double sum = 0;
        for (int i = 0; i < values.size(); i++) {
            sum += values[i];
        }
        cout << "=" << sum;
    } 
    else if (input.find('*') != string::npos) 
    {
        double product = 1;
        for (int i = 0; i < values.size(); i++) {
            product *= values[i];
        }
        cout << "=" << product;
    }
    else if (input.find('/') != string::npos) 
    {
        double product = values[0];
        for (int i = 1; i < values.size(); i++) {
            product /= values[i];
        }
        cout << "=" << product;
    }
   else 
   cout<<"ERROR! No operator used\n";

}
void cosval()
{
    cout<<"Enter how many Cosine values do you want to calculate"<<endl;
    int n=Inputcheck(n);
    double values[n];
    for (int i=0;i<n;i++)
    {
        cout<<i+1<<":Cos ";
        values[i]=Inputcheck(values[i]);
    }
    char type;
    do
    {
    cout<<"Is your entered value in degree or radian,enter 'r' or 'd'\n";
    char type;
    cin>>type;
    if (type=='d')
    {
       for (int i=0;i<n;i++)
       {
           double x=values[i];
           values[i]=DegreeToRadian(x);
       }
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<cos(values[i])<<endl;
        }
        break;
    }
    else if (type=='r')
    {
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<cos(values[i])<<endl;
        }
    break;
    }
    else
    cout<<"Please enter 'r' or 'd' to continue\n";
    }
   while (type!='r'||type!='d');

}
void degreeToRadian()
{
    cout<<"Enter your degree's value\n";
    double degree=Inputcheck(degree);
    double pi=3.141592653589793238;
    double radian=degree*(pi/180);
    cout<<"-->"<<degree<<"'= "<<radian<<"rad";
}
double DegreeToRadian(double b)
{
    double degree=b;
    double pi=3.141592653589793238;
    double radian=degree*(pi/180);
    return radian;
}
void sinval()
{
    cout<<"Enter how many Sine values do you want to calculate"<<endl;
    int n=Inputcheck(n);
    double values[n];
    for (int i=0;i<n;i++)
    {
        cout<<i+1<<":Sin ";
        values[i]=Inputcheck(values[i]);
    }
    char type;
    do
    {
    cout<<"Is your entered value in degree or radian\n";
    char type;
    cin>>type;
    if (type=='d')
    {
       for (int i=0;i<n;i++)
       {
           double x=values[i];
           values[i]=DegreeToRadian(x);
       }
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<sin(values[i])<<endl;
        }
        break;
    }
    else if (type=='r')
    {
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<sin(values[i])<<endl;
        }
    break;
    }
    else
    cout<<"Please enter 'r' or 'd' to continue\n";
    }
   while (type!='r'||type!='d');
}
void tanval()
{
    cout<<"Enter how many Tangent values do you want to calculate"<<endl;
    int n=Inputcheck(n);
    double values[n];
    for (int i=0;i<n;i++)
    {
        cout<<i+1<<":Tan ";
        values[i]=Inputcheck(values[i]);
    }
    char type;
    do
    {
    cout<<"Is your entered value in degree or radian\n";
    char type;
    cin>>type;
    if (type=='d')
    {
       for (int i=0;i<n;i++)
       {
           double x=values[i];
           values[i]=DegreeToRadian(x);
       }
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<tan(values[i])<<endl;
        }
        break;
    }
    else if (type=='r')
    {
        for (int i=0;i<n;i++)
        { 
            cout<<i+1<<": = "<<tan(values[i])<<endl;
        }
    break;
    }
    else
    cout<<"Please enter 'r' or 'd' to continue\n";
    }
   while (type!='r'||type!='d');
}
void Natural_log()
{
    cout<<"Enter the value to be calculated\n";
    double value=Inputcheck(value);
    cout<<"ln "<<value<<"= "<<log(value);
}
void base10_log()
{
    cout<<"Enter the value to be calculated\n";
    double value=Inputcheck(value);
    cout<<"lg "<<value<<"= "<<log10(value);
}
void pi_value()
{
    cout<<"Pi value is: "<<3.1415926535897932384626433832795;
}
void squareRoot()
{
    cout<<"Enter the number for its square root value\n";
    double result=Inputcheck(result);
    cout<<"Square root of ("<<result<<")= "<<sqrt(result);
}
void cubeRoot()
{
    cout<<"Enter the number for its cube root value\n";
    double result=Inputcheck(result);
    cout<<"Cube root of ("<<result<<")= "<<cbrt(result);
}
void power()
{
    cout<<"Enter the value\n";
    double valu=Inputcheck(valu);
    cout<<"Enter its raised power\n";
    double r=Inputcheck(r);
    double product=valu;
    for (int i=1;i<r;i++)
    {
        product*=valu;
    }
    cout<<valu<<" raised to power "<<r<<" = "<<product;
}
void factorial()
{
    cout<<"Enter the number for its factorial\n";
    double fact=Inputcheck(fact);
    double product=1;
    for (int i=1;i<=fact;i++)
    {
        product*=i;
    }
    cout<<fact<<"!= "<<product;
}
void percentage()
{
    cout<<"Enter the value\n";
    double value=Inputcheck(value);
    cout<<"Enter the total value\n";
    double totalvalue=Inputcheck(totalvalue);
    cout<<(value/totalvalue)*100<<"%";
}
void radianToDegree()
{
    cout<<"Enter your radian's value\n";
    double radian=Inputcheck(radian);
    double pi=3.141592653589793238;
    double degree=radian*(180/pi);
    cout<<"-->"<<radian<<"rad= "<<degree<<"'"; 
}