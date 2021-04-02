void movePlayerUp(){
  if(playerY>0) {
    playerY-=3;
  }
}

void movePlayerDown(){
   if(playerY<100) {
    playerY+=3;
  }
}

void movePlayerLeft(){
  if(playerX>0) {
    playerX-=3;
  }
}

void movePlayerRight(){
    if(playerX<112) {
    playerX+=3;
  }
}


void movePlayer(){ 
  if(upFlag) movePlayerUp();
  if(downFlag) movePlayerDown();
  if(leftFlag) movePlayerLeft();
  if(rightFlag) movePlayerRight();
}
