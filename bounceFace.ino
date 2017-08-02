int blue4 = 9;
int blue1 = 5;
int blue2= 6;
int blue3 = 3;
int blue6 = 10;
int blue5 = 11;
int brightlvl[] = {0, 20, 160, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int transition[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
int LED_COUNT = 32;
;
int dir = 2;
#include <Tlc5940.h>
#define NUM_TLCS 2

void setup()
{
 Tlc.init(0);

}

void loop(){
 for(int i = 0; i < LED_COUNT; i++){
   fading(i);
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
}


void fading(int index){
 switch(transition[index]){
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
 }
}

void off(int index){
 brightlvl[index] = 0;
}




void offtodim(int index){                          // called when transition == 1
 if (brightlvl[index] <= 199){                   // brightlvl starts at 0 at the beginning of this function
   brightlvl[index] += 10;
 }
 else {
   brightlvl[index] = 200;
   transition[index] = 2;
   if (index == 0){
     dir = 2;
   }
   else if (index == 31){               // what place in the line of leds to bounce back at
     dir = 1;
   }
   if (dir == 2){
     transition[index+1] = 1;
   }
   else if (dir == 1){
     transition[index-1] = 1;
   }
 }
}

void dimtoon(int index){                          // called when transition == 2
 if (brightlvl[index] <= 1590){                  // brightlvl starts at 20 at the beginning of this function
   brightlvl[index] += 80;
 }
 else {
   brightlvl[index] = 1600;
   transition[index] = 3;
 }
}

void ontodim(int index){                          // called when transition == 3
 if (brightlvl[index] >= 210){                  // brightlvl starts at 160 at the begining of this function
   brightlvl[index] -= 80;
 }
 else {
   brightlvl[index] = 200;
   transition[index] = 4;
 }
}


void dimtooff(int index){                          // called when transition == 4
 if (brightlvl[index] >=1){                     //brightlvl starts at 20 at the begining of this function
   brightlvl[index] -= 10;
 }
 else {
   brightlvl[index] = 0;
   transition[index] = 5;
 }
}
