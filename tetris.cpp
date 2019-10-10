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
        void get_range(string & t){
           if(t=="T1"){
                range=3;
            }
            else if(t=="L1"){
                range=2;
            }
            else if(t=="J1"){
                range=2;
            }
            else if(t=="S1"){
                range=3;
            }
            else if(t=="I1"){
                range=1;
            }
            else if(t=="T2"){
                range=2;
            }
            else if(t=="L2"){
                range=3;
            }
            else if(t=="J2"){
                range=3;
            }
            else if(t=="S2"){
                range=2;
            }
            else if(t=="I2"){
                range=4;
            }

            else if(t=="T3"){
                range=3;
            }

            else if(t=="L3"){
                range=2;
            }
            else if(t=="J3"){
                range=2;
            }
            else if(t=="Z1"){
                range=3;
            }
            else if(t=="O"){
                range=2;
            }
            else if(t=="T4"){
                range=2;
            }
            else if(t=="L4"){
                range=3;
            }
            else if(t=="J4"){
                range=3;
            }
            else if(t=="Z2"){
                range=2;
            }
        }
        void set_shape(string &t,int check_pt){
            shape=new char[3];
            relative_pos=check_pt;          //l左 r右 u上 d下         //z左下  c右下 q左上  e右上  //f 往右跳兩格 g往左跳兩格

            type=t;
            if(type=="T1"){
                range=3;
                if(check_pt==1) strncpy(shape,"rrz",3);
                else if(check_pt==2||check_pt>=20) {
                    strncpy(shape,"qrr",3);
                    relative_pos=2;
                }
                else if(check_pt==3) strncpy(shape,"llc",3);
            }
            else if(type=="L1"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"rqu",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"luu",3);
            }
            else if(type=="J1"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"ruu",3);
                    relative_pos=1;
                }
                else if(check_pt==2)strncpy(shape,"leu",3);
            }
            else if(type=="S1"){
                range=3;
                if(check_pt==1||check_pt>=20) {
                    strncpy(shape,"rur",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"ler",3);
                else if(check_pt==3) strncpy(shape,"ldl",3);
            }
            else if(type=="I1"){
                range=1;
                strncpy(shape,"uuu",3);
                if(check_pt>=20){
                    relative_pos=1;
                }
            }
            else if(type=="T2"){
                range=2;
                if(check_pt==1) strncpy(shape,"cuu",3);
                else if(check_pt==2||check_pt>=20){
                    strncpy(shape,"qru",3);
                    relative_pos=2;
                }
            }
            else if(type=="L2"){
                range=3;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"urr",3);
                    relative_pos=1;
                }
                else if(check_pt==2)strncpy(shape,"zuf",3);
                else if (check_pt==3)strncpy(shape,"lld",3);
            }
            else if(type=="J2"){
                range=3;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"ucr",3);
                    relative_pos=1;
                }
                else if(check_pt==2)strncpy(shape,"rgu",3);
                else if(check_pt==3)strncpy(shape,"llu",3);
            }
            else if(type=="S2"){
                range=2;
                if(check_pt==1)strncpy(shape,"cuq",3);
                else if(check_pt==2||check_pt>=20){
                    strncpy(shape,"ulu",3);
                    relative_pos=2;
                }
            }
            else if(type=="I2"){
                range=4;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"rrr",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"lfr",3);
                else if(check_pt==3) strncpy(shape,"grf",3);
                else if(check_pt==4) strncpy(shape,"lll",3);
            }

            else if(type=="T3"){
                range=3;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"rrq",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"lec",3);
                else if(check_pt==3) strncpy(shape,"lle",3);
            }

            else if(type=="L3"){
                range=2;
                if(check_pt==1) strncpy(shape,"rdd",3);
                else if(check_pt==2||check_pt>=20){
                    strncpy(shape,"uul",3);
                    relative_pos=2;
                }
            }
            else if(type=="J3"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"uur",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"ldd",3);
            }
            else if(type=="Z1"){
                range=3;
                if(check_pt==1) strncpy(shape,"rdr",3);
                else if(check_pt==2||check_pt>=20){
                  strncpy(shape,"rql",3);
                  relative_pos=2;
                }
                else if(check_pt==3) strncpy(shape,"lul",3);
            }
            else if(type=="O"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"rqr",3);
                    relative_pos=1;
                }
                else if(check_pt==2)strncpy(shape,"lur",3);
            }
            else if(type=="T4"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"urq",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"zuu",3);
            }
            else if(type=="L4"){
                range=3;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"rru",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"lfu",3);
                else if(check_pt==3) strncpy(shape,"uzl",3);
            }
            else if(type=="J4"){
                range=3;
                if(check_pt==1) strncpy(shape,"rrd",3);
                else if(check_pt==2) strncpy(shape,"lfd",3);
                else if(check_pt==3||check_pt>=20){
                   strncpy(shape,"ull",3);
                   relative_pos=3;
                }
            }        //    ffffffffffffffffff
            else if(type=="Z2"){
                range=2;
                if(check_pt==1||check_pt>=20){
                    strncpy(shape,"uru",3);
                    relative_pos=1;
                }
                else if(check_pt==2) strncpy(shape,"uzd",3);
            }
           /* for(int i=0;i<4;i++){
                cout<<shape[i];
            }
            cout<<endl;*/
        }
    private:
        char* shape;
        string type;
        int relative_pos;
        int range;
        int height;
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
        void show();
        space(int a,int b){
            rows=a;
            cols=b;
            window = new int* [rows];
            for(int i=0;i<rows;i++){
                window[i]=new int [cols];
                memset(window[i],0,cols*sizeof(int));
            }
            highest=new int [cols];
            memset(highest,0,cols*sizeof(int));
        }
       // ~space();
        void push(cmd*,int);
        int gethigh(int,int);

    private:
        int rows;
        int cols;
        int **window;
        int *highest;       //準備放東西的那個  下面0


};
void space::push(cmd* command,int cmd_length ){
    int i=1,j=1;
    int col_pos,row_pos;
    blocks block[cmd_length];
    //cout<<gethigh(command[0].col_pos);
    for(i=0;i<cmd_length;i++){

        row_pos=0;
        col_pos=0;
        block[i].get_range(command[i].cmds);
        block[i].set_shape(command[i].cmds,gethigh(command[i].col_pos-1,block[i].range)-command[i].col_pos+2);
        //cout<< gethigh(command[i].col_pos,block[i].range)-command[i].col_pos+1<<"sese"<<endl;

        col_pos=command[i].col_pos+block[i].relative_pos-1-1; //減相對的 和題目從1的

        cout<<"hi"<<highest[col_pos];
        row_pos=rows-highest[col_pos]-1;
        highest[col_pos]=rows-row_pos;

        window[row_pos][col_pos]=1;
        cout<<"row "<<row_pos<<endl;
        cout<<"col "<<col_pos<<endl;
        cout<<block[i].shape<<endl;
        for(int m=0;m<3;m++){
            if(block[i].shape[m]=='u'){
                row_pos--;
            //    highest[col_pos]=rows-row_pos-1;
            }
            else if(block[i].shape[m]=='d'){
                row_pos++;
           //     highest[col_pos]=rows-row_pos-1;
            }
            else if(block[i].shape[m]=='l'){
                col_pos--;
            }
            else if(block[i].shape[m]=='r'){
                col_pos++;
            }
            else if(block[i].shape[m]=='q'){
                col_pos--;
                row_pos--;
            }
            else if(block[i].shape[m]=='e'){
                col_pos++;
                row_pos--;

            }
            else if(block[i].shape[m]=='z'){
                col_pos--;
                row_pos++;
               // highest[col_pos]=rows-row_pos-1;
            }
            else if(block[i].shape[m]=='c'){
                col_pos++;
                row_pos++;
            }
            else if(block[i].shape[m]=='f'){
                col_pos+=2;
            }
            else if(block[i].shape[m]=='g'){
                col_pos-=2;
            }
            //cout<<"colaaa"<<col_pos<<endl;
            cout<<"row_pos"<<row_pos<<endl;
            highest[col_pos]=rows-row_pos;
            if(row_pos<0||row_pos>=rows)
                continue;
            //cout<<"highnow"<<highest[col_pos]<<endl;
            window[row_pos][col_pos]=1;
            

        }

        remove();
        show();
    }


}
void space::show(){
    for(int q=0;q<rows;q++){
        for(int r=0;r<cols;r++){
            cout<<window[q][r];
        }
        cout<<endl;
    }
}
void space::remove(){
    int** newwindow;
    newwindow= new int*[rows];
    for(int k=0;k<rows;k++){
        newwindow[k]=new int[cols];
        memset(newwindow[k],0,cols*sizeof(int));
    }
    int new_pos=rows-1;
    for(int i=rows-1;i>=0;i--){
        int isfull=1;

        for(int j=0;j<cols;j++){
            if(window[i][j]==0)
                isfull=0;
        }
        if(isfull==0){
            memcpy(newwindow[new_pos],window[i],cols*sizeof(window[i][0]));
            new_pos--;
        }
        else{
            memset(highest,0,cols*sizeof(int));
            for(int k=rows-1;k>=0;k--){
                for(int q=0;q<cols;q++){
                    if(newwindow[k][q]==1){
                        highest[q]=rows-k;
                    }
                }
            }

        }
    }
    for(int i=0;i<rows;i++){
        delete[] window[i];
    }
    delete []window;

    window=newwindow;
}
int space::gethigh(int start,int range){        //sth strange
    int i;
             //
    int tmp=highest[start];
    int high=start;
    for(i=start;i<start+range;i++){
      //  cout<<"high"<<highest[i]<<endl;
        if(highest[i]>tmp){
            tmp=highest[i];
            high=i;
        }
        else if(highest[i]==tmp)
            high=i;
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
