

int s0 = 43;
int s1 = 45;
int binv = 47;
int cin = 49;

int a0 = 23;
int a1 = 25;

int b0 = 31;
int b1 = 33;
 

int del = 700;



void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(binv, OUTPUT);
  pinMode(cin, OUTPUT);
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
}

void loop() {
digitalWrite(a0, HIGH);
digitalWrite(a1, LOW);
digitalWrite(b0, HIGH);
digitalWrite(b1, LOW);
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, LOW); 
  digitalWrite(cin, HIGH); 
  delay(del);   

digitalWrite(a0, HIGH);
digitalWrite(a1, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(b1, HIGH);
          
  digitalWrite(s0, LOW); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, LOW);   
  digitalWrite(cin, HIGH); 
  delay(del); 

digitalWrite(a0, LOW);
digitalWrite(a1, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(b1, HIGH);
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW); 
  digitalWrite(binv, LOW);  
  digitalWrite(cin, HIGH); 
  delay(del);   

digitalWrite(a0, HIGH);
digitalWrite(a1, HIGH);
digitalWrite(b0, LOW);
digitalWrite(b1, HIGH);        
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW); 
  digitalWrite(binv, LOW);  
  digitalWrite(cin, HIGH); 
  delay(del); 

digitalWrite(a0, LOW);
digitalWrite(a1, LOW);
digitalWrite(b0, HIGH);
digitalWrite(b1, HIGH);
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, HIGH); 
  delay(del);  

digitalWrite(a0, LOW);
digitalWrite(a1, HIGH);
digitalWrite(b0, LOW);
digitalWrite(b1, HIGH);         
  digitalWrite(s0, LOW); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, HIGH);   
  digitalWrite(cin, HIGH); 
  delay(del); 

digitalWrite(a0, HIGH);
digitalWrite(a1, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(b1, LOW);
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, HIGH); 
  delay(del);   

digitalWrite(a0, LOW);
digitalWrite(a1, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(b1, HIGH);        
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, HIGH); 
  delay(del); 

digitalWrite(a0, HIGH);
digitalWrite(a1, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(b1, HIGH);
  
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, LOW); 
  digitalWrite(cin, LOW); 
  delay(del);           
  digitalWrite(s0, LOW); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, LOW);   
  digitalWrite(cin, LOW); 
  delay(del); 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW); 
  digitalWrite(binv, LOW);  
  digitalWrite(cin, LOW); 
  delay(del);           
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW); 
  digitalWrite(binv, LOW);  
  digitalWrite(cin, LOW); 
  delay(del); 
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, LOW); 
  delay(del);           
  digitalWrite(s0, LOW); 
  digitalWrite(s1, HIGH); 
  digitalWrite(binv, HIGH);   
  digitalWrite(cin, LOW); 
  delay(del); 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, LOW); 
  delay(del);           
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW); 
  digitalWrite(binv, HIGH);  
  digitalWrite(cin, LOW); 
  delay(del); 



}
