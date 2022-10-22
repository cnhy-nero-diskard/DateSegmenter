#include <string>
#include <ctype.h>
using namespace std;

class convert{
    private:
        string inputs[2]; //takes in ex: [24.3453434] [months]
        string rank;
        string hier[7] = {"year", "months", "weeks", "days", "hours", "minutes", "seconds"};
        string output;
        char sample;
        int into; //this is inputs[0] converted into an float
        int retIndex();

        int quo;    //will be set to quo=value once assigned
        float rem;
        float multiplicand;
        const float equ[7] = {1,12,4.3482,7,24,60,60};
        int convertInt(string); 



    public:
        string * param_setter(){
            return inputs;}


        string output_g(){
            return output;
        }
        void converter();
        bool typecast();
            

};
int convert::convertInt(string sample){
    return stoi(sample);
}
bool convert::typecast(){ //will throw an exception if the numeric input !isdigit()
    //otherwise 
    try{
        for (auto &&i: inputs[0]){
            sample = (char) i;
            if (!isdigit(sample)){
                throw (sample);
            }
        }
    }catch(...){
        return false; //the conversion will not take place
    }
    into = convertInt(inputs[0]);
    return true;
} 
int convert::retIndex(){
    rank = inputs[1];
    for (int x = 0; x < 7; x++){
        if (hier[x] == rank){
            return x;
        }
    }
    return 10000; //if the input does not belong in the array
}
    
void convert::converter(){
    //important class variables here: into, inputs[1], and
}