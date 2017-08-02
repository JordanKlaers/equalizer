int blue4 = 9;
int blue1 = 5;
int blue2= 6;
int blue3 = 3;
int blue6 = 10;
int blue5 = 11;
int brightlvl[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int transition[] = {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
int LED_COUNT = 32;
;
int dir = 2;
#include <Tlc5940.h>
#define NUM_TLCS 2

void setup()
{
 Tlc.init(0);
 Serial.begin(9600);
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
Tlc.set(8, (brightlvl[8]*2));
Tlc.set(9, (brightlvl[9]*2));
Tlc.set(10, (brightlvl[10]*2));
Tlc.set(11, (brightlvl[11]*2));
Tlc.set(12, (brightlvl[12]*2));
Tlc.set(13, (brightlvl[13]*2));
Tlc.set(14, (brightlvl[14]*2));
Tlc.set(15, (brightlvl[15]*2));
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
     break;
   case 6:                           //_*_*_*_*_*_*_*_*_* this case doesnt need to exist in the original pattern
     on(index);
     break;
 }
}

void off(int index){
 brightlvl[index] = 0;
}

void on(int index){
 brightlvl[index] = 1600;
 if (index == 3 || index == 7 || index == 11 || index == 15 || index == 19 || index == 23 || index == 27 || index == 31){
   transition[index] = 3;
 }
}


void offtodim(int index){                          // called when transition == 1
 if (brightlvl[index] <= 180){                   // brightlvl starts at 0 at the beginning of this function
   brightlvl[index] += 10;
   Serial.println(brightlvl[4]);
 }
 else  {
   brightlvl[index] = 200;
   transition[index] = 2;
   if (index != 3 && index != 7 && index != 11 && index != 15 && index != 19 && index != 23 && index !=27 && index != 31){
     transition[index+1] = 1;                    // ____*****______ this part makes the next LED go up in brightness (unless its the top led)
   }
 }
}


void dimtoon(int index){                          // called when transition == 2
 if (brightlvl[index] <= 1590){                  // brightlvl starts at 20 at the beginning of this function
   brightlvl[index] += 80;
 }
 else {
   brightlvl[index] = 1600;
   transition[index] = 6;                     //_*_*_*_*_*_*_*_*_*_*_*_change this back to 3 for original pattern
   if (index == 4){
   }
 }
}

void ontodim(int index){                          // called when transition == 3
 if (brightlvl[index] >= 210){                  // brightlvl starts at 160 at the begining of this function
   brightlvl[index] -= 80;
 }
 else {
   brightlvl[index] = 200;
   transition[index] = 4;
   if (index != 0 && index != 4 && index != 8 && index != 12 && index != 16 && index != 20 && index != 24 && index != 28){
     transition[index-1] = 3;            //____********________ this one will make the led below begin going down (unless its the bottom led, it wont)
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
   if (index == 0 || index == 4 || index == 8 || index == 12 || index == 16 || index == 20 || index == 24 ){
     transition[index+4] = 1;
   }
   else if (index == 28){
     transition[0] = 1;
   }
 }
}
