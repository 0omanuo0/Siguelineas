int vMin =0, vMax =200;
int mot1, mot2;
int irT, MIzq, MDer;
void setup() {
  Serial.begin(9600);
  //calibracion
  for (int i=4; i <= 12; i++){
      pinMode(i, OUTPUT);
   }

}

void loop() {
  irAngulo(analogRead(A1),analogRead(A2));
  delay(10);
}

int irAngulo(int ir1, int ir2){
  irT = ir1-ir2;
  Serial.print(irT);
    Serial.print(",");
  irT = map(irT,-250, 500, 0, 1000);
  
  if(irT < 500){
    mot1 = map(irT,0, 500, vMin, vMax);
    mot2 = 255 - mot1;
  }
  else{
    mot2 = map(irT, 500, 1000, vMax, vMin);
    mot1 = 255 - mot2;
  }
  
  analogWrite(11, mot1);
  analogWrite(10, mot2);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  Serial.print(mot2);
  Serial.print(",");
  Serial.println(mot1);
  
}

