const int DEBOUNCE_DELAY = 50;

class DigitalInputPin {
public:
  DigitalInputPin(int pin) {
    m_pin = pin;
    m_isHigh = false;
    m_lastWasHigh = false;
    m_lastDebounceTime = 0;
    pinMode(m_pin, INPUT);
  }

  bool isHigh() {
    return m_isHigh;
  }

  void update() {
    bool isHighNow = (digitalRead(m_pin) == HIGH);
    if (isHighNow != m_lastWasHigh) {
      m_lastDebounceTime = millis();
    }
    if ((millis() - m_lastDebounceTime) > DEBOUNCE_DELAY) {
      if (isHighNow != m_isHigh)
        m_isHigh = isHighNow;
    }
    m_lastWasHigh = isHighNow;
  }

private:
  int m_pin;
  bool m_isHigh;
  bool m_lastWasHigh;
  int m_lastDebounceTime;
};

class Button {
public:
  Button(int pin) :
    m_pin(pin),
    m_isPressed(false),
    m_wasClicked(false)
  {}
  
  void update() {
    m_pin.update();
    if (m_pin.isHigh()) {
      if (!m_isPressed) {
        m_wasClicked = true;
      }
      m_isPressed = true;
    }
    else {
      m_isPressed = false;
    }
  }

  bool wasClicked() {
    bool result = m_wasClicked;
    m_wasClicked = false;
    return result;
  }
  
private:
  DigitalInputPin m_pin;
  bool m_isPressed;
  bool m_wasClicked;
};

//const int GETTER_BUTTON_PIN = 9;
//Button getterButton(GETTER_BUTTON_PIN);
const int LEFT_BUTTON_PIN = 9;
const int MIDDLE_BUTTON_PIN = 8;
const int RIGHT_BUTTON_PIN = 7;
Button leftButton(LEFT_BUTTON_PIN);
Button middleButton(MIDDLE_BUTTON_PIN);
Button rightButton(RIGHT_BUTTON_PIN);

void setup() {
  Serial.begin(115200);
}

void loop() {
//  getterButton.update();
//  if (getterButton.wasClicked())
//    Serial.write('g');
  leftButton.update();
  middleButton.update();
  rightButton.update();
  if (leftButton.wasClicked())
    Serial.write('l');
  if (middleButton.wasClicked())
    Serial.write('m');
  if (rightButton.wasClicked())
    Serial.write('r');
}
