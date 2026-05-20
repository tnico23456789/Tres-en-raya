# **BUSCAMINAS EN RAYA (TRES EN RAYA + BUSCAMINAS)** 👌
## **_Integrantes_**
#### Paul Moreno
#### Zaid Jaramillo
#### Julián Gamarra
#### Nicolás Torres
## **_Descripción del proyecto_** 
#### El juego es una fusión de dos clásicos: El buscaminas y el tres en raya, acoplados a un sistema aleatorio de cartas que dicta ciertas ventajas o desventajas al usuario en su siguiente turno, entre las cuales estan: **Perdida de turno** **Roba un espacio** **Turno extra** etc... Al elegir la carta de **MINA** el jugador acreedor puede colocar una mina en cualquiera de las posiciones libres del tablero, si el jugador siguiente coloca su ficha en la misma posición, EXPLOTAAAA!!!!! y automáticamente pierde el juego.
## Victoria
#### Además de la carta MINA, un jugador gana si completa una linea de 3 (ya sea vertical, horizontal o diagonal) de su fichacorrespondiente X o O
## Empate
#### Cuando el tablero se completo y ninguno de los 2 jugadores completo una fila, una columna o una diagonal con 3 de su respectiva ficha. Existe la opción de jugar una nueva ronda indefinidamente hasta que cualquiera de los dos gane, incluso si un de los dos gana pueden seguir juganndo y esa partida se va registrando en un contador de cuantas rondas ganadas va cada jugador.
## Derrota
#### Cuando un jugador explota l amina ubicada por su oponente o su oponente completa una fila, columna o diagonal con 3 de sus fichas
## CÓDIGO EJECUTABLE (con comentarios explicativos)
### Color
#### Es una parte complementaria visual del código que no interfiere como tal en la jugabilidad o fluidez del código pero aporta estética visual al juego.
<details>
<summary>📌 Mostrar código de color fuente</summary>

  ```cpp
#include <iostream>
using namespace std;

int main() {

    for(int i = 0; i < 256; i++) {

        cout << "\033[38;5;" << i << "m";

        cout << "Color " << i << "\n";
    }

    
    cout << "\033[0m";
    system("pause"); 
    return 0;
}
```

</details>

