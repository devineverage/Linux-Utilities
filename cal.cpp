#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;


int month;
int year;
int firstday;
int firstDayOfMonth;
int count = 1;


void firstDay(){
//This part determines which day will be the first day of that year (0 for Sunday, 1 for Monday, etc.)
int day=1;
int y = year - (14-month)/12;
int m = month +12 * ((14-month) / 12) -2;
firstday = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;


}

void print(){

int NumberOfDaysInMonth;

int DayOfWeekCounter = 0;



switch (month)
{
  case 1:
cout<<setw(12)<<"January "<<year;
NumberOfDaysInMonth = 31;
  break; 
  case 2:
cout<<setw(12)<<"February "<<year;
if (((year > 1752 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))||(year <= 1752 && year % 4 == 0))
  NumberOfDaysInMonth = 29;
else
  NumberOfDaysInMonth = 28;
  break;
  case 3:
cout<<setw(10)<<"March "<<year;
NumberOfDaysInMonth = 31;
  break;
  case 4:
cout<<setw(10)<<"April "<<year;
NumberOfDaysInMonth = 30;
  break;
  case 5:
cout<<setw(10)<<"May "<<year;
NumberOfDaysInMonth = 31;
  break;
  case 6:
cout<<setw(10)<<"June "<<year;
NumberOfDaysInMonth = 30;
  break;
  case 7:
cout<<setw(10)<<"July "<<year;
NumberOfDaysInMonth = 31;
  break;
  case 8:
cout<<setw(12)<<"August "<<year;
NumberOfDaysInMonth = 31;
  break;
  case 9:
cout<<setw(14)<<"September "<<year;
NumberOfDaysInMonth = 30;
  break;
  case 10:
cout<<setw(12)<<"October "<<year;
NumberOfDaysInMonth = 31;
  break;
  case 11:
cout<<setw(13)<<"November "<<year;
NumberOfDaysInMonth = 30;
  break;
  case 12:
cout<<setw(13)<<"December "<<year;
NumberOfDaysInMonth = 31;
  break;
}

//Display the days at the top of each month

if(year < 1752 || (year == 1752 && month < 9)){
  
  
  cout<<"\nSun Mon Tue Wed Thu Fri Sat";
  
}else{

  cout<<"\nSu Mo Tu We Th Fr Sa";

}
cout<<"\n"<<setw(2);

//Determine where the first day begins
 

switch (firstday)
{
  case 1:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(6);
  
  }else
  cout<< setw(5);
  break;
  case 2:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(11);
  
  }else
  cout<< setw(8);
  break;
  case 3:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(15);
  
  }else
  cout<<setw(11);
  break;
  case 4:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(19);
  
  }else
  cout<<setw(14);
  break;
  case 5:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(22);
  
  }else
  cout<<setw(17);
  break;
  case 6:
  if(year < 1752 || (year == 1752 && month < 9)){
    cout << setw(27);
  
  }else
  cout<<setw(20);
  break;
}

for(int p = 1; p <= NumberOfDaysInMonth; p++){
  
  if(year < 1752 || (year == 1752 && month < 9)){
  
    cout << count << setw(4);
    count ++;
  
  }else{
  
    cout << p << setw(3);
  
  }
  ++DayOfWeekCounter;
  if(DayOfWeekCounter + firstday > 6){
    cout << "\n" << setw(2);
    DayOfWeekCounter = 0;
    firstday = 0;  
  }
  if(DayOfWeekCounter > 6){
  
    cout << "\n" << setw(2);
    DayOfWeekCounter = 0;
  
  }
  


}

}

int main(const int argc, const char *argv[]){

std::cout.setf(std::ios::unitbuf);

if(argc <= 1){
    month = 11;
    year = 2016;
    firstDay();
    print();
    cout << "\n";
  }
  else if(argc == 2){
    year = atoi(argv[1]);
    cout<<setw(14)<< year << "\n\n";
    for(int c = 1; c <=12; c++){
      
      month = c;
      firstDay();
      print();
      cout << "\n\n";
    
    }
  }
  else if(argc == 3){
  
    month = atoi(argv[1]);
    year = atoi(argv[2]);
    firstDay();
    print();
    cout << "\n";
  
  }
  
  
return 0;

}
