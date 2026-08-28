//Grupo 8
//Piccicacco Feierman Diaz

void setup() {
  pinMode(32, INPUT);
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(32);                       // Lee de 0 a 1023
  int Porcentaje = map(lectura, 0, 4095, 0, 100);  // Convierte a 0 a 100

  Serial.print("Luz ");
  Serial.print(Porcentaje);
  Serial.println("%");

  delay(500);
}