// C++ code
#include<math.h>
//

int adc = 0;

double v = 0.0;

double Rf1 = 0.0;

double Rf2 = 0.0;

double F = 0.0;


void setup()

{

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(A0, INPUT);

  Serial.begin(9600);
  

}



double getForce(double v){
  double force;
  if(v > 0 && v <= 3.4848){
    force = -((-13.824+sqrt(-55.324*v+194.5275316))/(27.662));
  }
  else if(v > 3.4848 && v <= 4.3597){
    force = exp((v-4.0159)/(0.5304));
  }
  
  else if(v > 4.3597 && v <= 4.6823){
    force = -((-0.2072+sqrt(-0.0648*v+0.30301312))/(0.0324));  
  }
  
  else{
    force = exp((v-4.3547)/(0.1817));
  }
  
  return force;


}

void loop()

{

    adc = analogRead(A0);

    v = adc*5.000/1023.000;

    Rf1 = (((-v*66000)+(66000*5))/v);

    Rf2 = ((5*66000)/(v))-66000;
  
  	F = getForce(v);
	

  	Serial.print("V: ");
    Serial.print(v,4);
	  Serial.print(" | ");
  	Serial.print("F: ");
  	Serial.print(F,4);
  	Serial.println();

}