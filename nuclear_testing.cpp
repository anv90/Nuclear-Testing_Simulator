#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

//global variables for thresholds
float temperature_critical_low = 300;
float temperature_critical_high = 345; 
float temperature_warning_low = 315;
float temperature_warning_high = 33;
float pressure_critical_low = 7;
float pressure_critical_high = 15; 
float pressure_warning_low = 8;
float pressure_warning_high = 14;

string temp_monitor(float temperature) {
    if (temperature <= temperature_critical_low || temperature >= temperature_critical_high) {
        return "CRITICAL ALERT: Temperature is outside of safe range!";
    } else if (temperature <= temperature_warning_low) {
        return "WARNING: Temperature approaching critical low!";
    } else if (temperature >= temperature_warning_high) {
        return "WARNING: Temperature approaching critical high!";
    } else {
        return "Temperature is within safe range";
    }       
}

string pressure_monitor(float pressure) {
    if (pressure <= pressure_critical_low || pressure >= pressure_critical_high) {
        return "CRITICAL ALERT: Pressure is outside of safe range!";
    } else if (pressure <= pressure_warning_low) {
        return "WARNING: Pressure approaching critical low!";
    } else if (pressure >= pressure_warning_high) {
        return "WARNING: Pressure approaching critical high!";
    } else {
        return "Pressure is within safe range";
    }       
}

bool is_float(string str) {
    int count = 0;
    for (int j = 0; j < str.length(); j++) {
        //cout << "checkpt"; the couts were used for testing the function to make sure the logic was right
        if (isdigit(str[j])) {
            //cout << str[j] << endl;
            continue;
            } 
        else if (str[j] == '.') {
            count ++;
            //cout << "." << endl;
            if (count > 1) {
                //cout << "false" << endl;
                return false;
            }
            continue;
        } else {
            return false;
        }
        
    }
    return true;
    }
    
int main() {
    //initializing inputs as strings for error checking
    string str_user_temp;
    string str_user_pressure;
    
    //error checking of input; the while loop will keep reprompting the user for correct input
    while (true) {
        cout << "temperature: ";
        getline(cin, str_user_temp); //reads all the input the user gives and doesn't stop at a space
    if (is_float(str_user_temp) == false) { //calling a function to test if the value is a valid float
        cout << "Invalid input: Please input a number" << endl;
    } else {
        break;
    }
    }
     //error checking of input; the while loop will keep reprompting the user for correct input
    while (true) {
        cout << "pressure: ";
        getline(cin, str_user_pressure); //reads all the input the user gives and doesn't stop at a space
    if (is_float(str_user_pressure) == false) { //calling a function to test if the value is a valid float
        cout << "Invalid input: Please input a number" << endl;
    } else {
        break;
    }
    }

    //converting the string values to floats
    float user_temp = stof(str_user_temp);
    float user_pressure = stof(str_user_pressure);
    
    cout << temp_monitor(user_temp) << endl << pressure_monitor(user_pressure) << endl; //calling the comparison functions
    
    return 0;
}


//    