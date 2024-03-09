// cars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
//function prototypes
double calcBasicPrice(char);
int calcKmTraveled(int);
void calcAmountDue(int&, int&);
void displayFinalAmount(string, int&);
int main()
{
    //variable declaration
    string name = " ";
    char code = ' ';
    int basicAmount = 0;
    int currentKm;
    int difference = 0;
    int amountDue = 0;
    //allow user to enter values
    cout << "Enter customer's name : " << endl;
    cin >> name;
    cout << "Car code : " << endl;
    cin >> code;
    while (code != 'c' && code != 'C' && code != 't' && code != 'T' && code != 'y' && code != 'Y')
    {
        //allow user to enter code until correct code is entered
        cout << "Incorrect code is entered. Enter valid code : " << endl;
        cin >> code;
    }
    basicAmount = calcBasicPrice(code);
    //allow user to enter current kilometers
    cout << "Enter current kilometers travelled : " << endl;
    cin >> currentKm;
    difference = calcKmTraveled(currentKm);
    void calcAmountDue(int& basicAmount,int& difference);
    void displayFinalAmount(string name, int& amountDue);
    _getch();
    return 0;
}
//first function
double calcBasicPrice(char carCode)
{
    double basicRentAmount = 0.0;
    const int COROLLA = 300;
    const int TAZZ = 250;
    const int YARIS = 220;

    //calculation of basic rent amount for each car using ladder if
    if (carCode == 'c' || carCode == 'C')
    {
        basicRentAmount += COROLLA;
    }
    else if (carCode == 't' || carCode == 'T')
    {
        basicRentAmount += TAZZ;
    }
    else  if (carCode == 'y' || carCode == 'Y')
    {
        basicRentAmount += YARIS;
    }
        return basicRentAmount;
}
//second function
int calcKmTraveled(int currentKm)
{
    int random;
    int initialKm;
    int difference = 0;
    //generate initial kilometers
    random = 0 + rand() % (10000 - 0 + 1);
    initialKm = random;
    //introduction of if statement
    if (initialKm < currentKm)
    {
        //calculation of difference
        difference = currentKm - initialKm;
    }
    else
    {
        //generate until condition is met
        while (initialKm > currentKm)
        {
            random = 0 + rand() % (10000 - 0 + 1);
            //then calculate the difference
            difference = currentKm - initialKm;
        }
    }
    //return difference
    return difference;

}
//third function
void calcAmountDue(int& basicAmount, int& kM)
{
    int amountDue = 0;
    int newKm = 0;
    const int PER_KM = 10;
    //calculation of discount using ladder if statement
    if (kM > 200 && kM <= 500)
    {
        //decrease kilometers
        newKm = kM - 50;
        amountDue = (newKm * PER_KM)+basicAmount;
    }
    else if (kM > 500 && kM <= 1000)
    {
        //decrease kilometers
        newKm = kM - 120;
        amountDue = (newKm * PER_KM) + basicAmount;
    }
    else if (kM > 1000)
    {
        //decrease kilometers
        newKm = kM - 200;
        amountDue = (newKm * PER_KM)+ basicAmount;
    }
}
//fourth function
void displayFinalAmount(string customerName, int& amountDue)
{
    //display information to user
    cout << fixed << setprecision(2) << endl;
    cout << "Customer name : " << customerName << endl;
    cout << "Final amount due : R" << amountDue << endl;
}