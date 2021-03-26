/*
 * this file uses pitches.h which has constants for all notes
 */
#include "pitches.h";
void playGood(){
      tone( passiveBuzzerPin, NOTE_G5, 200);
      delay(200);
}
void playWrong() {
      tone( passiveBuzzerPin, NOTE_D5, 200);
      delay(200);
}
int wrong_tone[]={NOTE_D5,NOTE_E5,NOTE_CS5};
int wrong_times[]={400,200,250};
void playFail() {
  for (int k=0;k<3;k++){
      tone( passiveBuzzerPin, wrong_tone[k], wrong_times[k]);
      delay(wrong_times[k]);
  }
}


int good_tone[]={NOTE_G5,NOTE_B5};
int good_times[]={200,400};
void playWin(){
  for (int k=0;k<2;k++){
      tone( passiveBuzzerPin, good_tone[k], good_times[k]);
      delay(good_times[k]);
  }
}

