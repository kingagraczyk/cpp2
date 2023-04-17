#include "control_loop.h"
#include <iostream>
#include <fstream> 

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(float kp_, float kd_, float ki_) {

    _kp = kp_;
    _ki = ki_;
    _kd = kd_;

    _s = 0.001;
    
    _initvalue = false;

    CONTROLLER::system_start();
 
    boost::thread loop_t( &CONTROLLER::loop, this );                //Main control loop

}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {

    _xdes = x;

    _initvalue = true;

}
void CONTROLLER::system_start() {
    
    //Generate a random initial value
    srand((unsigned int)time(NULL));
    float random = ((float) rand()) / (float) RAND_MAX;
    _x = random;
    }

void CONTROLLER::loop() {

    ofstream myfile("Results.txt");

    do{
       usleep(0.1*1e6);  
    }
    while( !_initvalue );

  
    myfile.open ("Results.txt");
    myfile << "Reference =  " << _xdes << "\n";
    myfile.close();
    
    _xdes == _x; 

    double e = 0.0;
    double ep = 0.0;
    double de = 0.0;
    double ie = 0.0;

    double pid = 0.0;
    double output = 0.0;
    double dt = 1.0/100.0;

    do{
 //errors
        e = _xdes - _x;
        de = (e - ep) / dt;
        ie += e*dt;

        //action
        pid = _kp*e+ _kd*de + _ki*ie;

        //output
        output = pid;

        cout << "Error =  " << e << " \nOutput =  " << output << endl;
        myfile.open ("Results.txt", ios::app);
        myfile << "Error =  " << e << "Output =  " << output << "\n";
        myfile.close();

        if(abs(e)<_s) break;
        usleep(10000); 

        _x = output; 
    

    }
    
    while( true ); 
    }
