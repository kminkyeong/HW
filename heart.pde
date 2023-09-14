void heart(int x,int y, float d){
  noStroke();
  fill(255,51,51);
  rect(x-1*d,y,22*d,9*d);
  rect(x+29*d,y,22*d,9*d);
  rect(x-10*d,y+9*d,70*d,9*d);
  rect(x-10*d,y+18*d,70*d,9*d);
  rect(x,y+27*d,50*d,9*d);
  rect(x+10*d,y+36*d,30*d,9*d);
  rect(x+20*d,y+45*d,10*d,9*d);
  fill(255);
  rect(x,y+9*d,9*d,9*d);
}

void heart_delete(int x,int y, float d){
  noStroke();
  fill(176,196,222);
  rect(x-10*d, y, 70*d, 60*d);
}//하트가림막생성
