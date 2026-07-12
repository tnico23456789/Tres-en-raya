# **CARTAS EN RAYA+BUSCAMINAS** ❌⭕ 
## **_Integrantes_**
#### Paul Moreno
#### Zaid Jaramillo
#### Julián Gamarra
#### Nicolás Torres

<details>
<summary>📌 Mostrar Proyecto Primer bimestre</summary>
    
## **_Descripción del proyecto inicial_** 
#### El juego es una fusión: Una base de un tres en raya clásico, acoplado a un sistema aleatorio de cartas que dicta ciertas ventajas o desventajas al usuario en su siguiente turno, entre las cuales están: **Perdida de turno**, **Roba un espacio**, **Turno extra** etc... Cada jugador deberá colocar sus fichas (X y O) intentando completar una línea de 3 símbolos iguales, pero después de cada turno podrá escoger una carta especial que puede cambiar completamente el rumbo de la partida, lo que lo hace completamente IMPREDECIBLE!!!
## 🥇 Victoria
#### Un jugador gana si:
#### Forma una línea de 3 símbolos iguales (horizontal, vertical o diagonal).
## 🤝 Empate
#### Cuando el tablero se completo y ninguno de los 2 jugadores completo una fila, una columna o una diagonal con 3 de su respectiva ficha. Existe la opción de jugar una nueva ronda indefinidamente hasta que cualquiera de los dos gane, incluso si un de los dos gana pueden seguir juganndo.
## 🥈 Derrota
#### Un jugador pierde cuando:
#### El rival completa una línea ganadora (VERTICAL, HORIZONTAL O DIAGONAL).
## CÓDIGO EJECUTABLE (con comentarios explicativos)
# 🧩 Explicación de las partes más importantes del código

## 🎮 Menú principal

#### Esta parte del código se encarga de mostrar el menú principal del juego.  
#### Permite al usuario escoger entre jugar, leer las reglas, ver los créditos o salir del programa.  
#### Se utiliza un `switch` junto a un bucle `do while` para mantener el menú activo hasta que el jugador decida cerrar el juego.

<details>
<summary>📌 Mostrar código del menú principal</summary>

```cpp
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
```

</details>

## Inicialización del tablero

#### Aquí se crean las matrices principales del juego:
- `tabla` → almacena las fichas X y O.
- `bloqueo` → controla las casillas bloqueadas.
- `minas` → guarda los efectos aleatorios de las cartas.

#### Luego se rellenan las casillas vacías con el símbolo `-`.

<details>
<summary>📌 Mostrar código de inicialización del tablero</summary>

```cpp
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


```
</details>

## ♠️♥️♦️♣️ Sistema de cartas aleatorias
#### Después de cada turno el jugador puede escoger una carta.
#### El sistema genera números aleatorios utilizando `rand()` ![#f03c15](https://placehold.co/15x15/f03c15/f03c15.png) (sirve para generar números enteros pseudoaleatorios (números al azar) en un rango desde 0 hasta una constante llamada RAND_MAX).  y `srand(time(0))` ![#1589F0](https://placehold.co/15x15/1589F0/1589F0.png)  **(sirve para inicializar la semilla del generador de números pseudoaleatorios. para asignar efectos especiales).**
#### Dependiendo del número obtenido se activa:
#### - 💥Explosión
#### - 💸Robo
#### - 🛡️Escudo
#### - ❌Bloqueo
#### - ✌️Doble turno
<details> 
<summary>📌 Mostrar código del sistema de cartas</summary>

  ```cpp
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
    
    anticheat=0;//Esta linea reestablece el anticheat para que no salga el mismo mensaje a cada rato y sin necesidad
    if(ganar ==1){
        break;
    }
    /*Antes de empezar el turno del jugador 2 esta condición verifica si existe un jugador que haya ganadao temrinando el juego con el bucle principal*/
```
</details>

