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
        blocks(){
            height=0;
            height_check=0;
        }
        void get_range(string & t){
           if(t=="T1"){
                range=3;
                height=1;
                height_check=2;
            }
            else if(t=="L1"){
                range=2;
            }
            else if(t=="J1"){
                range=2;
            }
            else if(t=="S1"){
                range=3;
                height=-1;
                height_check=3;
            }
            else if(t=="I1"){
                range=1;
            }
            else if(t=="T2"){
                range=2;
                height=1;
                height_check=2;
            }
            else if(t=="L2"){
                range=3;
                height=1;
                height_check=1;
            }
            else if(t=="J2"){
                range=3;
            }
            else if(t=="S2"){
                range=2;
                height=1;
                height_check=2;
            }
            else if(t=="I2"){
                range=4;
            }
            else if(t=="T3"){
                range=3;
            }
            else if(t=="L3"){
                range=2;
                height=2;
                height_check=2;
            }
            else if(t=="J3"){
                range=2;
                height=2;
                height_check=1;
            }
            else if(t=="Z1"){
                range=3;
                height=-1;
                height_check=1;
            }
            else if(t=="O"){
                range=2;
            }
            else if(t=="T4"){
                range=2;
                height=1;
                height_check=1;
            }
            else if(t=="L4"){
                range=3;
            }
            else if(t=="J4"){
                range=3;
                height=1;
                height_check=3;
            }
            else if(t=="Z2"){
                range=2;
                height=1;
                height_check=1;
            }
        }
        void set_shape(string &t,int check_pt){
            shape=new char[3];
            relative_pos=check_pt;          //l左 r右 u上 d下         //z左下  c右下 q左上  e右上  //f 往右跳兩格 g往左跳兩格 //h往上跳兩格

            type=t;
            if(type=="T1"){
                range=3;
                if(check_pt==1) strncpy(shape,"cur",3);
                else if(check_pt==2) strncpy(shape,"qrr",3);
                else if(check_pt==3) strncpy(shape,"zul",3);
            }
            else if(type=="L1"){
                range=2;
                if(check_pt==1) strncpy(shape,"rqu",3);
                else if(check_pt==2) strncpy(shape,"luu",3);
            }
            else if(type=="J1"){
                range=2;
                if(check_pt==1) strncpy(shape,"ruu",3);
                else if(check_pt==2)strncpy(shape,"leu",3);
            }
            else if(type=="S1"){
                range=3;
                if(check_pt==1) strncpy(shape,"rur",3);
                else if(check_pt==2) strncpy(shape,"ler",3);
                else if(check_pt==3) strncpy(shape,"zle",3);
            }
            else if(type=="I1"){
                range=1;
                strncpy(shape,"uuu",3);
            }
            else if(type=="T2"){
                range=2;
                if(check_pt==1) strncpy(shape,"cuu",3);
                else if(check_pt==2) strncpy(shape,"qru",3);
            }
            else if(type=="L2"){
                range=3;
                if(check_pt==1) strncpy(shape,"urr",3);
                else if(check_pt==2) strncpy(shape,"zuf",3);
                else if (check_pt==3) strncpy(shape,"lzu",3);
            }
            else if(type=="J2"){
                range=3;
                if(check_pt==1) strncpy(shape,"ucr",3);
                else if(check_pt==2) strncpy(shape,"rgu",3);
                else if(check_pt==3) strncpy(shape,"llu",3);
            }
            else if(type=="S2"){
                range=2;
                if(check_pt==1) strncpy(shape,"cuq",3);
                else if(check_pt==2) strncpy(shape,"ulu",3);
            }
            else if(type=="I2"){
                range=4;
                if(check_pt==1) strncpy(shape,"rrr",3);
                else if(check_pt==2) strncpy(shape,"lfr",3);
                else if(check_pt==3) strncpy(shape,"grf",3);
                else if(check_pt==4) strncpy(shape,"lll",3);
            }
            else if(type=="T3"){
                range=3;
                if(check_pt==1) strncpy(shape,"rrq",3);
                else if(check_pt==2) strncpy(shape,"lec",3);
                else if(check_pt==3) strncpy(shape,"lle",3);
            }
            else if(type=="L3"){
                range=2;
                if(check_pt==1) strncpy(shape,"cdh",3);
                else if(check_pt==2) strncpy(shape,"uul",3);
            }
            else if(type=="J3"){
                range=2;
                if(check_pt==1) strncpy(shape,"uur",3);
                else if(check_pt==2) strncpy(shape,"zdh",3);
            }
            else if(type=="Z1"){
                range=3;
                if(check_pt==1) strncpy(shape,"crq",3);
                else if(check_pt==2) strncpy(shape,"rql",3);
                else if(check_pt==3) strncpy(shape,"lul",3);
            }
            else if(type=="O"){
                range=2;
                if(check_pt==1) strncpy(shape,"rqr",3);
                else if(check_pt==2)strncpy(shape,"lur",3);
            }
            else if(type=="T4"){
                range=2;
                if(check_pt==1) strncpy(shape,"urq",3);
                else if(check_pt==2) strncpy(shape,"zuu",3);
            }
            else if(type=="L4"){
                range=3;
                if(check_pt==1) strncpy(shape,"rru",3);
                else if(check_pt==2) strncpy(shape,"lfu",3);
                else if(check_pt==3) strncpy(shape,"uzl",3);
            }
            else if(type=="J4"){
                range=3;
                if(check_pt==1) strncpy(shape,"rcu",3);
                else if(check_pt==2) strncpy(shape,"cug",3);
                else if(check_pt==3) strncpy(shape,"ull",3);
            }
            else if(type=="Z2"){
                range=2;
                if(check_pt==1) strncpy(shape,"uru",3);
                else if(check_pt==2) strncpy(shape,"zue",3);
            }

        }
    private:
        char* shape;
        string type;
        int relative_pos;
        int range;
        int height;
        int height_check;
};
int read_file(cmd* command){
    int flag=0,i=0;
    ifstream fin("tetris.data");
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
            readyin=new int*[5];
            for(int m=0;m<5;m++){
                readyin[m]=new int [cols];
                memset(readyin[m],0,cols*sizeof(int));
            }
        }

        void push(cmd*,int);
        int gethigh(int,int,int,int);
        void out_file();
        int check_full();
        int check_rowfull(int);

    private:
        int rows;
        int cols;
        int **window;
        int *highest;       //準備放東西的那個  下面0
        int **readyin;
        int gameover;

};
void space::push(cmd* command,int cmd_length ){
    int i=1,j=1;
    int col_pos,row_pos;
    blocks block[cmd_length];
    gameover=0;
    for(i=0;i<cmd_length;i++){

        row_pos=0;
        col_pos=0;
        block[i].get_range(command[i].cmds);
        block[i].set_shape(command[i].cmds,gethigh(command[i].col_pos-1,block[i].range,block[i].height,block[i].height_check)-command[i].col_pos+2);


        col_pos=command[i].col_pos+block[i].relative_pos-1-1; //減相對的 和題目從1的
        row_pos=rows-highest[col_pos]-1;
        highest[col_pos]=rows-row_pos;
        if(row_pos<0||row_pos>=rows){
            readyin[-row_pos][col_pos]=1;
        }
        else
            window[row_pos][col_pos]=1;
        /*cout<<"row "<<row_pos<<endl;
        cout<<"col "<<col_pos<<endl;
        for(int m=0;m<3;m++)
        cout<<block[i].shape[m]<<endl;
        cout<<command[i].cmds<<endl;*/
        for(int m=0;m<3;m++){
            if(block[i].shape[m]=='u'){
                row_pos--;
            }
            else if(block[i].shape[m]=='d'){
                row_pos++;
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
            else if(block[i].shape[m]=='h'){
                row_pos-=2;
            }
            highest[col_pos]=rows-row_pos;
            if(row_pos<0||row_pos>=rows)
                readyin[-row_pos][col_pos]=1;
            else
                window[row_pos][col_pos]=1;


        }

        remove();



        if(check_full()){
            gameover=1;
        }
        //show();
        //cout<<endl;
        if(gameover)
            break;
    }
    out_file();

}
int space::check_full(){
    for(int i=1;i<5;i++){
        for(int j=0;j<cols;j++)
            if(readyin[i][j]==1)
                return 1;
    }
    return 0;
}
void space::out_file(){
    ofstream fout;
    fout.open("Tetris.final",ios::out);
    if(!fout){
        cout<<"nofile"<<endl;
    }
    for(int q=0;q<rows;q++){
        for(int r=0;r<cols;r++){
            fout<<window[q][r];
        }
        fout<<endl;
    }
    fout.close();
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
    int times=0;
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
        else if(isfull==1){
            times++;
        }
    }

    if(check_full()==1 && times>0){
        for(int j=1;j<=4;j++){
            if(check_rowfull(j)){
                memset(readyin[j],0,cols*sizeof(int));
                continue;
            }
            else if(check_rowfull(j)==0 && new_pos>=0){
                    //cout<<"j"<<j<<endl;
                memcpy(newwindow[new_pos],readyin[j],cols*sizeof(readyin[j][0]));
                memset(readyin[j],0,cols*sizeof(int));
                new_pos--;
            }

        }
    }
    memset(highest,0,cols*sizeof(int));
            int flag[cols];
            for(int k=rows-1;k>=0;k--){
                for(int q=0;q<cols;q++){
                    if(newwindow[k][q]==1){
                        highest[q]=rows-k;
                    }
                }
            }
    if(check_full()==1){
        gameover=1;
    }
    for(int i=0;i<rows;i++){
        delete[] window[i];
    }
    delete []window;
    for(int i=0;i<5;i++){
        memset(readyin[i],0,cols*sizeof(int));
    }
    window=newwindow;
}
int space::check_rowfull(int rownow){
    int isfull=1;
    for(int i=0;i<cols;i++){
       if(readyin[rownow][i]==0){
        return 0;
       }
    }
    return 1;
}
int space::gethigh(int start,int range,int height,int height_check){
    int i;
    int tmp;
    if(height_check==1)
        tmp=highest[start]+height;
    else
        tmp=highest[start];
    int high=start;
    for(i=start;i<start+range;i++){
        if(height_check!=0){
            if(i==start+height_check-1){
                if(highest[i]+height > tmp){
                    tmp=highest[i]+height;
                    high=i;
                }
            }
            else{
                if(highest[i]>tmp){
                    tmp=highest[i];
                    high=i;
                }
                else if(highest[i]==tmp){
                    high=i;
                }
            }
        }
        else{
            if(highest[i]>tmp){
                tmp=highest[i];
                high=i;
            }
            else if(highest[i]==tmp){
                high=i;
            }
        }


    }
    return high;
}
int main(){
    cmd command[1005];
    int cmd_length=read_file(command);
    space sp(command[0].rows,command[0].cols);
    sp.push(command,cmd_length);


return 0;
}