### Código final
<details>
<summary>📌 Mostrar código  fuente</summary>
  
  ```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
// <ctime> para que la semilla srand sea distinta dependiendo del tiempo
// <cstdlib> librería para limpiar pantalla
using namespace std;

void jugar();
void reglas();
void creditos();
//funciones fuera del main para editar el código por partes, en el caso de ser nesesario solo tocar una función y no todo el código
int main() {

    int opcion;

    do {
    system("cls");

    cout<<"==================================="<<endl;
    cout<<"   TRES EN RAYA... CON CARTAS!!!"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";

    cout << "1. Jugar\n";
    cout << "2. Reglas\n";
    cout << "3. Creditos\n";
    cout << "4. Salir\n\n";

    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion) {

        case 1:
            jugar();
            break;

        case 2:
            reglas();
            break;

        case 3:
            creditos();
            break;

        case 4:
            cout << "\nCerrando juego...\n";
            cout << "\nCHAOO\n";
            break;

        default:
            cout << "\nOpcion invalida\n";
            system("pause");
    }

    } while(opcion != 4);

return 0;
}


//juegar

void jugar() {
    //limpia la pantalla el symtem("cls") 
    system("cls");



    /*Definir las variables a ocupar dentro de nuestro código */
    int anticheat,vj=1,aux3=0,aux2=1,ext=0,prof1=4,proc1=4,prof2=4,proc2=4,fila1,columna1,fila2,columna2,ini=0,ctd=0,ctd2=0,ctd3=0,filamina=0;
    char tabla[3][3];
    char bloqueo[3][3];
    int minas[3][3];
    char j1='x',j2='o',aux;




    int ganar=0;
    cout<<"==================================="<<endl;
    cout<<"   TRES EN RAYA... CON CARTAS!!!"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";
    
    /*Se inicializan las tablas con el valor de tres*/
    tabla[3][3];
    minas[3][3];
    bloqueo[3][3];


    /*Relleno de las matrices con elementos */
    /*Matriz de Tablero*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabla[i][j]={'-'};
        }
    }
    /*Matriz de Cartas*/
    
    /*Matriz para la funcion de Bloqueo*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bloqueo[i][j]={'-'} ;
        }
    }


    do{/*Bucle Principal de Juego para ambos jugadores*/
        //jugador1 mecanica tres en raya normal 
        do{/*Bucle de Turno para el Jugador 1*/
        cout <<"\n"; 
        cout<<"----------------JUGADOR |x|----------------"<<endl;
        for (int i = 0; i < 3; i++)
            {
            if (i == 0){
                cout<< "  c1  c2  c3 " << endl; 
            }
            cout<< "f" << i + 1<< " "; 
            for (int j = 0; j < 3; j++)
            {
                
                cout<<tabla[i][j];
                if (j < 2){
                    cout<< " | ";
                }
            }
            cout <<"\n";
            if (i < 2){
                cout<< "  ---|---|---" << endl;
            }    
        }
        cout <<"\n";
        do{
        /*Espacio de asignacion para que el jugador 1 ingrese tanto fila como columna con un bucle qeu solo admite los valores correctos osea 
        del 1 al 3*/    
        cout<<"Elije una fila [1-3]"<<endl;
        cin >> fila1;
        if(fila1 >=1 and fila1<=3){
            ini = 0;
        }else{
            ini = 1;
        }
        cout<<"Elije una columna [1-3]"<<endl;
        cin >> columna1;
        if(columna1 >=1 and columna1<=3){
            ini = 0;
        }else{
            ini = 1;
        }
            /*Linea importante para restarle 1 a la opcion ingresada por el jugador debido a que la maquina se maneja desde el numero 0*/
            fila1 --;
            columna1 --;
        if(tabla[fila1][columna1] != '-'){
            cout<<"CASILLA NO VALIDA :("<<endl;
            ini = 1;
        }    
        }while( ini != 0 );

        //Bloque de  posicionamiento de Ficha
        /*Este bucle lee y verifica si la casilla ingresada esta bloqueada o no para pdoer colocar la respectiva X*/
        if( bloqueo[fila1][columna1] != '*'){
            /*Esta condicion agrega un + a la matriz de la carta bloqueo para un uso posterior de esta*/
            cout <<"\n"; 
            cout<<"La |x| fue colocada"<<endl;    
            tabla[fila1][columna1]={j1};
            bloqueo[fila1][columna1]={'+'};
            cout <<"\n"; 
        }else{
            cout <<"\n"; 
            cout<<"CASILLA BLOQUEADA :("<<endl;    
            tabla[fila1][columna1]={'-'};
            bloqueo[fila1][columna1]={'-'};
            cout <<"\n";  
        }


        /*Este bucle imprime el tablero actual de juego*/
        for (int i = 0; i < 3; i++)
            {
            if (i == 0){
                cout<< "  c1  c2  c3 " << endl; 
            }
            cout<< "f" << i + 1<< " "; 
            for (int j = 0; j < 3; j++)
            {
                
                cout<<tabla[i][j];
                if (j < 2){
                    cout<< " | ";
                }
            }
            cout <<"\n";
            if (i < 2){
                cout<< "  ---|---|---" << endl;
            }    
        }
        cout <<"\n";

        //Ganar filas
        /*Este bucle verifica si hay tres X o O en una fila para activar la win por parte del jugador correspondiente para ello recorre cada fila
        con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la fila*/

        for (int i = 0; i < 3; i++){
            ctd = 0;
            ctd2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if(aux == 'x'){
                    ctd +=1;
                    ctd2 =0;
                }else if(aux == 'o'){
                    ctd2 +=1;
                    ctd =0;
                }
            }
                if(ctd == 3){
                    cout<<"JUGADOR |x| GANA!!"<<endl;
                    ganar=1;
                    break;
                }else if( ctd2 == 3){
                    cout<<"JUGADOR |o| GANA!!"<<endl;
                    ganar=1;
                    break;
                }else{
                    ctd = 0;
                    ctd2 = 0;
                }  
        }
        //Ganar Columnas
        /*Este bucle verifica si hay tres X o O en una columna para activar la win por parte del jugador correspondiente para ello recorre cada columna
        de manera similar al de las filas pero con los elementos invertidos y con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la columna*/
        for (int i = 0; i < 3; i++){
            ctd = 0;
            ctd2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[j][i];
                if(aux == 'x'){
                    ctd +=1;
                    ctd2 =0 ;
                }else if (aux == 'o'){
                    ctd2 +=1;
                    ctd = 0;
                }               
            }
            if(ctd == 3){
                cout<<"JUGADOR |x| GANA!!"<<endl;
                ganar=1;
                break;
            }else if( ctd2 == 3){
                cout<<"JUGADOR |o| GANA!!"<<endl;
                ganar=1;
                break;
            }else{
                ctd = 0;
                ctd2 = 0;
            } 
        }
        //Ganar Diagonal
        /*Este bucle verifica si hay tres X o O en la diagonal principal para activar la win por parte del jugador correspondiente para ello recorre un bucle
        verificando las entradas con nuemero similar si poseen una X o un O  para activar la win por el jugador correspondiente*/

        ctd = 0;
        ctd2 = 0;

        /*Diagonal principal*/
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][i] == 'x'){
                ctd++;
            }

            if(tabla[i][i] == 'o'){
                ctd2++;
            }
        }

        if(ctd == 3){
            cout<<"JUGADOR |x| GANA!!"<<endl;
            ganar=1;
        }else if(ctd2 == 3){
            cout<<"JUGADOR |o| GANA!!"<<endl;
            ganar=1;
        }

        /*Reinicio de contadores*/
        ctd = 0;
        ctd2 = 0;

        /*Diagonal secundaria*/
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][3 - 1 - i] == 'x'){
                ctd++;
            }

            if(tabla[i][3 - 1 - i] == 'o'){
                ctd2++;
            }
        }

        if(ctd == 3){
            cout<<"JUGADOR |x| GANA!!"<<endl;
            ganar=1;
        }else if(ctd2 == 3){
            cout<<"JUGADOR |o| GANA!!"<<endl;
            ganar=1;
        }

        //EMPATE
        /*Aqui verifica el empate lo hace mediante un bucle que recorre cada fila con un contador que suma 1 siempre que vea un "-" ya que eso indica 
        que la casilla esta vacía o esta llena en caso el contador no sume aunque sea 1 esta dira que es un empate*/
        ctd = 0;
        ctd2 = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if (aux == '-'){
                    ctd3 +=1;
                }
            }    
        }
        if ( ctd3 == 0){
            cout<<"EMPATE!!"<<endl;
            ganar = 1;
        }else{
            ctd3=0;
        }  

        if( ganar == 1){
            break;
        }

        if(ext != 1){
            ext=1;
        }

        //  MECANICA EXTRA CARTAS 
        /*Aqui comienza con la lógica de programacion de la implmentación en este caso despues de poner su X o O  tiene la opcion de elegir entre 9 
        cartas que pueden tener 5 efectos posibles*/ 
        aux2=1;
        aux3=0;
        do{
            cout<<"-----------------------------"<<endl;
            cout<<"<<<<<<<<<<<CARTA!!>>>>>>>>>>>"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Elige tu carta [1 - 9]: ";cin>>filamina;cout<<"\n"; 
            if(filamina >=1 and filamina<=9){
                ini = 0;
            }else{
                ini = 1;
            }
            filamina--;
        }while( ini != 0 );
        /*Esta linea transforma el numero ingresado por el usuario para traducirlo a una posicion en la matriz de cartas primero divide para 3
        para sacar las filas y el residuo o el MOD indica la columna de la matriz*/
        int filaCarta = filamina / 3;
        int columnaCarta = filamina % 3;
        /* Aqui se esta ocupando la funcion srand para la generacion de nuemros aleatorios usando una semilla de tiempo 0*/
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   srand(time(0));
                int naleatorio = rand() % 5 + 1 ;
                minas[i][j]={naleatorio} ;
            }
        }

        aux3 = minas[filaCarta][columnaCarta];

        /*Aqui empiezan los 5 efectos posibles*/
        if(aux3 == 1){
            //EXPLOSION!
            /*Aqui comienza el primer efecto explosion hace que el jugador pierda la ultima ficha que puso utiliza un condicional que lee la utlima casilla basada
            en la ultima entrada del jugador*/

            if (anticheat==1)
            {
            /*Esta condicion verifica si el jugador esta intentando sacar doble turno muchas veces por lo cual lo penaliza*/
                cout<<"TRAMPOSO!! no puedes tener turnos infinitos :("<<endl;
            }
            
            cout<<"BOOOM!!!!"<<endl;
            cout<<"TE TOCO EXPLOSION!!" <<endl;
            cout<<"La ultima |x| sera destruida"<<endl;
            if ((fila1 == prof2) and (columna1 == proc2)){
                cout<<"ESCUDO ACTIVADO!!"<<endl;
                cout<<"Tu casilla estaba protegida por el ESCUDO!!"<<endl;
                prof1=4;proc1=4;          
            }else{
            tabla[fila1][columna1] = {'-'};
            }
            cout <<"\n"; 

        }else if(aux3== 2){
            //ROBO!
            /*Con esta carta puedes robar la posicion del enemigo en este caso el O del enemigo para el jugador 2 sera alrevez pero con la misma lógica*/
            int ctd4 = 0;
            /*Este bucle for anidado verifica que exista un O que robar en caso no lo haya pierde su carta*/
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++)
                {
                    aux = tabla[i][j];
                    if (aux == 'o'){
                        ctd4 +=1;
                    }
                }    
            }
            cout<<"ROBO!!!"<<endl;
            if (ctd4>=1)
            {
                /*Aqui muestra el tablero actual mediante un bucle for como al principio*/
                
                cout<<"Puedes robar una ficha de tu oponente"<<endl;
                for (int i = 0; i < 3; i++)
                    {
                    if (i == 0){
                        cout<< "  c1  c2  c3 " << endl; 
                    }
                    cout<< "f" << i + 1<< " "; 
                    for (int j = 0; j < 3; j++)
                    {
                        
                        cout<<tabla[i][j];
                        if (j < 2){
                            cout<< " | ";
                        }
                    }
                    cout <<"\n";
                    if (i < 2){
                        cout<< "  ---|---|---" << endl;
                    }    
                }
                /*Aqui pregunta donde desea su respectiva*/
                cout <<"\n";
                cout<<"Elije una casilla para robar la |x|"<<endl;
                do{
                cout<<"Elije una fila [1-3]"<<endl;
                cin >> fila1;
                if(fila1 >=1 and fila1<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                cout<<"Elije una columna [1-3]"<<endl;
                cin >> columna1;
                if(columna1 >=1 and columna1<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                    fila1 --;
                    columna1 --;
                if(tabla[fila1][columna1] == '-' or tabla[fila1][columna1] == 'x' ){
                    cout<<"CASILLA NO VALIDA :("<<endl;
                    ini = 1;
                }else{
                    cout<<"CASILLA VALIDA :)"<<endl;
                    ini = 0;
                }    
                }while( ini != 0 );
                /*Esta linea verifica si una casilla esta protegida otra de las cartas qeu se explicara despues*/
                if (((fila1 == prof2) and (proc2 == columna1))){
                    cout<<"ESCUDO ACTIVADO!!"<<endl;
                    cout<<"La casilla del oponente estaba protegida por el ESCUDO!!"<<endl;
                    prof2=4;proc2=4;
                }else{
                tabla[fila1][columna1] = {'x'};
                }
            }else{
                cout<<"MALA SUERTE!!!!"<<endl;
                cout<<"Aun no hay ningun |o| que robar"<<endl;
                cout<<"PIERDES LA CARTA :("<<endl;
            }
            cout <<"\n"; 
            

        }else if(aux3 == 3){
            //ESCUDO
            /*Esta carta escudo permite al jugador defender su ultima X puesta o O dependiendo del jugador que este en su turno*/
            cout<<"ESCUDO!!!!"<<endl;
            cout<<"Tu ultima |x| sera PROTEGIDA"<<endl;
            prof1 = fila1;
            proc1 = columna1;

        }else if(aux3 == 4){
            //BLOQUEO
            /*Esta carta permite poner un bloqueo en una casilla para que el otro jugador no pueda poner su X o O respectivamente*/
            cout<<"BLOQUEO!!!!"<<endl;
                cout <<"\n";
                cout<<"Elije una casilla para bloquear a tu oponente"<<endl;
                do{
                cout<<"Elije una fila [1-3]"<<endl;
                cin >> fila1;
                if(fila1 >=1 and fila1<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                cout<<"Elije una columna [1-3]"<<endl;
                cin >> columna1;
                if(columna1 >=1 and columna1<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                    fila1 --;
                    columna1 --;
                /*Esta linea verifica si la casilla ya esta ocupada para no permitir el bloqueo de la misma*/
                if(bloqueo[fila1][columna1] == '+'){
                    cout<<"CASILLA NO VALIDA :("<<endl;
                    ini = 1;
                }else{
                    cout<<"CASILLA VALIDA :)"<<endl;
                    ini = 0;
                }
                }while( ini != 0 );    
            bloqueo[fila1][columna1] = {'*'};
            cout <<"\n"; 

        }else if(aux3 == 5){
            //DOBLE TURNO
            /*El nombre lo dice permite repetir el bucle en el qeu esta el jugador 1 para tener un doble turno*/
            cout<<"DOBLE TURNO!!!!"<<endl;
            cout<<"Tienes un turno extra"<<endl;
            ext=0;
            cout <<"\n";
            minas[filaCarta][columnaCarta] = 1 ;
            anticheat = 1;
        }        
        //
        filamina = 0 ;
        
    }while(ext!=1);/*Complemento del bucle Do-While de arriba el que maneja el bucle del jugador 1*/
    
    anticheat=0;//Esta linea reestablece el anticheat para qeu no salga el mismo mensaje a cada rato y sin necesidad
    if(ganar ==1){
        break;
    }
    /*Antes de empezar el turno del jugador 2 esta condición verifica si existe un jugador que haya ganadao temrinando el juego con el bucle principal*/
        do{
            cout<<"----------------JUGADOR |o|----------------"<<endl;
        for (int i = 0; i < 3; i++)
            {
            if (i == 0){
                cout<< "  c1  c2  c3 " << endl; 
            }
            cout<< "f" << i + 1<< " "; 
            for (int j = 0; j < 3; j++)
            {
                
                cout<<tabla[i][j];
                if (j < 2){
                    cout<< " | ";
                }
            }
            cout <<"\n";
            if (i < 2){
                cout<< "  ---|---|---" << endl;
            }    
        }
        cout <<"\n";
        //jugador2
        /*Usa la logica similar a la del jugador 1*/

        do{

        
        cout<<"Elije una fila [1-3]"<<endl;
        cin >> fila2;
        if(fila2 >=1 and fila2<=3){
            ini = 0;
        }else{
            ini = 1;
        }
        cout<<"Elije una columna [1-3]"<<endl;
        cin >> columna2;
        if(columna2 >=1 and columna2<=3){
            ini = 0;
        }else{
            ini = 1;
        }
            fila2 --;
            columna2 --;
        if(tabla[fila2][columna2] != '-'){
            cout<<"CASILLA NO VALIDA :("<<endl;
            ini = 1;
        }    

        }while( ini != 0 );

        if( bloqueo[fila2][columna2] != '*'){
            cout <<"\n"; 
            cout<<"CASILLA VALIDA :)"<<endl;    
            tabla[fila2][columna2]={j2};
            bloqueo[fila2][columna2]={'+'};
            cout <<"\n"; 
        }else{
            cout <<"\n"; 
            cout<<"Espacio Bloqueado "<<endl;    
            tabla[fila2][columna2]={'-'};
            bloqueo[fila2][columna2]={'-'};
            cout <<"\n";  
        }

        for (int i = 0; i < 3; i++)
            {
            if (i == 0){
                cout<< "  c1  c2  c3 " << endl; 
            }
            cout<< "f" << i + 1<< " "; 
            for (int j = 0; j < 3; j++)
            {
                
                cout<<tabla[i][j];
                if (j < 2){
                    cout<< " | ";
                }
            }
            cout <<"\n";
            if (i < 2){
                cout<< "  ---|---|---" << endl;
            }    
        }
        cout <<"\n";

        //Ganar filas

        for (int i = 0; i < 3; i++){
            ctd = 0;
            ctd2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if(aux == 'x'){
                    ctd +=1;
                    ctd2 =0;
                }else if(aux == 'o'){
                    ctd2 +=1;
                    ctd =0;
                } 
            }
                if(ctd == 3){
                    cout<<"El JUGADOR |x| GANA!!"<<endl;
                    ganar=1;
                    break;
                }else if( ctd2 == 3){
                    cout<<"El JUGADOR |o| GANA!!"<<endl;
                    ganar=1;
                    break;
                }else{
                    ctd = 0;
                    ctd2 = 0;
                } 
        }
        //Ganar Columnas

        for (int i = 0; i < 3; i++){
            ctd = 0;
            ctd2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[j][i];
                if(aux == 'x'){
                    ctd +=1;
                    ctd2 =0 ;
                }else if (aux == 'o'){
                    ctd2 +=1;
                    ctd = 0;
                }               
            }
            if(ctd == 3){
                cout<<"El JUGADOR |x| GANA!!"<<endl;
                ganar=1;
                break;
            }else if( ctd2 == 3){
                cout<<"El JUGADOR |o| GANA!!"<<endl;
                ganar=1;
                break;
            }else{
                ctd = 0;
                ctd2 = 0;
            } 
        }
        //Ganar Diagonal

        ctd = 0;
        ctd2 = 0;

        /*Diagonal principal*/
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][i] == 'x'){
                ctd++;
            }

            if(tabla[i][i] == 'o'){
                ctd2++;
            }
        }

        if(ctd == 3){
            cout<<"El JUGADOR |x| GANA!!"<<endl;
            ganar=1;
        }else if(ctd2 == 3){
            cout<<"El JUGADOR |o| GANA!!"<<endl;
            ganar=1;
        }

        /*Reinicio de contadores*/
        ctd = 0;
        ctd2 = 0;

        /*Diagonal secundaria*/
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][3 - 1 - i] == 'x'){
                ctd++;
            }

            if(tabla[i][3 - 1 - i] == 'o'){
                ctd2++;
            }
        }

        if(ctd == 3){
            cout<<"El JUGADOR |x| GANA!!"<<endl;
            ganar=1;
        }else if(ctd2 == 3){
            cout<<"El JUGADOR |o| GANA!!"<<endl;
            ganar=1;
        }
        

        //EMPATE
        ctd = 0;
        ctd2 = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if (aux == '-'){
                    ctd3 +=1;
                }
            }    
        }
        if ( ctd3 == 0){
            cout<<"Empate!!"<<endl;
            ganar = 1;
        }else{
            ctd3=0;
        }  

        if( ganar == 1){
            break;
        }


        //  MECANICA EXTRA CARTAS Y MINAS 

        if(ext != 1){
            ext=1;
        }                        
        do{
            cout<<"-----------------------------"<<endl;
            cout<<"<<<<<<<<<<<CARTA!!>>>>>>>>>>>"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Elige tu carta [1 - 9]: ";cin>>filamina;cout<<"\n"; 
            if(filamina >=1 and filamina<=9){
                ini = 0;
            }else{
                ini = 1;
            }
            filamina--;
        }while( ini != 0 );

        int filaCarta = filamina / 3;
        int columnaCarta = filamina % 3;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   srand(time(0));
                int naleatorio = rand() % 5 + 1 ;
                minas[i][j]={naleatorio} ;
            }
        }

        aux3 = minas[filaCarta][columnaCarta];


        if(aux3== 1){
            if (anticheat==1)
            {
            /*Esta condicion verifica si el jugador esat intentando sacar doble turno muchas veces por lo cual lo penaliza*/
                cout<<"TRAMPOSO!! no puedes tener turnos infinitos :("<<endl;
            }
            cout<<"BOOOM!!!!"<<endl;
            cout<<"TE TOCO EXPLOSION!!" <<endl;
            cout<<"La ultima |o| sera destruida"<<endl;
            if ((fila2 == prof1) and (proc1 == columna2)){
                cout<<"ESCUDO ACTIVADO!!"<<endl;
                cout<<"Tu casilla estaba protegida por el ESCUDO!!"<<endl;
                prof1=4;proc1=4;          
            }else{
            tabla[fila2][columna2] = {'-'};
            }
            cout <<"\n"; 

        }else if(aux3 == 2){

            int ctd4 = 0;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++)
                {
                    aux = tabla[i][j];
                    if (aux == 'x'){
                        ctd4 +=1;
                    }
                }    
            }
            cout<<"ROBO!!!"<<endl;
            if (ctd4>=1)
            {
                
                cout<<"Puedes robar una ficha de tu oponente"<<endl;
                for (int i = 0; i < 3; i++)
                    {
                    if (i == 0){
                        cout<< "  c1  c2  c3 " << endl; 
                    }
                    cout<< "f" << i + 1<< " "; 
                    for (int j = 0; j < 3; j++)
                    {
                        
                        cout<<tabla[i][j];
                        if (j < 2){
                            cout<< " | ";
                        }
                    }
                    cout <<"\n";
                    if (i < 2){
                        cout<< "  ---|---|---" << endl;
                    }    
                }
                cout <<"\n";
                cout<<"Elije una casilla para robar la |o|"<<endl;
                do{
                cout<<"Elije una fila [1-3]"<<endl;
                cin >> fila2;
                if(fila2 >=1 and fila2<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                cout<<"Elije una columna [1-3]"<<endl;
                cin >> columna2;
                if(columna2 >=1 and columna2<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                    fila2 --;
                    columna2 --;

                if(tabla[fila2][columna2] == '-' or tabla[fila2][columna2] == 'o' ){
                    cout<<"CASILLA NO VALIDA :("<<endl;
                    ini = 1;
                }else{
                    cout<<"CASILLA VALIDA :)"<<endl;
                    ini = 0;
                }    
                }while( ini != 0 );
                if ((fila2 == prof1) and (proc1 == columna2)){
                    cout<<"ESCUDO ACTIVADO!!"<<endl;
                    cout<<"La casilla del oponente estaba protegida por el ESCUDO!!"<<endl;
                    prof1=4;proc1=4;
                }else{
                tabla[fila2][columna2] = {'o'};
                }
            }else{
                cout<<"MALA SUERTE!!!!"<<endl;
                cout<<"Aun no hay ningun |x| que robar"<<endl;
                cout<<"PIERDES LA CARTA :("<<endl;
            }cout <<"\n"; 
            

        }else if(aux3 == 3){
            cout<<"ESCUDO!!!!"<<endl;
            cout<<"Tu ultima |o| sera PROTEGIDA"<<endl;
            prof2 = fila2;
            proc2 = columna2;
            cout <<"\n"; 

        }else if(aux3 == 4){
            //BLOQUEO
            cout<<"BLOQUEO!!!!"<<endl;
                cout <<"\n";
                cout<<"Elije una casilla para bloquear a tu oponente"<<endl;
                do{
                cout<<"Elije una fila [1-3]"<<endl;
                cin >> fila2;
                if(fila2 >=1 and fila2<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                cout<<"Elije una columna [1-3]"<<endl;
                cin >> columna2;
                if(columna2 >=1 and columna2<=3){
                    ini = 0;
                }else{
                    ini = 1;
                }
                    fila2 --;
                    columna2 --;
                if(bloqueo[fila2][columna2] == '+'){
                    cout<<"CASILLA NO VALIDA :("<<endl;
                    ini = 1;
                }else{
                    cout<<"CASILLA VALIDA :)"<<endl;
                    ini = 0;
                }
                }while( ini != 0 );    
            bloqueo[fila2][columna2] = {'*'};
            cout <<"\n"; 

        }else if(aux3 == 5){
            //DOBLE TURNO
            cout<<"DOBLE TURNO!!!!"<<endl;
            cout<<"Tienes un turno extra"<<endl;
            ext=0;
            cout <<"\n"; 
            minas[filaCarta][columnaCarta]=1;
            anticheat = 1;
        }    

        filamina = 0 ;


        }while(ext!=1);

        if(ganar ==1){
        break;
        anticheat=0;//Esta linea reestablece el anticheat para qeu no salga el mismo mensaje a cada rato y sin necesidad
    }
    }while(ganar!=1);
    



    cout << "\n";
    system("pause");
    //es una función para no cerrar automáticamente el cpp
}


//reglas

void reglas() {

    system("cls");

    cout<<"==================================="<<endl;
    cout<<"   TRES EN RAYA... CON CARTAS!!!"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";

    
    cout<<"==================================="<<endl;
    cout << "           REGLAS"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";

    cout << "El clasico Tres en Raya..."<<endl;
    cout << "normal y tranquilo..."<<endl;
    cout << "HASTA QUE APARECEN LAS CARTAS!!!"<<endl;
    cout <<"\n";

    cout << "Despues de cada turno deberas escoger"<<endl;
    cout << "una de las 9 cartas misteriosas."<<endl;
    cout << "Cada una puede cambiar el destino"<<endl;
    cout << "de la partida en segundos."<<endl;
    cout <<"\n";

    cout<<"==================================="<<endl;
    cout << "      CARTAS ESPECIALES"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";

    cout << "[1] ESCUDO!!!"<<endl;
    cout << "Te protege del ROBO y de las explosiones."<<endl;
    cout <<"\n";

    cout << "[2] BOOM!!!"<<endl;
    cout << "Tu ficha EXPLOTA y desaparece del tablero."<<endl;
    cout << "Pero si tienes ESCUDO... sobrevives."<<endl;
    cout <<"\n";

    cout << "[3] ROBO!!!"<<endl;
    cout << "Puedes colocar TU ficha en lugar"<<endl;
    cout << "de la del oponente."<<endl;
    cout << "No funciona contra ESCUDO."<<endl;
    cout <<"\n";

    cout << "[4] BLOQUEO!!!"<<endl;
    cout << "Bloquea una casilla e impide que"<<endl;
    cout << "el oponente juegue ahi."<<endl;
    cout <<"\n";

    cout << "[5] DOBLE TURNO!!!"<<endl;
    cout << "Obtienes un turno extra."<<endl;
    cout << "Aprovechalo sabiamente."<<endl;
    cout <<"\n";

    cout<<"==================================="<<endl;
    cout << "    MUCHA SUERTE JUGADOR..."<<endl;
    cout << "      Y QUE COMIENCE"<<endl;
    cout << "         EL CAOS"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";  
    


    cout << "\n";
    system("pause");
}


//creditos :)))jnsjnsa

void creditos() {

    system("cls");

    cout<<"==================================="<<endl;
    cout<<"   TRES EN RAYA... CON CARTAS!!!"<<endl;
    cout<<"==================================="<<endl;
    cout <<"\n";

    
    cout<<"--------------CREDITOS--------------"<<endl;
    cout<<"Desarrollado por:"<<endl;
    cout<<"\n";
    cout<<"-Nicolas Torres"<<endl;
    cout<<"\n";
    cout<<"-Sebastian Moreno"<<endl;
    cout<<"\n";
    cout<<"-Julian Gamarra"<<endl;
    cout<<"\n";
    cout<<"-Zaid Jaramillo"<<endl;

    cout << "\n";
    system("pause");
}
```

</details>

## Conclusiones
#### Proyecto impulsado por el trabajo en equipo, se interactuo con los recursos impartidos en clase (variables, bucles, funicones, etc..). Al ser un proyecto tan masivo la corrección constante fue muy importante y necesaria. 