## 🏆 Verificación de victoria
#### Esta parte verifica si un jugador logró completar una línea de 3 símbolos iguales.
#### El código revisa:
#### Filas
#### Columnas
#### Diagonales
#### Si detecta tres X o tres O, el juego termina declarando al ganador.
#### Los detecta a traves de bucles `for` y condicionales `If`, `Else if` & `Else`
<details>
<summary>📌 Mostrar código  fuente</summary>
  
  ```cpp
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
```
</details>

## 🏁 Código final
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


//creditos 

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
#### Proyecto impulsado por el trabajo en equipo y el autoaprendizaje sumado a las enseñanzas inpartidas en clase, se interactuo con los recursos estudiados en clase (variables, bucles, funicones, etc..). Al ser un proyecto tan masivo la corrección constante fue muy importante y necesaria. Con el tiempo dado se alcanzó a optimizar el código para que su desempeño no se vea vulnerado por errores de código. Además, el trabajo en equipo fue clave para desarrollar una idea más ambiciosa y divertida que un Tres en Raya tradicional. La constante corrección de errores y optimización ayudó a mejorar tanto la jugabilidad como la estabilidad del código final.
El resultado fue un juego dinámico, caótico y entretenido que combina estrategia y suerte en cada ronda.
</details>

## Descripción del avance del proyecto
#### Debido al gran avance adquirido en el proyecto base (Tres en raya), se optó por la ampliación de la selección de videojuegos en el apartado del menú. El juego escogido fue el Buscaminas, un vieoujuego clásico que todos hemos escuchado. Se realizó una répica clásica de este famoso juego, sumando la selección de dificultad y el tamaño del tablero de preferencia del jugador.
## Buscaminas
#### El objetivo es despejar un tablero de casillas ocultas sin detonar ninguna mina. Al hacer clic en un cuadro, si revela un número, este indica cuántas minas hay en las 8 casillas circundantes (todas las casillas alrededor).
## 🥇 Victoria
#### Un jugador gana si:
#### Coloca correctamente todas las benderas sobre las minas, sin seleccionar ninguna de ellas.
## 🥈 Derrota
#### Un jugador pierde cuando:
#### Estalla una mina.
# 🧩 Explicación de las partes más importantes del código
## INCLUSIÓN DE LIBRERIAS EXTRAS 📚
#### Además de las librerias `<iostream>`, `<cstdlib>` y `<ctime>` utilizadas en el codigo para la creación de herramientas aleatorias y el aspecto visual del juego para una buena experiencia del usuario.
#### Se añado una cuarta librería `<conio.h>`, libreía que permite manipular la interfaz de la consola de texto en lenguajes como `C` y `C++`. Se utiliza para leer teclas individuales sin necesidad de presionar `Enter` (getch), detectar si se ha pulsado una tecla (kbhit), borrar la pantalla (clrscr) y posicionar el cursor en coordenadas específicas (gotoxy). Nos enffocamos en el uso de la función `clrscr`, refresca la pantalla inmediatamente el jugador hace una acción, el ejecutable no se "forma" ni se "apila", la pantalla permanece en tiempo real dando una sensación de fluidez muy agrdable para el jugador.
## Estructuras definidas ('structs') 
#### Una ventaja muy clara de las structs esta en que permite ocupar datos de distintos tipos y definirlas en una misma "variable". Aprovechando fueron definidas dos structs que nos ayudan manejar los elementos que ocupamos en el videojuego (minas, espacios vacios, numeros que indican minas alrededor, incognitas (lugares sin revelar) y banderas).
#### Los hemos separado en dos structs debido a que, un grupo de estos elementos no van a ser vistos como tal en el programa que son: minas, espacios vacios y numeros sin revelar.
#### El jugador al iniciar la partida va a encontra unicamnete visibles: cantidad de banderas disponibles y los espacios sin revelar.

<details>
<summary>📌 Mostrar libreria (objetos visibles) </summary>
    
  ```cpp
typedef struct
{
    string inc = "?";
    string bandera = "/";
}tIcono2;

```
#### Esta estructura contiene los símbolos visibles para el jugador durante la partida.

