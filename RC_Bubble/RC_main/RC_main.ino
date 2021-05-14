// Radio controlled Motor

const int RC_btn_1 = 28; 
const int RC_btn_2 = 26;
const int RC_mem_nRec = 27;
const int hw_btn_1 = 16;
const int hw_btw_2 = 5;
const int hw_led_1 = 9;
const int hw_led_2 = 11;
const int hw_pwm_out = 8;

const int loop_rate = 50;

int LED1state = 0;
int LED2state = 0;
bool dir = true;

unsigned int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RC_btn_1, INPUT);
  pinMode(RC_btn_2, INPUT);
  pinMode(RC_mem_nRec, INPUT);
  pinMode(hw_btn_1,INPUT);

  pinMode(hw_led_1, OUTPUT);
  pinMode(hw_led_2, OUTPUT);

  Serial.begin(9600);

  count = 0;

  delay(loop_rate);

}

void loop() {
  // put your main code here, to run repeatedly:
//  int RC_mem_state = digitalRead(RC_mem_nRec);
//  int Btn1_state = digitalRead(hw_btn_1);


  analogWrite(hw_led_1, LED1state);
  
  analogWrite(hw_led_2, LED2state);

  if (LED2state > 249) dir = false;
  else if (LED2state < 10) dir = true;
  
  LED1state = sawtooth(LED1state);
  LED2state = triangle(LED2state, dir);

  count++;
  delay(loop_rate);
  
}



int sawtooth(int state) {
  state += 5;
  if (state > 250) state = 10;
  return state;
}
  
int triangle(int state, bool dir) {
  if(dir == true) state += 5;
  else state -= 5;
  return state;
    
}
