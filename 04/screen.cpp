#include "screen.h"
#include <iostream>
using namespace std;

void printScreen(char(&screen)[g_height][g_width]){

	char (*ptr)[g_width] = screen;
	
	for(int i=0; i<g_height; i++){
		for(int j=0; j<g_width; j++){
			cout << *(*(ptr+i)+j);
		}
		cout << endl;
	}
}

void clearScreen(char(&screen)[g_height][g_width]){
	
	char (*ptr)[g_width] = screen;
	
	for(int i=0; i<g_height; i++){
		for(int j=0; j<g_width; j++){
			*(*(ptr+i)+j) = ' ';
		}
		cout << endl;
	}
	
}

void gridScreen(char(&screen)[g_height][g_width], int hline, int vline=(-1)){

	char (*ptr)[g_width] = screen;
	
	if(hline > g_width || vline > g_height){
		cout << "Error" << endl;
		return;
	} 
    if(vline==-1){
        vline = hline;
	}
    if(hline < 0){
    	hline = 0;
    }    
    if(vline < 0){
    	vline = 0;
    }
    
    int indexh = (g_height-hline) / (hline+1);
    int indexv = (g_width-vline) / (vline+1);
    
    for(int j=0; j<vline; j++){
    	for(int i=0; i<g_height; i++){
    		ptr[i][indexv] = '*';
   	 	}
    	indexv = indexv + indexv+1;
    }
    
    for(int n=0; n<hline; n++){
    	for(int m=0; m<g_width; m++){
    		ptr[indexh][m] = '*';
   	 	}
    	indexh = indexh + indexh+1;
    }
}

screen::screen()
{
    
}
