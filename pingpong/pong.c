#include <stdio.h>


void Draw(int BallPosX, int BallPosY, int PlatformL, int PlatformR);

void clear();



int main(void) {
    int scoreL = 0;
    int scoreR = 0;
    int PlatformL = 13;  // координаты центра левой платформы    x=3
    int PlatformR = 13;  // координаты центра правой платформы   x=78
    int BallPosX = 21, BallPosY = PlatformL;
    int BALLX = 1;  // скорость по х
    int BALLY = 1;  // скорость по у
    Draw(BallPosX, BallPosY, PlatformL, PlatformR);
    char step, c;
    while (scoreL !=21 && scoreR !=21) {
      // проверка на ввод только одного числа
        if ((scanf("%c%c", &step, &c) == 2) && (c == '\n') && ((step == ' ') || (step == 'z') ||
        (step == 'Z') || (step == 'a') || (step == 'A') || (step == 'm') ||
        (step == 'M') || (step == 'k') || (step == 'K'))) {
          // BALL
          if (BallPosX == 1) {  // если забили левому игроку
            scoreR = scoreR+1;
            BallPosX = 75;
            BallPosY = PlatformR;
          }
          if (BallPosX == 78) {  // если забили правому игроку
            scoreL = scoreL+1;
            BallPosX = 5;
            BallPosY = PlatformL;
          }
            // если ударяется об верхнюю границу слева
          if (BallPosY == 1 && BALLX > 0 && BALLY < 0) BALLY = 1;
            // если ударяется об верхнюю границу справа
          if (BallPosY == 1 && BALLX < 0  && BALLY < 0) BALLY = BALLY*-1;
            // если ударяется об нижнюю границу справa
          if (BallPosY == 24 && BALLX < 0 && BALLY > 0) BALLY = BALLY*-1;
            // если ударяется об нижнюю границу слева
          if (BallPosY == 24 && BALLX > 0 && BALLY > 0) BALLY = BALLY*-1;
            // если ударяется об левую платформу
            // если мяч ударился в центр плаформы, летит прямо
          if ((BallPosY == PlatformL) && (BallPosX == 5)) {
            BALLX = 1;
            BALLY = 0;
          }
            // если мяч ударился в верхнюю часть, летит вверх
          if ((BallPosY == PlatformL-1) && (BallPosX == 5)) {
            BALLX = 1;
            BALLY = -1;
          }
            // если мяч ударился в нижнюю часть, летит вниз
          if ((BallPosY == PlatformL+1) && (BallPosX == 5)) {
            BALLX = 1;
            BALLY = 1;
          }
            // если ударяется об правую платформу
            // если мяч ударился в центр плаформы, летит прямо
          if ((BallPosY == PlatformR) && (BallPosX == 75)) {
            BALLX = -1;
            BALLY = 0;
          }
            // если мяч ударился в верхнюю часть, летит вверх
          if ((BallPosY == PlatformR-1) && (BallPosX == 75)) {
            BALLX = -1;
            BALLY = -1;
          }
            // если мяч ударился в нижнюю часть, летит вниз
          if ((BallPosY == PlatformR+1) && (BallPosX == 75)) {
            BALLX = -1;
            BALLY = 1;
          }
          BallPosX = BallPosX+BALLX;
          BallPosY = BallPosY+BALLY;
            // если а тогда проверяем не упирается ли в стенку и двигаем
          if (step == 'z') {
            if (PlatformL+2 == 25) {
            } else {
            PlatformL = PlatformL+1;
            }
            clear();
            Draw(BallPosX, BallPosY, PlatformL, PlatformR);
          }
            // если z проверяем границы и двигаем левую платформу
          if (step == 'a') {
            if (PlatformL-2 == 0) {
            } else {
            PlatformL = PlatformL-1;
            }
            clear();
            Draw(BallPosX, BallPosY, PlatformL, PlatformR);
            }
            // если к проверяем границы и двигаем правую платформу
          if (step == 'm') {
            if (PlatformR+2 == 25) {
            } else {
            PlatformR = PlatformR+1;
            }
            clear();
            Draw(BallPosX, BallPosY, PlatformL, PlatformR);
          }
            // если м проверяем границы и двигаем правую платформу
          if (step == 'k') {
            if (PlatformR-2 == 0) {
            } else {
            PlatformR = PlatformR-1;
            }
            clear();
            Draw(BallPosX, BallPosY, PlatformL, PlatformR);
          }
         printf("%40d:%d\n", scoreL, scoreR);
        }
      if (scoreL == 21) printf("WIN LEFT");
      if (scoreR == 21) printf("WIN RIGHT");
    }
  return 0;
}
void Draw(int BallPosX, int BallPosY, int PlatformL, int PlatformR) {
  for (int y = 0; y <= 25; y++) {
    for (int x = 0; x <= 80; x++) {
     if (y == 0 || y == 25) {
      printf("-");
    } else if (x == 0 || x == 80 || x == 40) {
      if (x == BallPosX && y == BallPosY) {
        printf("o");
        } else {
      printf("|");
      }
    // печать правой платформы
    } else if ((x == 76) && (y == PlatformR || y == PlatformR+1 || y == PlatformR-1)) {
      printf("I");
    // печать левой платформы
    } else if ((x == 3) && (y == PlatformL || y == PlatformL+1 || y == PlatformL-1)) {
      printf("I");
    } else if (x == BallPosX && y == BallPosY) {  // печать мяча
      printf("o");
    } else {
        printf(" ");
    }
    }
      printf("\n");
    }
}
void clear() {
  printf("\33c\e[3J");
}

