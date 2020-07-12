uint8_t ADC_val[CH_NUM * 2];

void AD7606_Init(){
        AD7606_IOSet();
        AD7606_SetDF(0);                 //default:OS2 OS1 OS0 = 000
        AD7606_SetInputRange(0);         //default:range = -5 ~ +5
        AD7606_Reset();
}

//hook function,used to set input range.
void AD7606_SetInputRange(int _ucRange){
        
}
//hook function,used to set digital filter.
void AD7606_SetDF(uint8_t _ucMode){
        
}
//reset function
void AD7606_Reset(){
        digitalWrite(CS , HIGH);
        digitalWrite(CVAB , HIGH);
         /* AD7606 is high level reset，at least 50ns */
        digitalWrite(RST, LOW);
        //delayMicroseconds(1);
        digitalWrite(RST, HIGH);
        //delayMicroseconds(1);
        digitalWrite(RST, LOW);
}

void AD7606_IOSet(){
        pinMode(RST , OUTPUT);
        pinMode(CVAB, OUTPUT);
        pinMode(CS  , OUTPUT);
        pinMode(BUSY, INPUT);
        pullUpDnControl(BUSY, PUD_UP);
        digitalWrite(RST, LOW);
        digitalWrite(CS , HIGH);
        digitalWrite(CVAB , HIGH);
}

void AD7606_StartConv(){
        /* Conv in rising edge，at least 25ns  */
        digitalWrite(CVAB, LOW);
        //delayMicroseconds(1);
        digitalWrite(CVAB, HIGH);
}
//Software Poll
bool AD7606_StartADC(){        
        if (digitalRead(BUSY) == 0){
                digitalWrite(CS, LOW); 
                if (wiringPiSPIDataRW (SPI_CHANNEL_0, ADC_val, CH_NUM * 2) == -1){
                printf("SPI failure: %s\n", strerror(errno));
                }
                digitalWrite(CS, HIGH);  
                AD7606_StartConv();                         
                while(digitalRead(BUSY) == 0);
                return true;
        }
        else{
                printf("Value is not ready: %s\n", strerror(errno));
                return false;
        }
}
