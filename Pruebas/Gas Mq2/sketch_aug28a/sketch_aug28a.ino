//Grupo 8 Piccicacco Diaz Feierman

const int pinMQ2 = 32;
const int umbralGas = 60;

// Variables para usar millis()
unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 1000;

void setup() {
  // Iniciar el monitor serial
  Serial.begin(9600);
  Serial.println("Sensor iniciado");
  Serial.println("Lectura del nivel de gas");
}

void loop() {
  unsigned long tiempoActual = millis();

  // Realizar una lectura cada 1 segundo
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    // Leer el sensor
    int valorSensor = analogRead(pinMQ2);

    int porcentaje = map(valorSensor, 0, 1027, 0, 100);

    // Limitar el porcentaje entre 0 y 100
    porcentaje = constrain(porcentaje, 0, 100);

    Serial.print("Nivel de gas/humo: ");
    Serial.print(porcentaje);
    Serial.println("%");

    // Comprobar el nivel
    if (porcentaje >= umbralGas) {
      Serial.println("ADVERTENCIA");
    } else {
      Serial.println("Normal");
    }
  }
}