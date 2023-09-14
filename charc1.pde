void charc1(float x, float y, float d){

  fill(255, 255, 51);
  pushMatrix();    //left ear
  translate(x+0.8*d, y-5.5*d);
  rotate(radians(115));
  ellipse(0, 0, 2*d, d);
  popMatrix();
  
  pushMatrix();    //left ear
  translate(x-0.8*d, y-5.5*d);
  rotate(radians(65));
  ellipse(0, 0,  2*d, d);
  popMatrix();
  
  circle(x, y, 10*d);    //body
  
  fill(0);
  ellipse(x-1.5*d, y-2*d, 0.8*d, 1.4*d);    //right eye
  ellipse(x+1.5*d, y-2*d, 0.8*d, 1.4*d);    //left eye
    
  fill(255, 153, 51);
  ellipse(x, y, 5*d, 1.5*d);    //mouth
  
  pushMatrix();    //right feet
  translate(x+2.5*d, y+3.5*d);
  rotate(radians(145));
  ellipse(0, 0, 3*d, 1.6*d);
  popMatrix();
  
  pushMatrix();    //left feet
  translate(x-2.5*d, y+3.5*d);
  rotate(radians(35));
  ellipse(0, 0, 3*d, 1.6*d);
  popMatrix();
}
