//Lector de temperatura con LM35

float tempC;
float tempC1;
float tempC2;
float tempC3;
float tempC4;
float tempC5;
float tempC6;
float tempTotal;

int tempPin = 0; // Definimos la entrada en pin A0
void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    delay(3000);
}
void loop(){
    for(int ciclo=1;ciclo<=6;ciclo++){
      // Lee el valor desde el sensor
      tempC = analogRead(tempPin); 

      // Convierte el valor a temperatura
      tempC = (5.0 * tempC * 100.0)/1024.0; 

      // Envia el dato al puerto serial
      Serial.print(tempC);
      Serial.print(" grados Celsius\n");
      
      switch (ciclo){
        case 1:
          tempC1=tempC;
          break;
        case 2:
          tempC2=tempC;
          break;  
        case 3:
          tempC3=tempC;
          break;
        case 4:
          tempC4=tempC;
          break;
        case 5:
          tempC5=tempC;
          break;
        case 6:
          tempC6=tempC;
          break;        
      }
      // Espera cinco segundo para repetir el loop
      delay(6000);
    }
    tempTotal=tempC1+tempC2+tempC3+tempC4+tempC5+tempC6;
    tempTotal=tempTotal/6;
    Serial.print("Temperatura media en el ultimo minuto: ");
    Serial.print(tempTotal);
    Serial.print("\n \n");
}
