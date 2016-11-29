#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Test
#define ROWSCOL 37

struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
typedef vector<int> VE;
typedef vector<char> Row;
typedef vector<Row> Matrix;

Matrix llegir_matriu(Matrix &gps){
  Cell com;
  Pos pos;
  int xx;
  int yy;
  //farmers
  VE far1 = farmers(0);
    for (int id : far1) {
      pos = unit(id).pos;
      xx = pos.i;
      yy = pos.j;
      gps[xx][yy] = 'G';
    }
  for (int f4 = 1; f4 < 4; ++f4){
    VE far = farmers(f4);
    for (int id : far) {
      pos = unit(id).pos;
      xx = pos.i;
      yy = pos.j;
      gps[xx][yy] = 'F'; 
    }
  }
  for(int wp = 0; wp < 4; ++wp){
    VE wit = witches(wp);
    for (int id : wit) {
      pos = unit(id).pos;
      xx = pos.i;
      yy = pos.j;
      gps[xx][yy] = 'W';
      if (gps[xx][yy-1]=='W'  or gps[xx][yy+1]=='W'  or gps[xx-1][yy]=='W'  or gps[xx+1][yy]=='W'){//desactivar les caselles de les dos bruixes
      }
      else{
        if (xx > 0 and xx < 36 and yy-1 > 0 and yy < 36) gps[xx][yy-1] = 'R';
        if (xx > 0 and xx < 36 and yy-2 > 0 and yy < 36) gps[xx][yy-2] = 'R';
        if (xx > 0 and xx < 36 and yy-3 > 0 and yy < 36) gps[xx][yy-3] = 'R';
        if (xx > 0 and xx < 36 and yy > 0 and yy+1 < 36) gps[xx][yy+1] = 'R';
        if (xx > 0 and xx < 36 and yy > 0 and yy+2 < 36) gps[xx][yy+2] = 'R';
        if (xx > 0 and xx < 36 and yy > 0 and yy+3 < 36) gps[xx][yy+3] = 'R';
        if (xx -1 > 0 and xx < 36 and yy-1 > 0 and yy < 36) gps[xx-1][yy-1] = 'R';
        if (xx -1 > 0 and xx < 36 and yy-2 > 0 and yy < 36) gps[xx-1][yy-2] = 'R';
        if (xx -1 > 0 and xx < 36 and yy > 0 and yy < 36) gps[xx-1][yy] = 'R';
        if (xx -1 > 0 and xx < 36 and yy > 0 and yy + 1 < 36) gps[xx-1][yy+1] = 'R';
        if (xx -1 > 0 and xx < 36 and yy > 0 and yy + 2 < 36) gps[xx-1][yy+2] = 'R';

        if (xx > 0 and xx + 1 < 36 and yy-1 > 0 and yy < 36) gps[xx+1][yy-1] = 'R';
        if (xx > 0 and xx + 1 < 36 and yy-2 > 0 and yy < 36) gps[xx+1][yy-2] = 'R';
        if (xx > 0 and xx + 1 < 36 and yy > 0 and yy < 36) gps[xx+1][yy] = 'R';
        if (xx > 0 and xx + 1 < 36 and yy > 0 and yy + 1 < 36) gps[xx+1][yy+1] = 'R';
        if (xx > 0 and xx + 1 < 36 and yy > 0 and yy + 2 < 36) gps[xx+1][yy+2] = 'R';

        if (xx -2 > 0 and xx < 36 and yy-1 > 0 and yy < 36) gps[xx-2][yy-1] = 'R';
        if (xx -2 > 0 and xx < 36 and yy > 0 and yy < 36) gps[xx-2][yy] = 'R';
        if (xx -2 > 0 and xx < 36 and yy+1 > 0 and yy < 36) gps[xx-2][yy+1] = 'R';

        if (xx  > 0 and xx + 2 < 36 and yy-1 > 0 and yy < 36) gps[xx+2][yy-1] = 'R';
        if (xx  > 0 and xx + 2 < 36 and yy > 0 and yy < 36) gps[xx+2][yy] = 'R';
        if (xx  > 0 and xx + 2 < 36 and yy+1 > 0 and yy < 36) gps[xx+2][yy+1] = 'R';

        if (xx -3 > 0 and xx < 36 and yy > 0 and yy < 36) gps[xx-3][yy] = 'R';
        if (xx  > 0 and xx + 3 < 36 and yy > 0 and yy < 36) gps[xx+3][yy] = 'R';
      }
    }
  }

  VE kni1 = knights(0);
    for (int id : kni1) {
      pos = unit(id).pos;
      xx = pos.i;
      yy = pos.j;
      gps[xx][yy] = 'C';
    }
  for (int f4 = 1; f4 < 4; ++f4){
    VE kni2 = knights(f4);
    for (int id : kni2) {
      pos = unit(id).pos;
      xx = pos.i;
      yy = pos.j;
      gps[xx][yy] = 'K'; 
      if (xx > 0 and xx < 36 and yy-1 > 0 and yy < 36) gps[xx][yy-1] = 'A';
      if (xx > 0 and xx < 36 and yy > 0 and yy+1 < 36) gps[xx][yy+1] = 'A';
      if (xx -1 > 0 and xx < 36 and yy-1 > 0 and yy < 36) gps[xx-1][yy-1] = 'A';
      if (xx -1 > 0 and xx < 36 and yy > 0 and yy < 36) gps[xx-1][yy] = 'A';
      if (xx -1 > 0 and xx < 36 and yy > 0 and yy + 1 < 36) gps[xx-1][yy+1] = 'A';
      if (xx > 0 and xx + 1 < 36 and yy-1 > 0 and yy < 36) gps[xx+1][yy-1] = 'A';
      if (xx > 0 and xx + 1 < 36 and yy > 0 and yy < 36) gps[xx+1][yy] = 'A';
      if (xx > 0 and xx + 1 < 36 and yy > 0 and yy + 1 < 36) gps[xx+1][yy+1] = 'A';

    }
  }
  return gps;
}

