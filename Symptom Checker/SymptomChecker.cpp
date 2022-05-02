/* Will Richards
   4/24/2021
   A symptom checker that displays illnesses for randomly generated patients.
*/
#include <iostream>
#include <string>
#include <random>

using namespace std;


//define class
class Patient {
   
    public:
    int num;
   
   //function that displays the table
    void table(){
       
    cout << "Symptoms Checker" << endl;
    cout << "Guide:    * Common      + Sometimes/Rarely     - NO" << endl;
    cout << "===================================================" << endl;
    cout << "Symptoms " << "\t|\tCOVID-19 " << "\t|\tCold " << "\t|\tFlu   |" << endl;
    cout << "===================================================" << endl;
    cout << "Fever    " << "\t|\t\t* " << "\t\t|\t  + " << "\t|\t*     |" << endl;
    cout << "Cough    " << "\t|\t\t* " << "\t\t|\t  + " << "\t|\t*     |" << endl;
    cout << "Shortness" << "\t|\t\t* " << "\t\t|\t  - " << "\t|\t-     |" << endl;
    cout << "-of Breath" << endl;
    cout << "Runny Nose " << "\t|\t\t+ " << "\t\t|\t  * " << "\t|\t+     |" << endl;
    cout << "Headaches " << "\t|\t\t+ " << "\t\t|\t  + " << "\t|\t*     |" << endl;
    cout << "Sneezing " << "\t|\t\t- " << "\t\t|\t  * " << "\t|\t-     |" << endl;
    cout << "Fatigue " << "\t|\t\t+ " << "\t\t|\t  + " << "\t|\t*     |" << endl;
    cout << "===================================================" << endl;
   
    }
   
   //function that generates symptoms for each patient
    void generateSymptoms(){
       
        int i;
        int cough, fever, runnyNose, breath, headache, sneezing, fatigue;
        int covid = 0, cold = 0, flu = 0, other = 0;
       
        for(i = 0; i < num; i++){
           
           //generate random number (0 or 1, representing 'absent' or 'present' respectively)
            cough = rand()%2;
            fever = rand()%2;
            runnyNose = rand()%2;
            breath = rand()%2;
            headache = rand()%2;
            sneezing = rand()%2;
            fatigue = rand()%2;
           
           //statement to check if a patient has covid
            if(cough == 1 && fever == 1 && runnyNose == 1 && breath == 1 && headache == 0 && sneezing == 0 && fatigue == 0)
            covid++;
           //statement to check if a patient has a cold
            else if(cough == 1 && fever == 1 && runnyNose == 0 && breath == 0 && headache == 1 && sneezing == 1 && fatigue == 1)
            cold++;
           //statement to check if a patient has a flu
            else if(cough == 1 && fever == 1 && runnyNose == 1 && breath == 0 && headache == 1 && sneezing == 0 && fatigue == 1)
            flu++;
           //statement to check if a patient has another illness
            else
            other++;
           
        }
       
       //display results
        cout << "===================================================" << endl;
        cout << covid << " patients have symptoms of COVID-19" << endl;
        cout << cold << " patients have symptoms of a cold" << endl;
        cout << flu << " patients have symptoms of a flu" << endl;
        cout << other << " patients have some other illness" << endl;
        cout << "===================================================" << endl;
        cout << "COVID-19: " << (float)covid * 100 / num << "% " << string((covid * 100 / num), 'x') << endl;
        cout << "Cold: " << (float)cold * 100 / num << "% " << string((cold * 100 / num), 'x') << endl;
        cout << "Flu: " << (float)flu * 100 / num << "% " << string((flu * 100 / num), 'x') << endl;
        cout << "Other illnesses: " << (float)other * 100 / num << "% " << string((other * 100 / num), 'x') << endl;
        cout << "===================================================" << endl;
       
    }
   
};


//main program
int main(){
	//creating an object of the patient class
    Patient myObj;
   //assign number of patients to num
    myObj.num = 0;
    myObj.table();
    cout << "How many patients would you like to check? " << endl;
    cin >> myObj.num;
   //run generating symptoms function
    myObj.generateSymptoms();
   
    return 0;

}
