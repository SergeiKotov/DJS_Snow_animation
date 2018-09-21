// Animation moving

int animPin = 9;  // Пин соленойда
int buttonPin = 4;  // Пин кнопки
int ledKeyPin = 6;  // Пин транзистора включающего LED кнопки 
int pwmVol; // PWM signal's volume

void setup() {
  pinMode(animPin, OUTPUT);
  pinMode(ledKeyPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledKeyPin, HIGH);
}

void loop() {
  // Waiting for the button
  if (digitalRead(buttonPin) == HIGH){
    digitalWrite(ledKeyPin, LOW);
    // Работаем в полную силу
    for (int i = 0; i < 3; i++){
      Serial.println(i);
      // Animation FORWARD
      moving (0, 255, 1);
      //Pause
      delay(1000);
      // Animation BACK
      moving (255, 0, 1);
      //Pause
      delay(1000);
    }
    // Работаем на 50% 2 раза
        for (int i = 0; i < 2; i++){
      // Animation FORWARD
      moving (0, 70, 1);
      //Pause
      delay(500);
      // Animation BACK
      moving (70, 0, 1);
      //Pause
      delay(500);
    }

  } else {
    digitalWrite(ledKeyPin, HIGH);
  }
}

// Функция движения соленоида (начальная мощность PWM сигнала(позиция), конечная мощьность(позиция), задержка в цикле)
void moving (int pwmFrom, int pwmTo, int delayTime){
  int k;
  if (pwmFrom < pwmTo){
    k = 1;
  } else {
    k = -1;
  }
  for (pwmVol = pwmFrom; pwmVol != pwmTo; pwmVol = pwmVol + k){
    analogWrite(animPin, pwmVol);
    delay(delayTime);
  }
}

