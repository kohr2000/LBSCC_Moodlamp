// written for Little Bodhi Electronics Workshop - Moodlamp
//
// After converting your colors to RGB, write the RGB values down
// below in the format of {R, G, B}
// eg. 
// 255, 255, 255 which gives you white

// You can add as many colors as you want but remember that
// there will be colors in between your chosen colors too
// so around 3-4 is plenty

int colors[] = {
  255, 0, 0,
  0, 255, 0,
  0, 0, 255,
};

int color1[]={0,255,0};
int color2[]={0,0,255};
int color3[]={255,0,0};
int color4[]={0,0,0};

// you can adjust the speed that the colors change (from 1-100)
// putting 0 or negative numbers will cause the LED to not light up
#define SPEED 5


// You do not need to adjust the rest of the code




#define RED 3
#define GREEN 5
#define BLUE 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (SPEED <= 0){
    while (1==1){
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int k = 0; k<(sizeof(colors)/2); k+=3){
    for (int i = 0; i<256; i++){
      analogWrite(RED, mapping(i, colors[k],colors[(k+3)%(sizeof(colors)/2)]));
      analogWrite(GREEN, mapping(i, colors[k+1],colors[(k+4)%(sizeof(colors)/2)]));
      analogWrite(BLUE, mapping(i, colors[k+2],colors[(k+5)%(sizeof(colors)/2)]));
      delay(100/SPEED);
    }
  }
}

int mapping (int index, int origvalue, int newvalue){
  if (origvalue>newvalue){
    return map(255-index, 0, 255, newvalue, origvalue);
  }
  else if (origvalue<newvalue){
    return map(index, 0, 255, origvalue, newvalue);
  }
  else{
    return newvalue;
  }
}

