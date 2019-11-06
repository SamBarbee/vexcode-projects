#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftIntake           motor         3               
// RightIntake          motor         8               
// Tray                 motor         6               
// RightDrive           motor         2               
// LeftDrive            motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

void setDrive(int l,int r);
void setIntake(int p);

void pre_auton(void) {
  vexcodeInit();

}

void autonomous(void) {
  
}

void usercontrol(void) {

  while (1) {

    setDrive(Controller1.Axis2.value()+Controller1.Axis1.value(),Controller1.Axis2.value()-Controller1.Axis1.value());

    

    if(Controller1.ButtonR1.pressing()) {
      setIntake(100);
    }
    else if(Controller1.ButtonR2.pressing()) {
      setIntake(-100);
    }
    else {
      setIntake(0);
    }

    if(Controller1.ButtonUp.pressing()) {
      Tray.spin(fwd,100,pct);
    }
    else if(Controller1.ButtonDown.pressing()) {
      Tray.spin(fwd,-100,pct);
    }
    else {
      Tray.spin(fwd,0,pct);
    }

    

    wait(20, msec);
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}

void setDrive(int l,int r) {
  LeftDrive.spin(fwd,l,pct);
  RightDrive.spin(fwd,r,pct);
}

void setIntake(int p) {
  LeftIntake.spin(fwd,p,pct);
  RightIntake.spin(fwd,p,pct);
}