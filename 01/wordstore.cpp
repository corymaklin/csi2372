#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main(){

	string word;
	vector<string> text;	
	while(cin >> word){
		if(word == "stop"){
			break;
		}
		text.push_back(word);
	}
	
	for(int i=0; i<text.size(); i++){
		cout << text[i] << " ";
	}
	
	cout << "\n";
	
	for(int j=0; j<text.size(); j++){
	
		double sum = 0;
		string temp = text[j];
		
		for(int k=0; k<temp.size(); k++){
			sum += static_cast<int>(temp[k]);
		}
		double mean = sum / temp.size();
		
		double standardDeviation = 0;
		
		for(int n=0; n<temp.size(); n++){
			standardDeviation += pow(static_cast<int>(temp[n]) - mean, 2);
		}
		
		standardDeviation = sqrt(standardDeviation / (temp.size()-1));
		
		cout << "Mean of "+temp+" : " << mean << "\n";
		cout << "Standard deviation : " << standardDeviation <<"\n";
	}
	return 0;
}