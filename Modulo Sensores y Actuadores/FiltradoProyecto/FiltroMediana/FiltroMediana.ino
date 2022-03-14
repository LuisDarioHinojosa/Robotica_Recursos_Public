#define CONVERSION 2.046
#define pinLM35 A0 // Variable del pin de entrada del sensor (A0)




// el tamaño se define con base a samples
float arr[100]; // arreglo muestras
float output[96]; // arreglo output media movil
float median[5];

int nSamples = 30;
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




void bubbleSort(float values[], int length)
{
   int i, j, flag = 1;
   float temp;
   for (i = 1; (i <= length) && flag; i++)
   {
      flag = 0;
      for (j = 0; j < (length - 1); j++)
      {
         if (values[j + 1] < values[j])
         {
            temp = values[j];
            values[j] = values[j + 1];
            values[j + 1] = temp;
            flag = 1;
         }
      }
   }
}
 
void filtroMediana(float samples[],float output[],float median[], int nSamples,int nMedian){
    for(int i = 0; i < nSamples -4; i++){
        median[0] = samples[i];
        median[1] = samples[i+1];
        median[2] = samples[i+2];
        median[3] = samples[i+5];
        median[4] = samples[i+4];
        bubbleSort(median,nMedian);
        output[i] = median[2];
      }
  }

/*
void bubbleSort(float samples[],int n){
  float placeholder;
  int right = n-1;
  while(right > 0){
      int k = 0;
      for(int i = 0; i < right; i++){
          if(samples[i+1] < samples[i]){
              placeholder = samples[i+1];
              samples[i+1] = samples[i];
              samples[i] = placeholder;
              k = i;
            }
            right = k;
        }
    }

  }
*/



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

  filtroMediana(arr,output,median,nSamples,3);
  Serial.println("Filtro Mediana");
  for(int i = 0; i < nOutput; i++){
      Serial.println(output[i]);
      delay(100);
    }
   
  /*
  bubbleSort(arr,nSamples);
  Serial.println("Samples Sorted");
  for(int i = 0; i < nSamples; i++){
      Serial.println(arr[i]);
      delay(100);
    }
   */
  
  Serial.println("End Transmition");

  
}
