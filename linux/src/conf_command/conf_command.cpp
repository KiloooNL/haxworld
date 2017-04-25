#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char* args[]) {
	printf("\nHaxWorld Configuration (Terminal/Command Prompt Version)\n");
        // characters name
        char name[80];
        cout << "Enter characters name: ";
        cin >> name;
    
        // default resolution, 800x600
        int x = 800;
        int y = 600;
        cout << "\nEnter resolution width: ";
        cin >> x;
        cout << "Enter resolution height: ";
        cin >> y;

	if(x, y == 800, 600) {
        	cout << "\n(RESOLUTION CHOSEN: 800x600 - Default)\n";
	}
	else {
        	cout << "\n(RESOLUTION CHOSEN: " << x << "x" << y << ")\n";
	}
    
        // blood enabled?
        int blood_enabled = 0;
        cout << "\nBlood enabled?\n0 = yes\n1 = no\n";
        cin >> blood_enabled;
    
        // volume
        int volume = 100;
        cout << "\nSound & Music volume (Anywhere between 0-100): ";
        cin >> volume;
    
        //system("CLS");
    
        // show settings
        cout << "Settings:";
        cout << "\nCharacter name: " << name;
        cout << "\nResolution: " << x << "x" << y;
    
        if(blood_enabled == 0) {
                cout << "\nBlood: yes";
        } else {
                cout << "\nBlood: no";
        }
    
        cout << "\nVolume: " << volume << "\n";
    
        int correct = 0;
        cout << "\n\nAre these settings correct?\n0 = yes\n1 = no\n";
        cin >> correct;
        
	if(correct == 0) {
                cout << "\nSettings have been saved to \"conf.cfg\"\n";
        } else {
                cout << "\nSettings have not been saved.\n";
        }

	return 0;
}
