void charc3(float x, float y, float d){
  fill(255,182,193);
  pushMatrix();  //왼쪽 귀
  translate(x-6*d,y-3*d);
  rotate(radians(140));
  ellipse(0,0,7*d,2*d);
  popMatrix();
   
  fill(255,182,193); 
  pushMatrix();  //오른쪽 귀
  translate(x+5*d,y-7*d);
  rotate(radians(130));
  ellipse(0,0,7*d,2*d);
  popMatrix();
  
  fill(255,228,225);
  ellipse(x,y+1*d,12*d,5*d);  //얼굴 하관
  arc(x,y,10*d,14*d,PI,2*PI);  //얼굴
  
  fill(0);
  ellipse(x,y+0.5*d,1.5*d,d);  //코
  
  //왼쪽 눈
  fill(0);  
  ellipse(x-2*d,y-d,d,2*d);  //큰 눈
  fill(255);
  ellipse(x-2*d,y-d,0.5*d,1*d);  //작은 눈
  //오른쪽 눈
  fill(0);  
  ellipse(x+2*d,y-d, d, 2*d);  //큰 눈
  fill(255);
  ellipse(x+2*d,y-d,0.5*d,d);  //작은 눈
}
