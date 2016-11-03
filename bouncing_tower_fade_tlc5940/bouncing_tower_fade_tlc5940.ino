
 int brightlvl[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int transition[] = {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
 int LED_COUNT = 32;
 int tower = 1;                     // the int defines which tower should be changing
 int updown = 2;                    // 1 is down, 2 is up
#include <Tlc5940.h>
#define NUM_TLCS 2

void setup()
{
  Tlc.init(0);
  
}

void loop(){
  //for(int i = 0; i < LED_COUNT; i++){
  //  towerfade(i);
 // if (tower == 1){
 //   for(int i = 0; i < 4; i++){
 //     towerfade(i);
 //   }
 // }
 // else if (tower == 2){
 //   for(int j = 4; j < 8; j++){
 //     towerfade(j);  
 //   }
 // }
 // else if (tower == 3){
 //   for(int k = 8; k < 12; k++){
 //     towerfade(k);
 //   }
 // }
 // else if (tower == 4){
 //   for(int l = 8; l < 12; l++){
 //     towerfade(l);
 //   }
 // }
 // else if (tower == 5){
 //   for(int m =  8; m < 12; m++){
 //     towerfade(m);
 //   }
  //}
 // else if (tower == 6){
 //   for(int n = 8; n < 12; n++){
  //    towerfade(n);
  //  }
 // }
 // else if (tower == 7){
 //   for(int o = 8; o < 12; o++){
 //     towerfade(o);
 //   }
 // }
 // else if (tower == 8){
 //   for(int p = 8; p < 12; p++){
 //     towerfade(p);
 //   }
  //}
Tlc.set(0, brightlvl[0]);
Tlc.set(1, brightlvl[1]);
Tlc.set(2, brightlvl[2]);
Tlc.set(3, brightlvl[3]);
Tlc.set(4, brightlvl[4]);
Tlc.set(5, brightlvl[5]);
Tlc.set(6, brightlvl[6]);
Tlc.set(7, brightlvl[7]);
Tlc.set(8, (brightlvl[8]*3));
Tlc.set(9, (brightlvl[9]*3));
Tlc.set(10, (brightlvl[10]*3));
Tlc.set(11, (brightlvl[11]*3));
Tlc.set(12, (brightlvl[12]*3));
Tlc.set(13, (brightlvl[13]*3));
Tlc.set(14, (brightlvl[14]*3));
Tlc.set(15, (brightlvl[15]*3));
Tlc.set(16, brightlvl[16]);
Tlc.set(17, brightlvl[17]);
Tlc.set(18, brightlvl[18]);
Tlc.set(19, brightlvl[19]);
Tlc.set(20, brightlvl[20]);
Tlc.set(21, brightlvl[21]);
Tlc.set(22, brightlvl[22]);
Tlc.set(23, brightlvl[23]);
Tlc.set(24, brightlvl[24]);
Tlc.set(25, brightlvl[25]);
Tlc.set(26, brightlvl[26]);
Tlc.set(27, brightlvl[27]);
Tlc.set(28, brightlvl[28]);
Tlc.set(29, brightlvl[29]);
Tlc.set(30, brightlvl[30]);
Tlc.set(31, brightlvl[31]);
    Tlc.update();
    delay(0);
   
  }


void towerfade(int index){                         //tower1 controlls the first tower fade, for leds0 - 3
  switch(transition[index]){                      //transition refers to the led fading up/down/on/off
    case 1:
      offtodim(index);
      break;
    case 2:
      dimtoon(index);
      break;
    case 3:
      ontodim(index);
      break;
    case 4:
      dimtooff(index);
      break;
    case 5:
      off(index);
    case 6:
      on(index);
  }
}
  


  

void off(int index){
  brightlvl[index] = 0;
}

void on(int index){
  brightlvl[index] = 1600;
  if (index == 3 || index == 7 || index == 11 || index == 15 ||
      index == 19 || index == 23 || index == 27 || index ==31){
    transition[index] = 3;
  }
}




void offtodim(int index){                          // called when transition == 1
  if (brightlvl[index] <= 199){                   // brightlvl starts at 0 at the beginning of this function
    brightlvl[index] += 10;
    //Serial.println(brightlvl);
  }
  else {                                         //end of first incremental increase
    brightlvl[index] = 200;
    transition[index] = 2;                      // when on_off set to 2, the LED will increase from half way on to fully on
    if (index != 3 || index!= 7 || index != 11 || index != 15 ||
        index != 19 || index != 23 || index != 27 || index !=31){
      transition[index+1] = 1;                 // if updown == 2 (fade up) than make the next led begin fading up (((need to make a case for the top LED to change the direction to fade down))) as well as
    }                                           //this triggers the next led to also fade up, need to stop it at the last led
   
   // switch(index){                     // beggining led to bounce off
   //  dir = 2;
   // }
   // else if (index == 31){               // what place in the line of leds to bounce back at
   //   dir = 1;
   // }
   // if (dir == 2){
    //  transition[index+1] = 1;
   // }
   // else if (dir == 1){
   //   transition[index-1] = 1;
  }
}


void dimtoon(int index){                          // called when transition == 2
  if (brightlvl[index] <= 1590){                  // brightlvl starts at 20 at the beginning of this function
    brightlvl[index] += 80;
  }
  else {
    brightlvl[index] = 1600;
    transition[index] = 6;                       // made the top led transition set to go down, in the fully on function, instead of right here
   
  } 
}

void ontodim(int index){                          // called when transition == 3
  if (brightlvl[index] >= 210){                  // brightlvl starts at 160 at the begining of this function
    brightlvl[index] -= 80;
  }
  else {
    brightlvl[index] = 200;
    transition[index] = 4;
    if (index != 0 || index!= 4 || index != 8 || index != 12 ||
        index != 16 || index != 20 || index != 24 || index !=28){
      transition[index-1] = 3;                 
    } 
    
  }
}


void dimtooff(int index){                          // called when transition == 4
  if (brightlvl[index] >=1){                     //brightlvl starts at 20 at the begining of this function
    brightlvl[index] -= 10;
  }
  else {
    brightlvl[index] = 0;
    transition[index] = 5;              
    switch (index){                       // for leds 0, 4, 8, 12, 16, 20, 24, and 28, they will trigger the next tower to start
      case 0:                                    // needing to change both variables tower(which of the 8 towers is fading) and transition(getting the next towers led in the state to fade up)
        tower = 2;
        transition[index+4] = 1;
        break;
      case 4:                              //check with brian to see if, for example when index == 1,2,3 (the second third and 4th led of the first tower), there isnt a case to do anything, is that ok 
        tower = 3;
        transition[index+4] = 1;
        break;
      case 8:
        tower = 4;
        transition[index+4] = 1;
        break;
      case 12:
        tower = 5;
        transition[index+4] = 1;
        break;
      case 16:
        tower = 6;
        transition[index+4] = 1;
        break;
      case 20:
        tower = 7;
        transition[index+4] = 1;
      case 24:
        tower = 8;
        transition[index+4] = 1;
        break;
      case 28:
        tower = 1;
        transition[0] = 1;                  //when the last tower finishes fading off, the first led of the first tower is ready to fade up
    }
  }
}