bool segura(const Matrix &G,int nm, int x1, int y1){
  if(nm==0){
  if (G[x1][y1] != 'A' and G[x1][y1] != 'R') return true;
  else return false;
  }
  else return false;
}

bool ocupada (const Matrix &G, int nm, int x1, int y1){
  if(nm==0){
  if (G[x1][y1] == 'F' or G[x1][y1] == 'G') return true;
  else return false;
  }
  else return false;
}

int bfsf(const Matrix &segur, int xx, int yy, bool aleft, bool aright, bool atop, bool abottom) //casilla vacia mas cercana
{
  Matrix visited(37, Row(37, 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  bool abv1, bot1, lef1, righ1;
  abv1 = bot1 = lef1 = righ1 = true;
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();


    Cell cel;
    //Below
    if(!abottom) abottom = true;
    else{
    cel = cell(x+1,y);
    if (segura(segur, 0, x+1, y) && x < 37 - 1 && visited[x+1][y] == 'F' && cel.type == 0 &&  cel.id == -1) {
      if (cel.owner != 0 and bot1) {
        bot1 = false;
        return 0;
      }
      else if (cel.owner != 0 and !bot1) return dir;
      Q.push(make_pair(x+1, y));
      if(bot1){
        bot1 = false;
        dQ.push(0);
      }
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }
    else bot1 = false;
    }

    //Right
    if(!aright) aright = true;
    else{
    cel = cell(x,y+1);
    if (segura(segur, 0, x, y+1) && y < 37 - 1 && visited[x][y+1] == 'F' && cel.type == 0 &&  cel.id == -1) {
      if (cel.owner != 0 and righ1) {
        righ1 = false;
        return 2;
      }
      else if (cel.owner != 0 and !righ1) return dir;
      Q.push(make_pair(x, y+1));
      if(righ1){
        righ1 = false;
        dQ.push(2);
      }
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    else righ1 = false;
    }

    //Left
    if(!aleft) aleft = true;
    else {
    cel = cell(x,y-1);
    if (segura(segur, 0, x, y-1) && y > 0 && visited[x][y-1] == 'F' && cel.type == 0  && cel.id == -1) {
      if (cel.owner != 0 and lef1) {
        lef1 = false;
        return 6;
      }
      else if (cel.owner != 0 and !lef1) return dir;
      Q.push(make_pair(x, (y-1)));
      if(lef1){
        lef1 = false;
        dQ.push(6);
      }
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    else lef1 = false; 
    }

    
    //Above
    if(!atop) atop = true;
    else{
    cel = cell(x-1,y);
    if (segura(segur, 0, x-1, y) && x > 0 && visited[x-1][y] == 'F' && cel.type == 0 && cel.id == -1) {
      if (cel.owner != 0 and abv1) {
        abv1 = false;
        return 4;
      }
      else if (cel.owner != 0 and !abv1) return dir;
      Q.push(make_pair(x-1, y));
      if(abv1){
        abv1 = false;
        dQ.push(4);
      }
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    else abv1 = false;
    }

    
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return pos_seg(segur, xx, yy);
}

int pos_seg(const Matrix &segur, int xx, int yy) //casilla vacia mas cercana
{
  Matrix visited(37, Row(37, 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  bool abv1, bot1, lef1, righ1;
  abv1 = bot1 = lef1 = righ1 = true;
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();

    Cell cel;
    //Left
    cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && cel.type == 0 && segura(segur, 0, x, y-1)) {
      if (!ocupada(segur, 0, x, y-1) and lef1) {
        lef1 = false;
        return 6;
      }
      else if (cel.owner != 0 and !lef1) return dir;
      Q.push(make_pair(x, (y-1)));
      if(lef1){
        lef1 = false;
        dQ.push(6);
      }
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    else lef1 = false; 
    

    //Right
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && cel.type == 0 && segura(segur, 0, x, y+1) ) {
      if (!ocupada(segur, 0, x, y+1) and righ1) {
        righ1 = false;
        return 2;
      }
      else if (!ocupada(segur, 0, x, y+1) and !righ1) return dir;
      Q.push(make_pair(x, y+1));
      if(righ1){
        righ1 = false;
        dQ.push(2);
      }
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    else righ1 = false;
    

    //Above
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0 && segura(segur, 0, x-1, y)) {
      if (!ocupada(segur, 0, x-1, y) and abv1) {
        abv1 = false;
        return 4;
      }
      else if (!ocupada(segur, 0, x-1, y) and !abv1) return dir;
      Q.push(make_pair(x-1, y));
      if(abv1){
        abv1 = false;
        dQ.push(4);
      }
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    else abv1 = false;
    

    //Below
    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && cel.type == 0 && segura(segur, 0, x+1, y) ) {
      if (!ocupada(segur, 0, x+1, y) and bot1) {
        bot1 = false;
        return 0;
      }
      else if (!ocupada(segur, 0, x+1, y) and !bot1) return dir;
      Q.push(make_pair(x+1, y));
      if(bot1){
        bot1 = false;
        dQ.push(0);
      }
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }
    else bot1 = false;
    
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return 8;
}

int atac(const Matrix &radar, int xx, int yy, int tipo) //casilla vacia mas cercana
{
  Matrix visited(37, Row(37, 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  bool abv1, bot1, lef1, righ1;
  abv1 = bot1 = lef1 = righ1 = true;
  bool tr, tl, br, bl;
  tr = tl = br = bl = true;
  
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();

    Cell cel;
    //Left
    cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && cel.type == 0) {
      if ((radar[x][y-1]=='k' or radar[x][y-1]=='F') and lef1) {
        lef1 = false;
        return 6;
      }
      else if ((radar[x][y-1]=='k' or radar[x][y-1]=='F') and !lef1) return dir;
      Q.push(make_pair(x, (y-1)));
      if(lef1){
        lef1 = false;
        dQ.push(6);
      }
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    else lef1 = false; 
    

    //Right
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && cel.type == 0 ) {
      if ((radar[x][y+1]=='k' or radar[x][y+1]=='F') and righ1) {
        righ1 = false;
        return 2;
      }
      else if ((radar[x][y+1]=='k' or radar[x][y+1]=='F') and !righ1) return dir;
      Q.push(make_pair(x, y+1));
      if(righ1){
        righ1 = false;
        dQ.push(2);
      }
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    else righ1 = false;
    

    //Above
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0) {
      if ((radar[x-1][y]=='k' or radar[x-1][y]=='F') and abv1) {
        abv1 = false;
        return 4;
      }
      else if (radar[x-1][y]=='k' or radar[x-1][y]=='F') return dir;
      Q.push(make_pair(x-1, y));
      if(abv1){
        abv1 = false;
        dQ.push(4);
      }
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    else abv1 = false;
    

    //Below
    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && cel.type == 0) {
      if ((radar[x+1][y]=='k' or radar[x+1][y]=='F') and bot1) {
        bot1 = false;
        return 0;
      }
      else if ((radar[x+1][y]=='k' or radar[x+1][y]=='F') and !bot1) return dir;
      Q.push(make_pair(x+1, y));
      if(bot1){
        bot1 = false;
        dQ.push(0);
      }
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }
    else bot1 = false;




    if(tipo == 2){
      //TR
        cel = cell(x+1,y+1);
        if (x > 0 && y < 37 - 1 && visited[x+1][y+1] == 'F' && cel.type == 0) {
          if ((radar[x+1][y+1]=='k' or radar[x+1][y+1]=='F') and tr) {
            tr = false;
            return 3;
          }
          else if ((radar[x+1][y+1]=='k' or radar[x+1][y+1]=='F') and !tr) return dir;
          Q.push(make_pair(x+1, y+1));
          if(tr){
            tr = false;
            dQ.push(3);
          }
          else dQ.push(dir);
          visited[x+1][y+1] = 'T';
    }
    else tr = false;
    
      //TL
        cel = cell(x+1,y-1);
        if (x > 0 && y > 0 && visited[x+1][y-1] == 'F' && cel.type == 0) {
          if ((radar[x+1][y-1]=='k' or radar[x+1][y-1]=='F') and tl) {
            tl = false;
            return 5;
          }
          else if ((radar[x+1][y-1]=='k' or radar[x+1][y-1]=='F') and !tl) return dir;
          Q.push(make_pair(x+1, y-1));
          if(tl){
            tl = false;
            dQ.push(5);
          }
          else dQ.push(dir);
          visited[x+1][y-1] = 'T';
    }
    else tl = false;    


      //BL
        cel = cell(x-1,y-1);
        if (x < 37 - 1 && y > 0 && visited[x-1][y-1] == 'F' && cel.type == 0) {
          if ((radar[x-1][y-1]=='k' or radar[x-1][y-1]=='F') and bl) {
            bl = false;
            return 7;
          }
          else if ((radar[x-1][y-1]=='k' or radar[x-1][y-1]=='F') and !bl) return dir;
          Q.push(make_pair(x-1, y-1));
          if(bl){
            bl = false;
            dQ.push(7);
          }
          else dQ.push(dir);
          visited[x-1][y-1] = 'T';
    }
    else bl = false; 

    //BR
        cel = cell(x-1,y+1);
        if (x < 37 - 1 && y < 37 - 1 && visited[x-1][y+1] == 'F' && cel.type == 0) {
          if ((radar[x-1][y+1]=='k' or radar[x-1][y+1]=='F') and br) {
            br = false;
            return 1;
          }
          else if ((radar[x-1][y+1]=='k' or radar[x-1][y+1]=='F') and !br) return dir;
          Q.push(make_pair(x-1, y+1));
          if(br){
            tr = false;
            dQ.push(1);
          }
          else dQ.push(dir);
          visited[x-1][y+1] = 'T';
    }
    else br = false;
    }
    
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return 8;
}


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    Matrix gps(37, Row(37));
    llegir_matriu(gps);
    VE f = farmers(0);
    for (int id : f) {
      Pos pos = unit(id).pos;
      int xx = pos.i;
      int yy = pos.j;
      bool aleft, aright, atop, abottom;
      aleft = aright = atop = abottom = true;
      int direction = bfsf(gps, xx, yy, aleft, aright, atop, abottom);
      Cell c;
      int dir2;
      
      if (direction==0) command(id, Dir(0));
      if (direction==2) command(id, Dir(2));
      if (direction==4) command(id, Dir(4));
      if (direction==6) command(id, Dir(6));
      if (direction==8) command(id, Dir(8));
     
    }
     /*VE k = knights(0);
      for (int id : k) {
        Pos pos = unit(id).pos;
        if (unit(id).health<100)command(id, Dir(pos_seg(gps, pos.i, pos.j)));
        else command(id, Dir(atac(gps, pos.i, pos.j, 2))); 
      }



  VE w = witches(0);
      for (int id : k) {
        Pos pos = unit(id).pos;
        if (round()<10) command(id, Dir(8));
        else command(id, Dir(atac(gps, pos.i, pos.j, 2)));
      }*/
    
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
