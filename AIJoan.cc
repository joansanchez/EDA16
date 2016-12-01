#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Joan 


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

void distancies(Matrix &G,  int xx, int yy, int maxdist) //en uso
{
  Matrix visited(G.size(), Row(G[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(0);
  visited[xx][yy] = 'T';
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dist = dQ.front() + 1;
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; i += 2){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)G[0].size() - 1 and p.i > 0 and p.i < (int)G.size() - 1 and visited[p.i][p.j]=='F' and dist <= maxdist){
        Q.push(make_pair(p.i, p.j));
        dQ.push(dist);
        visited[p.i][p.j] = 'T';
        G[p.i][p.j]='X';
      }
    }
 
    Q.pop();
    dQ.pop();
  }
}



  void omplir_farmers(Matrix &mf){ //en uso
    //bruixes
    Cell com;
    Pos pos;
    int x;
    int y;
    for(int wp = 0; wp < 4; ++wp){
      VE wit = witches(wp);
      for (int id : wit) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mf[x][y] = 'X';
        if(unit(id).active) distancies(mf, x, y, 3);
      }
    }

    //Cavallers
    for(int kp = 1; kp < 4; ++kp){
      VE kni = knights(kp);
      for (int id : kni) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mf[x][y] = 'X';
        distancies(mf, x, y, 1);
        if(mf[x][y-1]=='X' and mf[x-1][y]=='X') mf[x-1][y-1] = 'X';
        if(mf[x][y+1]=='X' and mf[x-1][y]=='X') mf[x-1][y+1] = 'X';
        if(mf[x][y-1]=='X' and mf[x+1][y]=='X') mf[x+1][y-1] = 'X';
        if(mf[x][y+1]=='X' and mf[x+1][y]=='X') mf[x+1][y+1] = 'X';
      }
    }

  }

  void omplir_knights(Matrix &mk){ //en uso
    Cell com;
    Pos pos;
    int x;
    int y;
    for(int wp = 0; wp < 4; ++wp){
      VE wit = witches(wp);
      for (int id : wit) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mk[x][y] = 'X';
        if(unit(id).active) distancies(mk, x, y, 3);
      }
    } 
  }



  int bfsf(const Matrix &mf,int xx, int yy) //casilla vacia mas cercana. En uso
  {
  Matrix visited(mf.size(), Row(mf[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  vector<bool> direc (4, true); //serveix per comprovar que es a primera veegada que sortim d-aquella posicio
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; i += 2){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)mf[0].size() - 1 and p.i > 0 and p.i < (int)mf.size() - 1 && visited[p.i][p.j] == 'F' && mf[p.i][p.j] != 'X' && cel.type == 0 && cel.id == -1) {
        if (cel.owner != 0 and direc[i/2]) {
        direc[i/2] = false;
        return i;
      }
      else if (cel.owner != 0 and !direc[i/2]) return dir;
      Q.push(make_pair(p.i, p.j));
      if(direc[i/2]){
        direc[i/2] = false;
        dQ.push(i);
      }
      else dQ.push(dir);
      visited[p.i][p.j] = 'T';
      }
      else direc[i/2] = false;
    }
     Q.pop();
    dQ.pop();
  }
  
  //No vertexes found
  return 8;
  }


int bfsk(const Matrix &mk,int xx, int yy) //enemigo mas cercano
  {
  Matrix visited(mk.size(), Row(mk[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  vector<bool> direc (7, true); //serveix per comprovar que es a primera veegada que sortim d-aquella posicio
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; ++i){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)mk[0].size() - 1 and p.i > 0 and p.i < (int)mk.size() - 1 && visited[p.i][p.j] == 'F' && mk[p.i][p.j] != 'X' && cel.type == Empty) {
        if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and unit(cel.id).player != 0) and direc[i]) {
        direc[i] = false;
        return i;
      }
      else if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and unit(cel.id).player != 0) and !direc[i]) return dir;
      Q.push(make_pair(p.i, p.j));
      if(direc[i]){
        direc[i] = false;
        dQ.push(i);
      }
      else dQ.push(dir);
      visited[p.i][p.j] = 'T';
      }
      else direc[i] = false;
    }
     Q.pop();
    dQ.pop();
  }
  
  //No vertexes found
  return 8;
  }

int bfsw(Matrix &mw,int xx, int yy) //casilla vacia mas cercana. En uso
  {
  Matrix visited(mw.size(), Row(mw[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  vector<bool> direc (4, true); //serveix per comprovar que es a primera veegada que sortim d-aquella posicio
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; i += 2){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)mw[0].size() - 1 and p.i > 0 and p.i < (int)mw.size() - 1 && visited[p.i][p.j] == 'F' && mw[p.i][p.j] != 'A' && cel.type == 0 && unit(cel.id).player != 0) {
        if ((cel.id != -1 and unit(cel.id).type == Knight and unit(cel.id).player != 0) and direc[i/2]) {
        direc[i/2] = false;
        mw[p.i][p.j] = 'A';
        return i;
      }
      else if ((cel.id != -1 and  unit(cel.id).type == Knight and unit(cel.id).player != 0) and !direc[i/2]){ 
        mw[p.i][p.j] = 'A';
        return dir;
      }
      Q.push(make_pair(p.i, p.j));
      if(direc[i/2]){
        direc[i/2] = false;
        dQ.push(i);
      }
      else dQ.push(dir);
      visited[p.i][p.j] = 'T';
      }
      else direc[i/2] = false;
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
  
  Matrix matfarmers(rows(), Row(cols())); //zones on el farmer no pot anar: bruixes i cavallers
  omplir_farmers(matfarmers);
  Matrix matknights(rows(), Row(cols())); //zones on els cavallers no poden anar: bruixes
  omplir_knights(matknights);
  Matrix matwitches(rows(), Row(cols()));
  //omplir_knights(matwitches);

  //farmers
  VE f = farmers(0);
    for (int id : f) {
      Pos pos = unit(id).pos;
      int x = pos.i;
      int y = pos.j;
      command(id, Dir(bfsf(matfarmers, x, y)));
    }

 
  //knights
    VE k = knights(0);
    for (int id : k) {
      Pos pos = unit(id).pos;
      int x = pos.i;
      int y = pos.j;
      command(id, Dir(bfsk(matknights, x, y)));
    }
 
  //witches 
    VE w = witches(0);
    for (int id : w) {
      Pos pos = unit(id).pos;
      int x = pos.i;
      int y = pos.j;
      command(id, Dir(bfsw(matwitches, x, y)));
    }
  
}
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);