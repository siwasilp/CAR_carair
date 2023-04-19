#include "para.h"
void setup() {
  setup_x();
  //----------- job_0/5 : Begin ------------------
  disp_0();
}
void loop()
{
  
  //----------- job_x : TEST_HW ----------------
  loadcell();
  //rfid();
  //rcl();
  key_x();
  
  //----------- job_1/5 : check_now ------------
  rfid_x();
  disp_now();
  
  //----------- job_2/5 : with_key  ------------


  //----------- job_3/5 : Move_XXX  ------------

  
  //----------- job_4/5 : Disp_ST   ------------


  //----------- job_5/5 : Clear_ST  ------------
}
