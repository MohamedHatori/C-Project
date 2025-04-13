#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;
const double pi = 3.141592653;
int operation;
void showMenu()
{
    cout<<"Choose The Opertaion"<<endl;
    cout<<"1-> |+|\n2-> |-|\n3->|*|\n4->|/|\n5->|^|\n6->|sqrt|\n7->|sin|\n8->|cos|\n9->|tan|\n";
    cout<<"Choose From 1 - 9"<<endl;
    cin>>operation;
    if(operation<1||operation>9)
    {
        cout<<"Please Choose From 1 to 9"<<endl;
        showMenu();
    }
}
void Calculator()
{
    // char operation;
    // cout<<"Enter The Operation"<<endl;
    // cin>>operation;
    int size;
    double result = 0;
    if(operation >=1 && operation<=5)
    {
        cout<<"Enter How Many Numbers You Wanna Do The Operation on"<<endl;
        cin>>size;
        string Wrong;
        cout<<"If You Enter Wrong Number Enter yes, if you dont Enter no"<<endl;
        cin>>Wrong;
        if(Wrong == "yes"||Wrong=="YES"||Wrong=="yEs")
        {
        cout<<"Enter How Many Numbers You Wanna Do The Operation on"<<endl;
        cin>>size;
        }
        vector<float> arr(size);
        cout<<"Enter The Numbers"<<endl;
        for(int i = 0;i<size;i++)
        {
            cin>>arr[i];
        }
        result = arr[0];
        for(int i = 1;i<size;i++)
        {
            if(operation == 1)
            {
                result+=arr[i];
            }
            else if(operation == 2)
            {
                result-=arr[i];
            }
            else if(operation == 3)
            {
                result*=arr[i];
            }
            else if(operation == 4)
            {
                while(arr[i]== 0)
                {
                    cout<<"You Cannot Divide On zero"<<endl;
                    cin>>arr[i];
                }
                result/=arr[i];
            }
            else if(operation == 5)
            {
                result = pow(arr[0],arr[1]);
                break;
            }
}
}
        if(operation == 6)
        {
            double num;
            cout<<"Enter The Number"<<endl;
            cin>>num;
            result = sqrt(num);
        }
        else if(operation == 7)
        {
            double num;
            cout<<"Enter Your Angle in degress"<<endl;
            cin>>num;
            double radians = num * pi/ 180.0;
            result = sin(radians);
        }
        else if(operation == 8)
        {
            double num;
            cout<<"Enter Your Angle in degress"<<endl;
            cin>>num;
            double radians = num * pi/ 180.0;
            result = cos(radians);
        }
        else if(operation == 9)
        {
            double num;
            cout<<"Enter Your Angle in degress"<<endl;
            cin>>num;
            double radians = num * pi/ 180.0;
            result = tan(radians);
        }
    cout<<"Result = "<<result<<endl;
}
void Again()
{
    bool Again = false;
    cout<<"if you wanna do another math Enter Yes ,if you dont Enter no"<<endl;
    string s;
    cin>>s;
    if(s=="Yes"||s=="yes"||s=="YES")
    {
        Again = true;
    }
    else if(s=="no"||s=="No"||s=="nO"||s=="NO")
    {
        return;
    }
    while(Again)
    {
        showMenu();
        Calculator();
        cout<<"if you wanna do another math Type Yes"<<endl;
        cin>>s;
        if(s=="Yes"||s=="yes"||s=="YES")
        {
            Again = true;
        }
        else if(s=="No"||s=="NO"||s=="nO"||s=="no")
        {
            break;
        }
    }
}
int main()
{
    showMenu();
   Calculator();
   Again();
    return 0;
}