#### Incluye dos elementos:

#### `inc ("?")`: representa una casilla aún sin descubrir.
#### `bandera ("/")`: representa una bandera colocada por el jugador para marcar una posible mina.

#### De esta manera se mantiene separado el tablero real del tablero que observa el jugador.
</details>

<details>
<summary>📌 Mostrar libreria (objetos invisibles) </summary>
    
  ```cpp
typedef struct
{
    string mina = "*";
    string vacio = " ";
    string numina;

}tIcono

```

#### Sus atributos son:

#### `mina`: representa una mina mediante el carácter "*".
#### `vacio`: representa una casilla sin minas alrededor utilizando un espacio en blanco.
#### `numina`: almacena el número de minas adyacentes convertido a una cadena (string).

El uso de esta estructura evita escribir los mismos símbolos repetidamente a lo largo del código, facilitando futuras modificaciones.
</details>

## Inicialización del tablero
### Variables principales del juego
  ```cpp
int num,win=0,seguir=0;
int filacu = 0,columnacu = 0,ctdminas = 0,ctdwin = 0, dificultad = 1,aux=0;
  ```
#### Estas variables controlan el estado de la partida:

#### `num`: tamaño del tablero.
#### `win`: almacena el estado de la partida (en curso, victoria o derrota).
#### `seguir`: determina si el jugador desea iniciar otra partida.
#### `filacu y columnacu`: posición actual del cursor dentro del tablero.
#### `ctdminas`: cantidad de minas presentes o banderas disponibles.
#### `ctdwin`: número total de minas, utilizado para verificar la victoria.
#### `dificultad`: porcentaje de minas que tendrá el tablero.
#### `aux`: variable de apoyo para validar entradas del usuario.
### Creación de los tableros
```cpp
string mapa[100][100];
string mapaqseve[100][100];
```
#### El juego utiliza dos matrices independientes:

#### `*mapa*` almacena la información real del tablero, incluyendo minas, espacios vacíos y números.
#### `*mapaqseve*` representa el tablero visible para el jugador, ocultando inicialmente todas las casillas.

#### Esta separación permite mantener oculta la información del tablero hasta que el jugador descubra cada casilla.
### TAMAÑO Y DIFICULTAD DEL TABLERO 
#### Antes de iniciar el juego, el usuario debe elegir el tamaño del tablero y seleccionar la dificultad de la partida. Los datos de entrada de la dificultad que ingresen dictan la probabilidad de aparición de una casilla por cada espacio del tablero, entre mas alto el numero mas probable es la aparición de una mina en cualquiera de las casillas, asi si el jugador escoge un numero muy grande (entre el rango definido de dificultad por el programdor). 
```cpp
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
```


