#include <iostream>
#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(float _kp,float _kd,float _ki);
        
        void loop();                //Main loop function        
        void system_start();       //start the system
        void set_xdes(double x);   //member to set the desired value

    private:
        double _xdes; 
        double _x; 

        float _s; 
        
        float _kp; // Proportional gain
        float _kd; // Derivative gain
        float _ki; // Integral gain

        bool _initvalue;
};
