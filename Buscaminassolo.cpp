#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

typedef struct 
{
    string mina = "*";
    string vacio = " ";
    string numina;

}tIcono;
typedef struct 
{
    string inc = "?";
    string bandera = "/";
}tIcono2;
void llenarmatriz(string matriz[][100],int num,int num2);
int numaleatorio(int num);
void imprimirmapa(string mapa[][100], int num,int &columnacu,int &filacu);
void llenarmatriznumeros(string matriz[][100],int num);
int contarnumeros(string matriz[][100],int i,int e,int num);
void movimiento(int &filacu,int &columnacu,int num,string mapa[][100],string mapa2[][100], int &win,int &ctdminas);
void rellenarmapaqseve(string mapa[][100], int num);
void expansionre(int fila,int columna,string mapa[][100],string mapa2[][100],int num);
void reiniciarmatrices(string matriz[][100],string matriz2[][100]);
int contadorminas(string matriz[][100],int num);
void banderas(int &ctd);
void verificadorwin(string matriz[][100],string matriz2[][100],int num,int ctdminas, int &win);
void controles();

int main(){
    srand(time(0));
    int num,win=0,seguir=0;
    int filacu = 0,columnacu = 0,ctdminas = 0,ctdwin = 0,dificultad = 1,aux=0;
    string mapa[100][100];
    string mapaqseve[100][100];

    while (seguir == 0)
    {
        cout << "===================================" << endl;
        cout << "           BUSCAMINAS!!!" << endl;
        cout << "===================================" << endl;
        cout << "\n";
            reiniciarmatrices(mapa,mapaqseve);
        filacu = 0;
        columnacu = 0;
        win=0;
        ctdminas=0;
        ctdwin = 0;
        dificultad=1;
        cout<<"Eliga la Medida de la matriz :)"<<endl;
        cin>>num;
        do{
        cout<<"Ingrese Dificultad (1%-75%)"<<endl;
        cin>>dificultad;
        if( dificultad<=0 or dificultad>75){
            aux=0;    
        }else{
            aux=1;
        }
        }while(aux==0);
        llenarmatriz(mapa,num,dificultad);
        llenarmatriznumeros(mapa,num);
        ctdminas=contadorminas(mapa,num);
        ctdwin=contadorminas(mapa,num);
        rellenarmapaqseve(mapaqseve,num);
        while(win == 0){
            system("cls");
            banderas(ctdminas);
            verificadorwin(mapa,mapaqseve,num,ctdwin,win);
            imprimirmapa(mapaqseve,num,filacu,columnacu);
            movimiento(filacu,columnacu,num,mapa,mapaqseve,win,ctdminas);
            
        }
        if(win == 1){
            cout<<"!BOOOOOOOOM PERDISTE"<<endl;
            cout<<"Desea seguir jugando? ( 0 = Si )"<<endl;
            cin>>seguir;
        }else if(win != 1 and win !=0){
            cout<<"!Ganasteeeee"<<endl;
            cout<<"Desea seguir jugando? ( 0 = Si )"<<endl;
            cin>>seguir;
        }
        system("cls");
    }
    



}

