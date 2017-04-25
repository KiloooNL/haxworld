#include <iomanip>
#include <iostream>
#include <fstream>
#include "define.h"
using namespace std;

static void config() {
    int sum = 0;
    int res_width = SCREEN_WIDTH;
    int res_height = SCREEN_HEIGHT;
    bool blood = true;
    int volume = 100;
    int x;
    ifstream config;

    config.open("config.cfg");
    if (!config) { // if config can't be found, create a new one
        cout << "Unable to open \"config.cfg\" - creating a new configuration.\n";
          ofstream myfile;
          myfile.open ("config.cfg");
          myfile << "[HaxWorld auto generated config]\nres_width = 640\nres_height = 480\nblood = true\nvolume = 100\n";
          myfile.close();
    } 
    config >> res_width >> res_height >> volume >> blood;

    while (config >> x) {
        sum = sum + x;
    }
    
    config.close();
    cout << "Resolution = " << res_width << "x" << res_height << endl; 
}