#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftIntake = motor(PORT3, ratio36_1, false);
motor RightIntake = motor(PORT8, ratio36_1, true);
motor Tray = motor(PORT6, ratio18_1, false);
motor RightDrive = motor(PORT2, ratio18_1, true);
motor LeftDrive = motor(PORT1, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}