#include <iostream>
#include <fstream>
using namespace std;
class cmd{
    public:
        string cmds;
        int col_pos;

};

int main(){
  int rows,cols,i=0;
  char s[100][100];
  int flag=0;
  ifstream fin("tetris.data.txt");

  cmd command[100];
  do{
    if(!flag){
        fin>>rows>>cols;
        flag=1;
    }
    fin>>command[i].cmds>>command[i].col_pos;
    if(command[i].cmds=="End")
        break;
    i++;
  }while(!fin.eof());

    for(int j=0;j<i;j++){
        cout<<command[j].cmds<<" "<<command[j].col_pos<<endl;
    }
fin.close();
return 0;
}
