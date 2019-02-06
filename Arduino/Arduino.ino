typedef unsigned int uint;
typedef unsigned long ulong;

#define led 10

#define ground A0
#define power A1
#define sig A2

#define sample_ms 15

void setup() {
    pinMode(13, INPUT);
    pinMode(led, OUTPUT);
    
    pinMode(ground, OUTPUT);
    pinMode(power, OUTPUT);
    pinMode(sig, INPUT);
    digitalWrite(ground, LOW);
    digitalWrite(power, HIGH);
    
    analogReference(DEFAULT);
    Serial.begin(9600);
}


ulong update = 0;
ulong sum = 0;
ulong samples = 0;

void loop() {
    
    sum += analogRead(sig);
    samples++;
    
    if(millis() - update < sample_ms)
        return;
    update += sample_ms;
    
    uint v = sum / samples;
    analogWrite(led, linear_led(v));
    Serial.println(v);
    
    sum = samples = 0;
}

//v is 0 to 1023
//return is 0 to 255
//v is 0 to 1023
//return is 0 to 255
uint linear_led(uint v) {
    static const byte lut[17] = {0, 1, 2, 3, 4, 6, 8, 11, 16, 23, 32, 45, 64, 90, 128, 180, 255};
    
    if(v > 1022)
        return 255;
    if(v == 0)
        return 0;
    
    v += 1;
    uint i = v / 64; //64 = max_v / len(lut)
    uint rem = v % 64;
    uint bl = lut[i]; //Exponential segment
    uint bh = lut[i+1];
    return bl + (bh*rem - bl*rem)/64; //Integer efficient form of bl + (bh-bl)*(rem/64)
}