#### A diferencia del codigo de Tres en raya, llenar el tablero del buscaminas requiere realizar la accion de llenar varias veces:
#### 1. Llenar las minas basandose en la dificultad que escogió el jugador.
#### Llamamos a la función:
```cpp
llenarmatriz(mapa,num,dificultad);
```
```cpp

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
```
#### Funcion numaleatorio
```cpp
int numaleatorio(int num){
    
    return rand()%num;
}
```
#### Funcion que arroja un numero al azar gracias a la librería `<ctime>`.
#### 2. Llenar alrededor de las minas los numeros que indican la cantidad de las mismas alrededor 
#### Llamamos a la función:
```cpp
llenarmatriznumeros(mapa,num);
```
#### Esta función recorre todo el tablero una vez que las minas ya fueron colocadas. Su objetivo es calcular cuántas minas existen alrededor de cada casilla y almacenar ese número en el tablero.
Las casillas que contienen una mina no son modificadas, mientras que las casillas vacías reciben el número correspondiente de minas adyacentes.
```cpp
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
```
#### Se utilizan dos ciclos anidados para recorrer cada posición de la matriz. De esta manera, todas las casillas son procesadas individualmente, sin importar el tamaño del tablero.
#### Para cada casilla se llama a la función contarnumeros(), encargada de contar cuántas minas existen en las nueve posiciones que la rodean.
El resultado se almacena en la variable x.
```cpp
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
```
#### 3. Llenar la matriz visible del jugador. 
```cpp
void rellenarmapaqseve(string mapa[][100], int num){
    tIcono2 mapa2;
    mapa[num][num];
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            mapa[i][e]=mapa2.inc;
        }
    }   
}
```
Se llama a esta función al iniciar la partida, su objetivo es llenar la matriz de `?', a medidda que va avanzando el juego estas van despareciendo dependiendo de la seleccion de casilla del usuario y que elementos estan cerca o en la casilla seleccionada.  
### IMPRESION DE MAPA
```cpp
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
```
Aparicion del jugador (|X|), aompañado de una función llamada `controles()`
```cpp
void controles(){
    cout << "===================================" << endl;
    cout << "              MOVIMIENTO            " << endl;
    cout << "                  W                  " << endl;
    cout << "                A S D                " << endl;
    cout << "Q:Revelar Casilla     E:Poner Bandera" << endl;
    cout << "===================================" << endl;
}
```
Una funcion que es la que se visualiza en todo el programa y da información al ususario acerca de las teclas destinadas a su juego, dotandole del típico `AWSD` para una experiencia de usuario ideal gracais al subprograma `movimiento()`
```cpp
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
```

#### Se define la variable "tecla" `char tecla = _getch()`, la funcion `_getch()` espera a que el jugador presione una tecla y almacena el carácter ingresado en la variable tecla.
La función `_getch()`, perteneciente a la biblioteca `<conio.h>`, tiene dos características importantes:

No requiere presionar Enter, por lo que la acción se ejecuta inmediatamente al pulsar una tecla.
No muestra el carácter en la consola, evitando que las teclas utilizadas para controlar el juego aparezcan en pantalla.

#### Ademas del movimeinto se definen las teclas `Q` y `E` que son para revelar la casilla y colocar bandera respectivamente en ese orden
### Funcion `expansionre()`
#### Esta función implementa la expansión automática de casillas vacías. Cuando el jugador descubre una casilla que no tiene minas alrededor, la función revela también las casillas vacías vecinas de forma recursiva, reproduciendo el comportamiento clásico del Buscaminas.
```cpp
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
    
```
### Verificacion de victoria
```cpp
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
```
#### Se crea un contador llamado `ctd`, cuya función es registrar cuántas minas han sido marcadas correctamente con una bandera.
#### La función recorre todas las posiciones del tablero para comparar el contenido del tablero real con el tablero visible.
#### De esta forma, verifica una por una todas las casillas de la partida.
#### En cada casilla se comprueba si:

#### - En el tablero real existe una mina ("*"), y
#### - En el tablero visible el jugador colocó una bandera ("/").

#### Cuando ambas condiciones se cumplen, significa que esa mina fue identificada correctamente, por lo que el contador se incrementa.
#### Al finalizar el recorrido, se compara la cantidad de minas correctamente marcadas con el número total de minas del tablero.

#### Si ambos valores coinciden, la variable win toma el valor 2, indicando que el jugador ha ganado la partida al localizar correctamente todas las minas.
### CONCLUSIONES
#### El desarrollo de este proyecto permitió aplicar de manera práctica los fundamentos de programación en C++, integrando estructuras, funciones, matrices bidimensionales y recursividad para construir un juego completamente funcional. Además, se reforzó la importancia de dividir el programa en subprogramas, facilitando su organización, mantenimiento y comprensión. La implementación de la lógica del Buscaminas también permitió trabajar con validación de datos, generación aleatoria de escenarios e interacción con el usuario mediante el teclado. En conjunto, el proyecto representa una aplicación completa de los conocimientos adquiridos, combinando lógica de programación, resolución de problemas y diseño de algoritmos.
