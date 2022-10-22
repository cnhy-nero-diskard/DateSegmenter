#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;


int main(){

    string pi = "3.14159";
    float conv = stof(pi);
    cout << "Converted: " << conv <<endl;
    
    return 0;
}

void sample(){
      try {
    int age = 15;
    if (age >= 18) {
      cout << "Access granted - you are old enough.";
    } else {
      throw (age);
    }
  }
  catch (int myNum) {
    cout << "Access denied - You must be at least 18 years old.\n";
    cout << "Age is: " << myNum;  
  }
  
}


void exc(){
    string foo = "baby01";

   
    try{
    for (auto &&i : foo)
    {   
        char g = (char)i;
        cout << g << " is a digit --- "<<isdigit(g)<<endl;
        if (!isdigit(g)){
            throw(g);
        }
    }}
    catch(...){
        cout << "boang man ka" << endl;
    }
}