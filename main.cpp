#include "control_loop.h"

using namespace std;int main(int argc, char** argv) {
    
 CONTROLLER c(0.1,0.03,0.02);

    double y;
    while( true ) {
        cout << "Insert value = ";
        cin >> y;
        c.set_xdes(y);
    }

    return 0;}