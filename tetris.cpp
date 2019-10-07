#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class space;
class cmd{
    public: 
        int rows;
        int cols;       
        string cmds;
        int col_pos;
};
class blocks{
    public:
        friend space;
        void set_shape(string &t,int check_pt){              //l左 r右 u上 d下         //z左下  c右下 q左上  e右上
            type=t;
            if(type=="T1"){
                if(check_pt==1) strncpy(shape,"yrrz",4);
                else if(check_pt==2||check_pt>=20) strncpy(shape,"yqrr",4);
                else if(check_pt==3) strncpy(shape,"yllc",4);
            }                
            else if(type=="L1"){
                if(check_pt==1) strncpy(shape,"yrqu",4);  
                else if(check_pt==2) strncpy(shape,"yluu",4);
            }
            else if(type=="J1"){
                if(check_pt==1)strncpy(shape,"yruu",4);
                else if(check_pt==2)strncpy(shape,"yleu",4);
            }                
            else if(type=="S1"){
                if(check_pt==1) strncpy(shape,"yrur",4);
                else if(check_pt==2) strncpy(shape,"yler",4);
                else if(check_pt==3) strncpy(shape,"yldl",4);
            }                
            else if(type=="I1"){
                strncpy(shape,"yuuu",4);
            }                
            else if(type=="T2")
                strncpy(shape,"nrqru",4);
            else if(type=="L2")
                strncpy(shape,"yurr",4);
            else if(type=="J2")
                strncpy(shape,"yrrql",4);
            else if(type=="S2")
                strncpy(shape,"nrqrq",4);
            else if(type=="I2")
                strncpy(shape,"yrrr",4);
            else if(type=="T3")
                strncpy(shape,"yrrq",4);
            else if(type=="L3")
                strncpy(shape,"nruul",4);
            else if(type=="J3")
                strncpy(shape,"yuur",4);
            else if(type=="Z1")
                strncpy(shape,"nrrql",4);
            else if(type=="O")
                strncpy(shape,"yrqr",4);
            else if(type=="T4")
                strncpy(shape,"yurq",4);
            else if(type=="L4")
                strncpy(shape,"yrru",4);
            else if(type=="J4")        //    ffffffffffffffffff
                strncpy(shape,"f",4);
            else if(type=="Z2")
                strncpy(shape,"yuru",4);
            for(int i=0;i<4;i++){
                cout<<shape[i];
            }
            cout<<endl;
        }                                  
    private:
        char shape[4];
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
class space{
    public:
        void remove();
        space(int a,int b){
            rows=a;
            cols=b;
            window = new int* [rows];
            for(int i=0;i<rows;i++){
                window[i]=new int [cols];
            }
            highest=new int [cols];   
            memset(highest,0,cols*sizeof(int));
        }
       // ~space();
        void push(cmd*,int);
        int gethigh(int);

    private:
        int rows;
        int cols;
        int **window;
        int *highest;
    

};
void space::push(cmd* command,int cmd_length ){
    int i=1,j=1;
    int col_pos,row_pos;
    blocks block[cmd_length];
    //cout<<gethigh(command[0].col_pos);
    for(i=0;i<cmd_length;i++){
        block[i].set_shape(command[i].cmds,gethigh(command[i].col_pos)-command[i].col+1);
    }

/*
    for(j=command.col_pos;j<=block.highrange;j++){        
        int** newwindow;
        newwindow=new int*[rows];
        for( i=0;i<rows;i++){
            newwindow[i]=new int [cols];
        }


        
        if(j==block.highrange){              // 右邊  掉下來卡到的情況
            newwindow[highest[j]][block.highrange]=1;
            row_pos=highest[j];         //highest 空的那個
            col_pos=j;
            for(int k=0;k<5;k++){
                if(block.shape[k]=='l'){
                    col_pos--;
                }
                else if(block.shape[k]=='d'){
                    row_pos--;
                }
                else if(){

                }
                window[row_pos][col_pos]=1;
            }            
        }
        

    }*/
    //window[highest[j]][j]
    
}
int space::gethigh(int start){
    int i;
    int tmp=highest[start];
    int high=start;
    for(i=start+1;i<=4;i++){
        cout<<highest[i];
        if(highest[i]>tmp){
            tmp=highest[i];
            high=i;
        }            
        else if(highest[i]==tmp)
            high=99;
    }
    return high;
}
int main(){
    int rows,cols;
    int flag=0;
    char *a;
    cmd command[1005];
    int cmd_length=read_file(command);
    space sp(command[0].rows,command[0].cols);
    sp.push(command,cmd_length);

    //cout<<cmd_length;
   /* for(int j=0;j<cmd_lenth;j++){
        cout<<command[j].cmds<<" "<<command[j].col_pos<<endl;
    }*/

return 0;
}
