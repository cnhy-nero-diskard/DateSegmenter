#include <string>
#include <ctype.h>
using namespace std;

class convert{
    private:
        string inputs[2]; //takes in ex: [24.3453434] [months]
        string rank;
        const string hier[7] = {"year", "months", "weeks", "days", "hours", "minutes", "seconds"}; //string of equ
        string output = "";
        char sample;
        float into; //this is inputs[0] converted into an float
        int retIndex();
        
        int i_start; //return value of retIndex()
        int iconv;  // set to := (int) date
        float frac; // set to := (float)date - iconv
        float prod; // set to := multiplier * date
        int wholes[7] = {0}; // wholes[i] = iconv -> max 7 

        const float equ[7] = {1,12,4.3482,7,24,60,60}; //standard equivalences of dates 
        float convertInt(string); 



    public:
        int * whole_getter(){
            return wholes;
        }
        string * param_setter(){
            return inputs;}


        string output_g(){
            for (int i = 0; i<7; i++){
                
                string o = to_string(wholes[i]);
                string s = string(o + " " + hier[i]+" ");
                output.append(s);
            }
            return output;
        }
        int converter();
        bool typecast();
            

};
float convert::convertInt(string sample){
    return stof(sample);
}
bool convert::typecast(){ //will throw an exception if the numeric input !isdigit()
    //otherwise 
    try{
        for (auto &&i: inputs[0]){
            sample = (char) i;
            if (!isdigit(sample) && !(sample == '.')){
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
    return 10000; //if the index is higher than hier[], then the loop will not execute in the first place
}
    
int convert::converter(){
    if (!typecast()){
        return 1;
    }
    i_start = retIndex();
    iconv = into;
    frac = into - (int) into;
    wholes[i_start] = iconv;
    //commands abovementioned will first add the input rank

    for (int i = i_start+1; i<7; i++){
        prod = equ[i] * frac;
        iconv = (int) prod;
        frac = prod - iconv;
        wholes[i] = iconv;
    }
}