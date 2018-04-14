#include <iostream>
#include "oldstring.cpp"
#include <string>
using namespace std;

int main(void){

    string s1;

    cout << "Enter a string" << endl;
    getline(cin, s1);
	
    cout << s1 << endl;

    const char *cstr = s1.c_str();

    const char **ptr = &cstr;
    
    while(*(*ptr) != '\0'){
    
    	double x = mean(cstr);
    	double y = stdDev(cstr, x);
    	string word = getWord(ptr);
    
    	cout << "Mean of " << word << " : " << x << endl;
    	cout << "Standard deviation of " << word << " : " << y << endl;
    }
    
    return 0;
}
