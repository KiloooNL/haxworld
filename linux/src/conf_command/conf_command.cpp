#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

char name[80];
int res_width = SCREEN_WIDTH;
int res_height = SCREEN_HEIGHT;
bool blood = true;
int volume = 100;
ifstream config;

int main() {
	printf("\nHaxWorld Configuration (Terminal/Command Prompt Version)\n");
    	config.open("config.cfg");
    	if (!config) { // if config can't be found, create a new one
        	cout << "Unable to open \"config.cfg\" - creating a new configuration.\n";
          	ofstream myfile;
          	myfile.open ("config.cfg");
          	myfile << "[HaxWorld auto generated config]\nname = haxworld\nres_width = 800\nres_height = 600\nblood = true\nvolume = 100\n";
          	myfile.close();
    	}	 
        // characters name
        cout << "Enter characters name: ";
        cin >> name;

        // default resolution, 800x600
        cout << "\nEnter resolution width: ";
        cin >> res_width;
        cout << "Enter resolution height: ";
        cin >> res_height;

	if(res_width, res_height == 800, 600) {
        	cout << "\n(RESOLUTION CHOSEN: 800x600 - Default)\n";
	}
	else {
        	cout << "\n(RESOLUTION CHOSEN: " << res_width << "x" << res_height << ")\n";
	}
    
        // blood enabled?
        cout << "\nBlood enabled?\n0 = yes\n1 = no\n";
        cin >> blood;
    
        // volume
        cout << "\nSound & Music volume (Anywhere between 0-100): ";
        cin >> volume;
    
        //system("clear");
    
        // show settings
        cout << "Settings:";
        cout << "\nCharacter name: " << name;
        cout << "\nResolution: " << res_width << "x" << res_height;
    
        if(blood == 0) {
                cout << "\nBlood: yes";
        } else {
                cout << "\nBlood: no";
        }
    
        cout << "\nVolume: " << volume << "\n";
    
        int correct = 0;
        cout << "\n\nAre these settings correct?\n0 = yes\n1 = no\n";
        cin >> correct;
        
	if(correct == 0) {
		ofstream myfile;
        	myfile.open ("config.cfg");
        	myfile << "name = " << name << "\n" << "resolution = " << res_width << "x" << res_height << "\nblood = " << blood << "\nvolume = " << volume << "\n";
        	myfile.close(); 
                cout << "\nSettings have been saved to \"config.cfg\"\n";
        } else {
                cout << "\nSettings have not been saved.\n";
        }   

    	config.close();
    	cout << "Resolution = " << res_width << "x" << res_height << endl; 
	return 0;
}
