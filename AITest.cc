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

int bfsf(Pos pf)
{
  Matrix visited(37, Row(37, 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(pf.i, pf.j));
  dQ.push(8);
  visited[pf.i][pf.j] = 'T';
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    //Above
    Cell cel = cell(x,y-1);
    cerr << y-1<<endl;
    if (y > 0 && visited[x][y-1] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 4;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x, (y-1)));
      if(dir == 8)dQ.push(4);
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    //Left
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 6;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x-1, y));
      if(dir == 8)dQ.push(6);
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    //Right
    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 2;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x+1, y));
      if(dir == 8)dQ.push(2);
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }

    //Below
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 0;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x, y+1));
      if(dir == 8)dQ.push(0);
      else dQ.push(dir);
      visited[x][y+1] = 'T';
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
    VE f = farmers(0);
    for (int id : f) {
      Pos pos = unit(id).pos;
      cerr<<"Soc "<< unit(id).pos << " estic a "<<pos ;
      int direction = bfsf(pos);
      cerr <<"direccion del bfs:"<< direction << endl; //chivato
      //if (round()%10) direction= Dir(2*random(0, 3));
      Cell c;
      if (direction==0 and !((c = cell(pos + Dir(0))).haunted) and c.id ==-1) command(id, Dir(0));
      else if (direction==2 and !(c = cell(pos + Dir(2))).haunted and c.id ==-1) command(id, Dir(2));
      else if (direction==4 and !(c = cell(pos + Dir(4))).haunted and c.id ==-1) command(id, Dir(4));
      else if (direction==6 and !(c = cell(pos + Dir(6))).haunted and c.id ==-1) command(id, Dir(6));
      else command(id, Dir(0));
      /*Cell c;
      if((direction == 0)  and !((c = cell(pos + Dir(0))).haunted) and c.id ==-1) {command(id, Dir(0));cerr<<"primer if c: "<< c.id<<endl;}
      else if (direction == 2 and !(c = cell(pos + Dir(2))).haunted and c.id ==-1) {command(id, Dir(2)); cerr<<"segon if c: "<< c.id<<endl;}
      else if (direction == 4 and !(c = cell(pos + Dir(4))).haunted and c.id ==-1) {command(id, Dir(4)); cerr<<"tercer if c: "<< c.id<<endl;}
      else if (direction == 6 and !(c = cell(pos + Dir(6))).haunted and c.id ==-1) {command(id, Dir(6)); cerr<<"quart if c: "<< c.id<<endl;}
      else {command(id, Dir(8));cerr<<"acabo entrando en el none"<<endl;}
      cerr<< "-----------------" <<endl;*/


 /*     c = cell(pos + Dir(0));
      //cerr << c.type <<endl;
      if((c = cell(pos + Dir(0))).type == 0 and !(c = cell(pos + Dir(0))).haunted) command(id, Dir(0));
      else if ((c = cell(pos + Dir(2))).type == 0 and !(c = cell(pos + Dir(2))).haunted) command(id, Dir(2));
      else if ((c = cell(pos + Dir(4))).type == 0 and !(c = cell(pos + Dir(4))).haunted) command(id, Dir(4));
      else if ((c = cell(pos + Dir(6))).type == 0 and !(c = cell(pos + Dir(6))).haunted) command(id, Dir(6));
      else command(id, Dir(7));*/
    }

    
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