void llenarmatriz(string matriz[][100],int num,int num2){
    int x,z,y,ctd=0;
    tIcono mapa1;
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            z = numaleatorio(100);
            if( z <= num2){
                matriz[i][e]= mapa1.mina;
            }else {
                matriz[i][e]= mapa1.vacio;
            }
        }
    }
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            z = numaleatorio(100);
            if( matriz[i][e]== mapa1.mina){
                ctd++;
            }
        }
    }
    if (ctd==0){
        x = numaleatorio(num);
        y = numaleatorio(num);
        matriz[x][y]= mapa1.mina;
    }
    
}
void llenarmatriznumeros(string matriz[][100],int num){
    int x;
    string z,y;
    tIcono mapa1;
    matriz[num][num];
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            x = contarnumeros(matriz,i,e,num);
            z = to_string(x);
            mapa1.numina = z;
            if(x==0){
                continue;
            }else{
                matriz[i][e] = mapa1.numina;
            }
        }
    }
    
}
int contarnumeros(string matriz[][100],int i,int e,int num){
    tIcono mapa1;
    int ctd=0;
    if( matriz[i][e] == mapa1.mina){
        return 0;
    }else{
        for (int l =-1; l <= 1; l++)
        {
            for (int n =-1; n <= 1; n++)
            {
                if((i+l<0 or i+l>num-1) or ( e+n<0 or e+n>num-1)){
                    continue;
                }else{
                    if(matriz[i+l][e+n]==mapa1.mina){
                        ctd++;
                    }else{
                        continue;

                    }    
                }
            }
        }
        return ctd;
    }  
    
}
void rellenarmapaqseve(string mapa[][100], int num){
    tIcono2 mapa2;
    mapa[num][num];
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            mapa[i][e]=mapa2.inc;
        }

    }   

}
int numaleatorio(int num){
    
    return rand()%num;
}
void imprimirmapa(string mapa[][100], int num,int &filacu,int &columnacu){
    mapa[num][num];
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            if(i == filacu && e == columnacu)
            {
                cout << "|X| ";  
            }else{
                cout<<"|"<<mapa[i][e]<<"|"<<" ";
            }
        }
        cout<<"\n";
    }
    controles();   

}
void movimiento(int &filacu, int &columnacu, int num,string mapa[][100], string mapa2[][100],int &win,int &ctdminas)
{
    tIcono mapa1;
    tIcono2 mapave;
    char tecla = _getch();

    if(tecla == 'a' or tecla == 'A' && columnacu > 0)
    {
        columnacu--;
    }
    else if(tecla == 'd' or tecla == 'D' && columnacu < num - 1)
    {
        columnacu++;
    }
    else if(tecla == 'w' or tecla == 'W' && filacu > 0)
    {
        filacu--;
    }
    else if(tecla == 's' or tecla == 'S' && filacu < num - 1)
    {
        filacu++;
    }
    else if(tecla == 'q' or tecla == 'Q')
    {
        if(mapa[filacu][columnacu] == mapa1.vacio){
            expansionre(filacu,columnacu,mapa,mapa2,num);

        }else if (mapa[filacu][columnacu] == mapa1.mina) {        
            mapa2[filacu][columnacu] = mapa[filacu][columnacu];
            win=1;
        }else{
            mapa2[filacu][columnacu] = mapa[filacu][columnacu];
        }

    }
    else if(tecla == 'e' or tecla == 'E')
    {
        if(mapa2[filacu][columnacu] == mapave.inc){
            mapa2[filacu][columnacu] = mapave.bandera;
            ctdminas = ctdminas-1;

        }else if(mapa2[filacu][columnacu] == mapave.bandera){
            mapa2[filacu][columnacu] = mapave.inc;
            ctdminas = ctdminas+1;
        }
        
    }
}
void expansionre(int fila,int columna,string mapa[][100],string mapa2[][100],int num){
    tIcono mapa1; 
    tIcono2 mapave;
    for (int h = -1; h <=1 ; h++)
    {
        for (int l = -1; l <=1 ; l++)
        {
            if (columna+l<0 or fila+h<0 or columna+l>num-1 or fila+h>num-1)
            {
                continue;
            }else{
                if(mapa2[fila+h][columna+l] == mapave.inc){
                    if(mapa[fila+h][columna+l]== mapa1.vacio){
                        mapa2[fila+h][columna+l] = mapa[fila+h][columna+l];
                        expansionre(fila+h,columna+l,mapa,mapa2,num);
                    }else{
                        continue;
                    }
                }else{                    
                    continue;
                }                    
                
            }
            
        }
    }
    
}
void reiniciarmatrices(string matriz[][100],string matriz2[][100]){
    tIcono mapa1;
    for (int i = 0; i < 100; i++)
    {
        for (int e = 0; e < 100; e++)
        {
            matriz[i][e]=mapa1.vacio;
            matriz2[i][e]=mapa1.vacio;
        }
    }
    
}
int contadorminas(string matriz[][100],int num){
    tIcono mapa1;
    int ctd=0;
    for (int i = 0; i < num; i++)
    {
        for (int e = 0; e <num; e++)
        {
            if(matriz[i][e]==mapa1.mina){
                ctd++;
            }
        }
    }
    return ctd;
}
void banderas(int &ctd){
    tIcono2 mapa1;
    string tbanderas="";
    for (int i = 0; i < ctd; i++)
    {
        tbanderas += mapa1.bandera;
    }
    cout<<"Banderas: "<<tbanderas<<endl;

}

void verificadorwin(string matriz[][100],string matriz2[][100],int num,int ctdminas, int &win){
    tIcono mapa1;
    tIcono2 mapa2;
    int ctd =0;
    for (int i = 0; i < num; i++)
    {
        for (int e = 0; e < num; e++)
        {
            if(matriz[i][e]==mapa1.mina and matriz2[i][e]==mapa2.bandera){
                ctd++;
            }
        }
    }
    if(ctd == ctdminas){
        win =2 ;
    }   
}
void controles(){
    cout << "===================================" << endl;
    cout << "              MOVIMIENTO            " << endl;
    cout << "                  W                  " << endl;
    cout << "                A S D                " << endl;
    cout << "Q:Revelar Casilla     E:Poner Bandera" << endl;
    cout << "===================================" << endl;
}
