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

int bfsf(int xx, int yy, bool aleft, bool aright, bool atop, bool abottom) //casilla vacia mas cercana
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
    if(!aleft) aleft = true;
    else {
    cel = cell(x,y-1);
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
    }

    //Right
    if(!aright) aright = true;
    else{
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
    }

    //Above
    if(!atop) atop = true;
    else{
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
    }

    //Below
    if(!abottom) abottom = true;
    else{
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
      int xx = pos.i;
      int yy = pos.j;
      bool aleft, aright, atop, abottom;
      aleft = aright = atop = abottom = true;
      int direction = bfsf(xx, yy, aleft, aright, atop, abottom);
      Cell c;
      int dir2;



      if (direction == 0){
        if(!((c = cell(pos + Dir(0))).haunted) and c.id ==-1) command(id, Dir(0));
        else {
          if(!((c = cell(pos + Dir(2))).haunted) and c.id ==-1) command(id, Dir(2));
          else if (!((c = cell(pos + Dir(6))).haunted) and c.id ==-1) command(id, Dir(6));
          else if (!((c = cell(pos + Dir(4))).haunted) and c.id ==-1) command(id, Dir(4));
        }
      }
      if (direction == 2){
        if(!((c = cell(pos + Dir(2))).haunted) and c.id ==-1) command(id, Dir(2));
        else {
          aright = false;
          command(id, Dir(bfsf(xx, yy, aleft, aright, atop, abottom)));
        }
      }
      if (direction == 4){
        if(!((c = cell(pos + Dir(4))).haunted) and c.id ==-1) command(id, Dir(4));
        else {
          atop = false;
          dir2 = bfsf(xx, yy, aleft, aright, atop, abottom);
          if(!((c = cell(pos + Dir(dir2))).haunted) and c.id ==-1) command(id, Dir(dir2));
        }
      }
      if (direction == 6){
        if(!((c = cell(pos + Dir(6))).haunted) and c.id ==-1) command(id, Dir(6));
        else {
          aleft = false;
          command(id, Dir(bfsf(xx, yy, aleft, aright, atop, abottom)));
        }
      }
      //if (direction==0 and !((c = cell(pos + Dir(0))).haunted) and c.id ==-1) command(id, Dir(0));
      //if (direction==2 and !(c = cell(pos + Dir(2))).haunted and c.id ==-1) command(id, Dir(2));
      //if (direction==4 and !(c = cell(pos + Dir(4))).haunted and c.id ==-1) command(id, Dir(4));
      //if (direction==6 and !(c = cell(pos + Dir(6))).haunted and c.id ==-1) command(id, Dir(6));
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
     VE k = knights(0);
    if (round()%2 == 0) {
      for (int id : k) {
        VE D;
        Pos pos = unit(id).pos;
        for (int d = 0; d < 8; ++d) {
          int id2 = cell(pos + Dir(d)).id;
          if (id2 != -1) {
            Unit u = unit(id2);
            if (u.player != 0 and u.type != Witch) D.push_back(d);
          }
        }
        if (D.empty()) command(id, Dir(random(0, 7)));
        else command(id, Dir(D[random(0, D.size() - 1)]));
      }
    }
    else {
      int num = k.size();
      vector<Dir> v(num);
      for (int i = 0; i < num; ++i) v[i] = Dir(2*(i%4) + 1);
      vector<int> perm = random_permutation(num);
      for (int i = 0; i < num; ++i) command(k[i], v[perm[i]]);
    }




   VE w = witches(0);
    if (round() < 40) command(w[0], Top);
    else if (round() < 80) command(w[0], Left);
    else if (round() < 120) command(w[0], None);
    else if (round() < 160) command(w[0], Bottom);
    else {
      set<Pos> s;
      while ((int)s.size() < 4) s.insert(Pos(random(0, 36), random(0, 36)));
      vector<Pos> v(s.begin(), s.end());
      if (v[random(0, 3)].i < 18) command(w[0], None);
      else command(w[0], Top);
    }

    int id = w[1];
    if (status(0) > 0.8) command(id, Left);
    else if (total_score(1) > 10000) command(id, Bottom);
    else if (land(3) > 100) command(id, Right);
    else if (cell(35, 35).type == Wall) command(id, None);
    else if (unit(id).health < 40) command(id, Top);
    else if (cell(10, 20).owner == 2) command(id, None);
    else if (not cell(20, 10).haunted) command(id, None);
    else if (pos_ok(unit(id).pos + Pos(20, 30))) command(id, Left);
    else if (pos_ok(unit(id).pos.i + random(-5, 5), 10)) command(id, Bottom);
    else if (not unit(id).active) command(id, Right);
    else cerr << unit(id).pos << endl; // You can print to cerr to debug.
    
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
