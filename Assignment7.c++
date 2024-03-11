/*In the given code we got output as dummydummy. In that code user2 got the same memory location 
as user1. Therfore,when the user2 is changed, it affects the user1as well due to the shared memory.To resolve this
problem, we have to allocate new memory block for the name of the user2 and copy the content of user1's name into it
Hence, in the below code the output will show that changing the name of user2 does not effect user1,as each object
has its own dynamically allocated memory for name.*/
#include<iostream>
#include<cstring>
using namespace std;
class sample{
    public:
    char *name;
    sample(){}
    sample(char *str, int length){
        name=new char[length+1];
        strcpy(name,str);
    }
    sample(const sample &other){
        int length=strlen(other.name);
        name=new char[length+1];
        strcpy(name,other.name);
    }
    ~sample(){
        delete[] name;
    }
};
int main(int argc, char *argv[]){
    sample user1((char*)"chitkara",8);
    sample user2=user1;
    strcpy(user2.name,"dummy");
    cout<<user2.name<<" "<<user1.name<<endl;
    return 0;
}