#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
class cmd{
    public: 
        int rows;
        int cols;       
        string cmds;
        int col_pos;
};
class blocks{
    public:
        blocks(string &t){
            type=t;
            if(type=="T1")
                strncpy(shape,"nrqrr",5);
            else if(type=="L1")
                strncpy(shape,"yrqu",5);     //n y q r u l
            else if(type=="J1")
                strncpy(shape,"yruu",5);
            else if(type=="S1")
                strncpy(shape,"yrur",5);
            else if(type=="I1")
                strncpy(shape,"yuuu",5);
            else if(type=="T2")
                strncpy(shape,"nrqru",5);
            else if(type=="L2")
                strncpy(shape,"yurr",5);
            else if(type=="J2")
                strncpy(shape,"yrrql",5);
            else if(type=="S2")
                strncpy(shape,"nrqrq",5);
            else if(type=="I2")
                strncpy(shape,"yrrr",5);
            else if(type=="T3")
                strncpy(shape,"yrrq",5);
            else if(type=="L3")
                strncpy(shape,"nruul",5);
            else if(type=="J3")
                strncpy(shape,"yuur",5);
            else if(type=="Z1")
                strncpy(shape,"nrrql",5);
            else if(type=="O")
                strncpy(shape,"yrqr",5);
            else if(type=="T4")
                strncpy(shape,"yurq",5);
            else if(type=="L4")
                strncpy(shape,"yrru",5);
            else if(type=="J4")        //    ffffffffffffffffff
                strncpy(shape,"f",5);
            else if(type=="Z2")
                strncpy(shape,"yuru",5);
            cout<<shape;

        }
    private:
        char shape[5];
        string type;

};
int read_file(cmd* command){
    int flag=0,i=0;
    ifstream fin("tetris.data.txt");  
    do{
        if(!flag){
            fin>>command[i].rows>>command[i].cols;
            flag=1;
        }
        fin>>command[i].cmds>>command[i].col_pos;
        if(command[i].cmds=="End")
            break;
        i++;
    }while(!fin.eof());
    
    fin.close();
    return i;
}
int main(){
    int rows,cols;
    int flag=0;
    cmd command[1005];
    int cmd_lenth=read_file(command);
    blocks k(command[3].cmds);
    /*cout<<cmd_lenth;
    for(int j=0;j<cmd_lenth;j++){
        cout<<command[j].cmds<<" "<<command[j].col_pos<<endl;
    }*/

return 0;
}
