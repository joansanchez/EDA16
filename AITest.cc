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

int bfsf(int xx, int yy)
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

    //Left
    Cell cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && cel.type == 0) {
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


    //Right
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && cel.type == 0) {
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


    //Above
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0) {
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


    //Below
    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && cel.type == 0) {
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
      int xx = pos.i;
      int yy = pos.j;

      cerr<<"Soc "<< unit(id).id << " estic a "<<pos ;
      int direction = bfsf(xx, yy);
      cerr <<"direccion del bfs:"<< direction << endl; //chivato
      //if (round()%10) direction= Dir(2*random(0, 3));
      Cell c;
      /*if(direction==0) command(id, Dir(0));
      else if (direction==2) command(id, Dir(2));
      else if (direction==4) command(id, Dir(4));
      else if (direction==6) command(id, Dir(6));
      else  command(id, Dir(8));*/

      if (direction==0 and !((c = cell(pos + Dir(0))).haunted) and c.id ==-1) command(id, Dir(0));
      if (direction==2 and !(c = cell(pos + Dir(2))).haunted and c.id ==-1) command(id, Dir(2));
      if (direction==4 and !(c = cell(pos + Dir(4))).haunted and c.id ==-1) command(id, Dir(4));
      if (direction==6 and !(c = cell(pos + Dir(6))).haunted and c.id ==-1) command(id, Dir(6));
      if (direction==8) command(id, Dir(8));
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
