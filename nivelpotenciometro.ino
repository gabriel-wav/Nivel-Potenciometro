int pot =  34;
int letpot = 0;

int LEDs[ ] = {12, 13, 14, 15, 5, 18, 19};
bool segmentos1[6] [8]  = { {0,0,1,1,1,1,1}, // B
                           {1,1,1,0,1,1,1}, // A
                           {1,0,0,1,1,0,0}, // I
                           {0,0,0,0,1,1,1}, // X
                           {1,1,1,1,1,1,0}, }; // O

bool segmentos2[6] [8]  = {                           
                          
                            {1,1,1,0,1,1,0}, // M
                            {1,0,0,1,1,1,1}, // E
                            {0,1,1,1,1,0,1}, // D
                            {1,0,0,1,1,0,0}, // I
                            {1,1,1,1,1,1,0}, }; // O

bool segmentos3[5] [8]  = {                                            
                            {1,1,1,0,1,1,1}, // A 
                            {0,0,0,1,1,1,0}, // L
                            {0,0,0,1,1,1,1}, // T
                            {1,1,1,1,1,1,0}, }; // O



void setup(){
Serial.begin(115200);
for (int i = 0; i<8; i++) {
pinMode(LEDs[i],OUTPUT);
        }
pinMode(pot, INPUT);
}

void loop() {
letpot = analogRead(pot);
Serial.println(letpot);
for(int j=0; j<6;j++){
 for(int i=0; i<8; i++){
if (letpot <=2000){
digitalWrite(LEDs[i], segmentos1[j][i]);
}
  }
delay(500);
 }
 for(int j=0; j<6;j++){
 for(int i=0; i<8; i++){
if (letpot >=2001 && letpot <= 3000){
digitalWrite(LEDs[i], segmentos2[j][i]);
}
 }
delay(500);
 }
for(int j=0; j<5;j++){
 for(int i=0; i<8; i++){
if (letpot >=3001 && letpot <= 4095){
digitalWrite(LEDs[i], segmentos3[j][i]);
}
  }
delay(500);
 }
}
