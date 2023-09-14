float [] a, b, c, vx, vy;
int j, k;
void setup() {
  size(1500, 800);

  a = new float[12];
  b = new float[12];
  c = new float[12];
  vx = new float[12];
  vy = new float[12];
  for (int i=0; i<12; i++) {
    a[i] = random(width);
    b[i] = random(height);
    c[i] = random(8, 16);
    vx[i] = random(4, 6);
    vy[i] = random(4, 6);
  }

  j = (int)random(0, 12);    //키보드로 동작하는 캐릭터 정하기
  k = (int)random(0, 12);
  while (true) {              //두 캐릭터가 다르도록 설정
    if (j==k)  k = (int)random(0, 12);
    else  break;
  }
}

int life_1 = 3;    //player1 life
int life_2 = 3;    //player2 life
int score = 0;
int life_cnt_1 = 0;    //player1 누적 life cnt
int life_cnt_2 = 0;    //player2 누적 life cnt
PFont font;
int game_over=0;
void draw() {
  background(176, 196, 222);

  heart(1300, 40, 0.7);    //player2 heart 표시
  heart(1350, 40, 0.7);
  heart(1400, 40, 0.7);

  heart(100, 40, 0.7);    //player1 heart 표시
  heart(150, 40, 0.7);
  heart(200, 40, 0.7);
  if (life_2==2)  heart_delete(1300, 40, 0.7);    //player2 heart 제거
  else if (life_2==1) {
    heart_delete(1300, 40, 0.7);
    heart_delete(1350, 40, 0.7);
  } else if (life_2<=0) {
    heart_delete(1300, 40, 0.7);
    heart_delete(1350, 40, 0.7);
    heart_delete(1400, 40, 0.7);
    game_over=2;
  }

  if (life_1==2)  heart_delete(100, 40, 0.7);    //player1 heart 제거
  else if (life_1==1) {
    heart_delete(100, 40, 0.7);
    heart_delete(150, 40, 0.7);
  } else if (life_1<=0) {
    heart_delete(100, 40, 0.7);
    heart_delete(150, 40, 0.7);
    heart_delete(200, 40, 0.7);
    game_over=1;
  }
  score++;

  for (int i=0; i<12; i++) {      //캐릭터 움직이기
    if (i != j && i != k) {
      a[i] += vx[i];
      b[i] += vy[i];
      if (a[i]<0 || a[i]>width) vx[i] = -vx[i];
      if (b[i]<0 || b[i]>height) vy[i] = -vy[i];
    }

    if (keyPressed) {     //키보드(wasd)로 캐릭터 움직이기 -> player1
      if (a[j]<=width && 0<=a[j] && b[j]<=height && 0<=b[j]) {    //캐릭터가 벽을 넘어가지 못하도록 설정
        if (key == 'w')  b[j] -= 1;
        else if (key == 'a')  a[j] -= 1;
        else if (key == 's')  b[j] += 1;
        else if (key == 'd')  a[j] += 1;
      } else {    //벽에 닿으면 중간위치로 이동
        a[j] = 750;
        b[j] = 400;
      }

      if (key == CODED) {      //키보드(방향키)로 캐릭터 움직이기 -> player2
        if (a[k]<=width && 0<=a[k] && b[k]<=height && 0<=b[k]) {    //캐릭터가 벽을 넘어가지 못하도록 설정
          if (keyCode == UP)  b[k] -= 1;
          else if (keyCode == LEFT)  a[k] -= 1;
          else if (keyCode == DOWN)  b[k] += 1;
          else if (keyCode == RIGHT)  a[k] += 1;
        } else {    //벽에 닿으면 중간위치로 이동
          a[k] = 750;
          b[k] = 400;
        }
      }
    }

    if (i<4)  charc1(a[i], b[i], c[i]);    //캐릭터함수1 이동
    else if (3<i && i<8)  charc2(a[i], b[i], c[i]);    //캐릭터함수2 이동
    else if (7<i && i<12)  charc3(a[i], b[i], c[i]);    //캐릭터함수3 이동


    for (int m=0; m<4; m++) {      //캐릭터함수1과 특정 캐릭터와의 충돌 계산
      if (j!=m) {      //player1의 충돌 측정
        if ((a[j] <= a[m]+10*c[m] && a[m]-10*c[m] <= a[j]) && (b[j] <= b[m]+10*c[m] && b[m]-10*c[m] <= b[j])) {
          life_cnt_1++;
        }
      }
      if (k!=m) {      //player2의 충돌 측정
        if ((a[k] <= a[m]+10*c[m] && a[m]-10*c[m] <= a[k]) && (b[k] <= b[m]+10*c[m] && b[m]-10*c[m] <= b[k])) {
          life_cnt_2++;
        }
      }
    }

    for (int m=4; m<8; m++) {    //캐릭터함수2와 특정 캐릭터와의 충돌 계산
      if (j!=m) {
        if ((a[j] <= a[m]+6*c[m] && a[m]-6*c[m] <= a[j]) && (b[j] <= b[m]+8*c[m] && b[m]-8*c[m] <= b[j])) {
          life_cnt_1++;    //player1의 충돌 측정
        }
      }
      if (k!=m) {
        if ((a[k] <= a[m]+0.7*c[m] && a[m]-0.7*c[m] <= a[k]) && (b[k] <= b[m]+8*c[m] && b[m]-8*c[m] <= b[k])) {
          life_cnt_2++;    //player2의 충돌 측정
        }
      }
    }

    for (int m=8; m<12; m++) {    //캐릭터함수3과 특정 캐릭터와의 충돌 계산
      if (j!=m) {
        if ((a[j] <= a[m]+10*c[m] && a[m]-10*c[m] <= a[j]) && (b[j] <= b[m]+14*c[m] && b[m]-14*c[m] <= b[j])) {
          life_cnt_1++;    //player1의 충돌 측정
        }
      }
      if (k!=m) {
        if ((a[k] <= a[m]+10*c[m] && a[m]-10*c[m] <= a[k]) && (b[k] <= b[m]+14*c[m] && b[m]-14*c[m] <= b[k])) {
          life_cnt_2++;    //player2의 충돌 측정
        }
      }
    }

    if (life_cnt_1 > 1500) {
      life_1-=1;
      life_cnt_1=0;
    }
    if (life_cnt_2 > 1500) {
      life_2-=1;
      life_cnt_2=0;
    }
  }

  if ((life_1==0)||(life_2==0)) {
    for (int i=0; i<12; i++) {
      vx[i] = 0;
      vy[i] = 0;
    }

    if (game_over==1) {
      fill(119, 136, 153);
      stroke(119, 136, 153);
      rect(0, 200, width, 400);

      fill(255, 240, 245);
      font=loadFont("SnapITC-Regular-48.vlw");
      textFont(font, 120);
      text("Game Over", 400, 400);

      textFont(font, 60);
      text("player 2 wins!!", 500, 500);
      noLoop();
    } else if (game_over==2) {
      fill(119, 136, 153);
      stroke(119, 136, 153);
      rect(0, 200, width, 400);

      fill(255, 240, 245);
      font=loadFont("SnapITC-Regular-48.vlw");
      textFont(font, 120);
      text("Game Over", 400, 400);

      textFont(font, 60);
      text("player 1 wins!!", 500, 500);
      noLoop();
    }
  }
}
