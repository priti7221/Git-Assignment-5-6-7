#include<iostream>
using namespace std;


class User {
private:
string name;
int birth_year;
int birth_day;
int birth_month;
double salary;

public:

User(string name, int year, int day, int month, double salary){
      this -> name = name;
      birth_year = year;
      birth_day = day;
      birth_month = month;
      this -> salary = salary;
}

int operator==(const User& object){
    if(birth_year < object.birth_year){
        return 1;
    } else if(birth_year > object.birth_year){
        return -1;
    }
     
       if(birth_day < object.birth_day){
     return 1;
       } else if(birth_day > object.birth_day){
      return -1;
       }

       
  if(birth_month < object.birth_month){
     return 1;
      } else if(birth_month > object.birth_month){
       return -1;
     } else{
        return 0;
     }

}

  double operator+(const User& object){
    return (salary + object.salary) / 2.0;
  }

  double operator+(int num){
      salary = salary *(num / 100.0);// add percentage increment in user existing salary
      return salary;

  }

  void display(){
        cout << "Name of the user: " << name << endl;
        cout << "Birth Year of the user: " << birth_year << endl;
        cout << "Birth Day of the user: " << birth_day << endl;
        cout << "Birth Month of the user: " << birth_month << endl;
        cout << "Salary of the user: " << salary << endl;
  }

};

int main(){
    User user1 ("Pratibha",2006,28,3,40000);
    User user2("Prince",2009,21,1,50000);

    // comparing ages of uers
    int result = user1 == user2;
      if(result == 1){
        cout<<"user1 is elder"<<endl<<endl;
      } else if(result == -1){
        cout<<"user2 is elder"<<endl<<endl;
      } else{
        cout<<" both are equal"<<endl<<endl;
      }

    double avg_sal = user1 + user2;
    cout<<"Average salary:"<<avg_sal<<endl<<endl;

     cout<<"Before increment users details:"<<endl<<endl;
    user1.display();
    user2.display();

   user1 + 5; // add 5% increment in user1 existing salary
   user2 + 10; // add 10% increment in user2 existing salary

   cout<<"\nAfter increment users details :"<<endl<<endl;
   user1.display();
   user2.display();

   

} 