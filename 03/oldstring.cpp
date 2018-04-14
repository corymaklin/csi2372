#include <iostream>
#include "oldstring.h"
#include <string>
#include <math.h>

double mean(const char *ptr){

    double sum = 0;
    int count = 0;
    while(!((*ptr == '\0') || (*ptr ==' '))){
        sum += static_cast<int>(*ptr);
        count++;
        ptr++;
    }

    double mean = sum / count;

    return mean;
}

double stdDev(const char *ptr, double mean){
	
	double standardDeviation = 0;
	int count = 0;
	
	while(!((*ptr == '\0') || (*ptr ==' '))){
		standardDeviation += pow(static_cast<int>(*ptr) - mean, 2);
		ptr++;
		count++;
	}
	
	standardDeviation = sqrt(standardDeviation / (count-1));
	
    return standardDeviation;
}

std::string getWord(const char **ptr){

    std::string s;

    while(!((*(*ptr) == '\0') || (*(*ptr) ==' '))){
        s+=*(*ptr);
        (*ptr)++;
    }
    if(*(*ptr) == ' '){
        (*ptr)++;
    }
    return s;
}

oldstring::oldstring()
{

}
