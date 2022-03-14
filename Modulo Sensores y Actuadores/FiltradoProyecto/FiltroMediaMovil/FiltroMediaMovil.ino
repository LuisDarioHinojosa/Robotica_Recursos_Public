#define CONVERSION 2.046
#define pinLM35 A0 // Variable del pin de entrada del sensor (A0)




// el tamaño se define con base a samples
float arr[100]; // arreglo muestras
float pivot[101]; // arreglo pivote media movil
float output[96]; // arreglo output media movil


int nSamples = 100;
int nPivot = nSamples+1;
int nOutput = nSamples-4;

// fills and array with samples
void takeSamples(float arr[],int n){
  float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
  float v; // valor para almencar el voltaje 
  for(int i = 0; i < n; i++){
      v = analogRead(pinLM35);    
      tempC = v/CONVERSION; // sin opam
      arr[i] = tempC;
      delay(250);
    }
  }


void llenarPivote(float samples[],float pivot[], int nSamples, int nPivot){
    for(int i = 0; i < nPivot; i++){
        if(i == 0){
          pivot[i] = 0.0;
          }
        else{
          pivot[i] = samples[i-1];
          }
      }
  }


// calcula el filtro mediaMovil 
void filtroMediaMovil(float pivot[],float output[],int nPivot){
  float average;
  for(int i = 0; i < nPivot-4; i++){
      average = pivot[i] + pivot[i+1] + pivot[i+2]+pivot[i+3]+pivot[i+4];
      output[i] = average/5.0;
    }
    
  }

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);

}




 
void loop() {
  Serial.println("Start Transmition");
  delay(1000);

  Serial.println(nSamples);
  
  takeSamples(arr,nSamples);
  Serial.println("Samples:");
  for(int i = 0; i < nSamples; i++){
      Serial.println(arr[i]);
      delay(100);
    }
  llenarPivote(arr,pivot,nSamples, nPivot);
  Serial.println("Pivot:");
  for(int i = 0; i < nPivot; i++){
      Serial.println(pivot[i]);
      delay(100);
  }
  filtroMediaMovil(pivot,output,nPivot);
  Serial.println("Output:");
  for(int i = 0; i < nOutput; i++){
      Serial.println(output[i]);
      delay(100);
  } 
  Serial.println("End Transmition");
  
}
