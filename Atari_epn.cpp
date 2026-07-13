// Librerias utilizadas:
// cstdlib  -> rand().
// ctime    -> time() para la semilla.
// conio.h  -> _getch() para leer teclas sin Enter.
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
// <ctime> para que la semilla srand sea distinta dependiendo del tiempo
// <cstdlib> librería para limpiar pantalla
using namespace std;
//prototipos tres en raya
void jugar();//bucle del juego principal
void tablero(char tabla[3][3]);//imprime el tablero a tiempo real
void elecfilacolumna(bool bloq, bool rob, char tabla[3][3], char bloqueo[3][3], char player1, int &fila1, int &columna1);//funcion para pedir al jugador que elija la fila y columna para colocar su ficha o para elegir la casilla a bloquear o a robar dependiendo de la carta que le haya tocado
void ganador(char tabla[3][3], char player1, char player2, bool &ganar, bool &salida);//funcion para encontrar verificar si alguien ha ganado o hay empate
void ezcudo(bool escudo_activo, char escudo[3][3], char player1, int fila1, int columna1, bool &proteccion);//funcion para activar el escudo o desactivarlo si fue gastado.
void titulo_jugador(char player1);

void reglas();
void titulo_reglas();
void cartas_especiales_titulo();

void creditos();

void titulo();
//titulo: Tres en raya... con cartas.

//prototipos buscaminas
void buscaminas();
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
// Llena el tablero colocando minas de forma aleatoria.
void llenarmatriz(string matriz[][100],int num,int num2);
// Devuelve un numero aleatorio entre 0 y num-1.
int numaleatorio(int num);
// Imprime el tablero visible y la posicion del cursor.
void imprimirmapa(string mapa[][100], int num,int &columnacu,int &filacu);
// Calcula los numeros alrededor de cada mina.
void llenarmatriznumeros(string matriz[][100],int num);
// Cuenta cuantas minas rodean una casilla.
int contarnumeros(string matriz[][100],int i,int e,int num);
// Procesa el movimiento del jugador y las acciones.
void movimiento(int &filacu,int &columnacu,int num,string mapa[][100],string mapa2[][100], int &win,int &ctdminas, int &primerMovimiento ,int &dificultad);
// Inicializa el tablero visible con casillas ocultas.
void rellenarmapaqseve(string mapa[][100], int num);
// Expande recursivamente las casillas vacias.
void expansionre(int fila,int columna,string mapa[][100],string mapa2[][100],int num);
// Reinicia ambas matrices.
void reiniciarmatrices(string matriz[][100],string matriz2[][100]);
// Cuenta el numero total de minas.
int contadorminas(string matriz[][100],int num);
// Muestra las banderas restantes.
void banderas(int &ctd);
// Verifica si el jugador ha ganado.
void verificadorwin(string matriz[][100],string matriz2[][100],int num,int &win);
// Muestra los controles del juego.
void controles();



// funciones fuera del main para editar el código por partes, en el caso de ser nesesario solo tocar una función y no todo el código
int main()//menú
{

    int opcion;//opción de menu

    do
    {
        system("cls");

        cout << "===================================" << endl;
        cout << "             ATARI EPN" << endl;
        cout << "===================================" << endl;
         cout << "\n";

        cout << "1. Tres en raya con CARTAS\n";
        cout << "2. Buscaminas\n";
        cout << "3. Creditos\n";
        cout << "4. Salir\n\n";

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            int opcion2;
            do{
                system("cls");
                titulo();
                cout << "1. Jugar\n";
                cout << "2. reglas\n";
                cout << "3. salir\n\n";
                cout << "Opcion: ";
                cin >> opcion2;
                switch(opcion2){
                    case 1:
                        jugar();
                        break;
                    case 2:
                        reglas();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "\nOpcion invalida\n";
                        system("pause");
                }
                
            }while(opcion2!=3);
            break;

        case 2:
            system("cls");
            buscaminas();
            cout<<opcion;
            break;

        case 3:
            creditos();
            break;

        case 4:
            cout << "\nCHAOO!!!\n";
            cout << "\nCerrando juego...\n";

            system("pause");
            break;

        default:
            cout << "\nOpcion invalida\n";
            system("pause");
        }

    } while (opcion != 4);

    return 0;
}

void jugar()//bucle del juego principal
{
    // limpia la pantalla el symtem("cls")
    system("cls");
    // restablecer las variables
    char player1 = 'x', player2 = 'o';//jugador 1 y jugador 2
    
    int fila1, columna1;//seleccion de fila o columna
    bool salida = false;
    bool ganar = false;//confirmacion para saaltar del bucle de juego una vez ya haya ganado un jugador
    bool proteccion = true;//verificacion para saber si el escudo está activado o desactivado
    bool casilla_bloqueada = false;//verificacion para ver si el jugdor fue bloqueado
    srand(time(0));


    //comienzo
    titulo();

    /*Relleno de las matrices con elementos */
    /*Matriz de Tablero*/
    char tabla[3][3]={
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };
    /*Matriz de Cartas*/

    /*Matriz para la funcion de Bloqueo*/
    char bloqueo[3][3]={
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };
    //matriz para la funcion de escudo
    char escudo[3][3]={
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };


    do
    { /*Bucle Principal de Juego para ambos jugadores*/
        // jugador1 mecanica tres en raya normal
        
        do
        { /*Bucle de Turno para el Jugador 1*/
            titulo_jugador(player1);
            tablero(tabla);//inmprime tablero
            cout << "\n";

            elecfilacolumna(false,false,tabla,bloqueo,player1,fila1,columna1);//pide al juagador la posicion para colocar su ficha

            // Bloque de  posicionamiento de Ficha
            /*Este bucle lee y verifica si la casilla ingresada esta bloqueada o no para pdoer colocar la respectiva X*/
            if (bloqueo[fila1][columna1] != '*')
            {
                /*Esta condicion agrega un + a la matriz del bloqueo para un uso posterior de esta*/
                cout << "\n";
                titulo_jugador(player1);
                cout << "La |"<< player1 <<"| fue colocada" << endl;
                tabla[fila1][columna1] = {player1};
                bloqueo[fila1][columna1] = {'+'};
                cout << "\n";
            }
            else
            {
                cout << "\n";
                cout << "CASILLA BLOQUEADA :(" << endl;
                //quita el bloque si fue impuesto antes
                bloqueo[fila1][columna1] = {'-'};
                cout << "\n";
                casilla_bloqueada = true;
            }

            /*Este bucle imprime el tablero actual de juego*/
            tablero(tabla);
            cout << "\n";
            ganador(tabla, player1, player2, ganar, salida);
            //cout << ganar << endl;
            if (casilla_bloqueada == true)
                {
                    cout << "CASILLA BLOQUEADA" << endl;
                    cout << "NO PUEDES ELEGIR CARTA :(" << endl;
                }
            if (ganar != true && casilla_bloqueada == false)//condicion para que no pueda entrear el jugador si fue bloqueado
            {
                
                
                ganador(tabla, player1, player2, ganar, salida);

                //  MECANICA EXTRA CARTAS
                /*Aqui comienza con la lógica de programacion de la implmentación en este caso despues de poner su X o O  tiene la opcion de elegir entre 9
                cartas que pueden tener 5 efectos posibles*/
                int karta = 0;
                salida = true;
                cout << "-----------------------------" << endl;
                cout << "<<<<<<<<<<<CARTA!!>>>>>>>>>>>" << endl;
                cout << "-----------------------------" << endl;
                bool error = false;
                do
                {
                    cout << "Elige tu carta [1 - 9]: ";
                    cin >> karta;
                    cout << "\n";
                    if ((karta >= 1 and karta <= 9) or (karta >= 101 and karta <= 105))
                    {
                        error = false;
                    }
                    else
                    {
                        error = true;
                        cout << "OPCION NO VALIDA :(" << endl;
                    }
                    
                } while (error == true);
                /*Esta linea transforma el numero ingresado por el usuario para traducirlo a una posicion en la matriz de cartas primero divide para 3
                para sacar las filas y el residuo o el MOD indica la columna de la matriz*/
                
                if (karta >= 1 and karta <= 9)
                {
                    /* Aqui se esta ocupando la funcion srand para la generacion de nuemros aleatorios usando una semilla de tiempo 0*/
                    
                    int numeroaleatorio = rand()%5 + 1;
                    karta = numeroaleatorio;
                    
                }
                else
                {
                    karta = karta - 100;
                    //cout << karta << endl;
                }
                /*Aqui empiezan los 5 efectos posibles*/
                if (karta == 1)
                {
                    // EXPLOSION!
                    /*Aqui comienza el primer efecto explosion hace que el jugador pierda la ultima ficha que puso utiliza un condicional que lee la utlima casilla basada
                    en la ultima entrada del jugador*/

                    cout << "BOOOM!!!!" << endl;
                    cout << "TE TOCO EXPLOSION!!" << endl;
                    cout << "La ultima |" << player1 << "| sera destruida" << endl;
                    
                    ezcudo(false, escudo, player1, fila1, columna1, proteccion);
                    if (proteccion == true)
                    {
                        tabla[fila1][columna1] = {'-'};
                        bloqueo[fila1][columna1] = {'-'};
                    }
                    proteccion = true;
                    cout << "\n";
                }
                else if (karta == 2)
                {
                    // ROBO!
                    /*Con esta carta puedes robar la posicion del enemigo en este caso el O del enemigo para el jugador 2 sera alrevez pero con la misma lógica*/
                    int ctd4 = 0;
                    /*Este bucle for anidado verifica que exista un O que robar en caso no lo haya pierde su carta*/
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            char aux;
                            aux = tabla[i][j];
                            if (aux == player2)
                            {
                                ctd4 += 1;
                            }
                        }
                    }
                    cout << "ROBO!!!" << endl;
                    if (ctd4 >= 1)
                    {
                        /*Aqui muestra el tablero actual mediante un bucle for como al principio*/

                        cout << "Puedes robar una ficha de tu oponente" << endl;
                        tablero(tabla);
                        /*Aqui pregunta donde desea su respectiva*/
                        cout << "\n";
                        cout << "Elije una casilla para robar la |" << player2 << "| de tu oponente" << endl;
                        
                        elecfilacolumna(false,true,tabla, bloqueo, player1, fila1, columna1);
                        
                        /*Esta linea verifica si una casilla esta protegida otra de las cartas qeu se explicara despues*/
                        
                        ezcudo(false, escudo, player1, fila1, columna1, proteccion);
                        if (proteccion == true)
                        {
                            tabla[fila1][columna1] = player1;
                        }
                        proteccion = true;
                        tablero(tabla);
                    }
                    else
                    {
                        cout << "MALA SUERTE!!!!" << endl;
                        cout << "Aun no hay ningun |" << player2 << "| que robar" << endl;
                        cout << "PIERDES LA CARTA :(" << endl;
                    }
                    cout << "\n";
                    ganador(tabla, player1, player2, ganar, salida);
                }
                else if (karta == 3)
                {
                    // ESCUDO
                    /*Esta carta escudo permite al jugador defender su ultima X puesta o O dependiendo del jugador que este en su turno*/
                    
                    ezcudo(true, escudo, player1, fila1, columna1, proteccion);
                }
                else if (karta == 4)
                {
                    // BLOQUEO
                    /*Esta carta permite poner un bloqueo en una casilla para que el otro jugador no pueda poner su X o O respectivamente*/
                    cout << "BLOQUEO!!!!" << endl;
                    cout << "\n";
                    cout << "Elije una casilla para bloquear a tu oponente" << endl;

                    
                    elecfilacolumna(true,false,tabla,bloqueo, player1, fila1, columna1);
                    /*Esta linea verifica si la casilla ya esta ocupada para no permitir el bloqueo de la misma*/

                    bloqueo[fila1][columna1] = {'*'};
                    cout << "\n";
                }
                else if (karta == 5)
                {
                    // DOBLE TURNO
                    /*El nombre lo dice permite repetir el bucle en el qeu esta el jugador 1 para tener un doble turno*/
                    cout << "DOBLE TURNO!!!!" << endl;
                    cout << "Tienes un turno extra" << endl;
                    salida = false;
                    cout << "\n";
                    
                }
                ganador(tabla, player1, player2, ganar, salida);
                karta = 0;
            }

            system("pause");
        } while (salida == false); /*Complemento del bucle Do-While de arriba el que maneja el bucle del jugador 1*/

        char p3;
        p3=player1;
        player1=player2;
        player2=p3;
        

    } while (ganar != true);

    cout << "\n";
    system("pause");
    // es una función para no cerrar automáticamente el cpp

}

void titulo_jugador(char player1){
    system("cls");
    cout << "----------------JUGADOR |"<< player1 <<"|----------------" << endl;
}

void titulo_reglas(){
    cout << "===================================" << endl;
    cout << "   TRES EN RAYA... CON CARTAS!!!" << endl;
    cout << "===================================" << endl;
    cout << "              REGLAS" << endl;
    cout << "===================================" << endl;
}

void cartas_especiales_titulo(){
    system("pause");
    system("cls");
    titulo_reglas();
    cout << "      CARTAS ESPECIALES" << endl;
    cout << "===================================" << endl;
    cout << "\n";
    
}

void reglas()
{

    system("cls");
    titulo_reglas();
    cout<<endl;

    cout << "El clasico Tres en Raya..." << endl;
    cout << "normal y tranquilo..." << endl;
    cout << "HASTA QUE APARECEN LAS CARTAS!!!" << endl;
    cout << "\n";

    cout << "Despues de cada turno deberas escoger" << endl;
    cout << "una de las 9 cartas misteriosas." << endl;
    cout << "Cada una puede cambiar el destino" << endl;
    cout << "de la partida en segundos." << endl;
    cout << "\n";

    
    cartas_especiales_titulo();


    cout << "[1] ESCUDO!!!" << endl;
    cout << "Te protege del ROBO y de las explosiones." << endl;
    cout << "\n";

    cartas_especiales_titulo();
    cout << "[2] BOOM!!!" << endl;
    cout << "Tu ficha EXPLOTA y desaparece del tablero." << endl;
    cout << "Pero si tienes ESCUDO... sobrevives." << endl;
    cout << "\n";
    
    cartas_especiales_titulo();
    cout << "[3] ROBO!!!" << endl;
    cout << "Puedes colocar TU ficha en lugar" << endl;
    cout << "de la del oponente." << endl;
    cout << "No funciona contra ESCUDO." << endl;
    cout << "\n";

    cartas_especiales_titulo();
    cout << "[4] BLOQUEO!!!" << endl;
    cout << "Bloquea una casilla e impide que" << endl;
    cout << "el oponente juegue ahi." << endl;
    cout << "\n";

    cartas_especiales_titulo();
    cout << "[5] DOBLE TURNO!!!" << endl;
    cout << "Obtienes un turno extra." << endl;
    cout << "Aprovechalo sabiamente." << endl;
    cout << "\n";
    system("pause");
    system("cls");
    cout << "===================================" << endl;
    cout << "    MUCHA SUERTE JUGADOR..." << endl;
    cout << "      Y QUE COMIENCE" << endl;
    cout << "         EL CAOS" << endl;
    cout << "===================================" << endl;
    cout << "\n";

    cout << "\n";
    system("pause");
}

void creditos()
{

    system("cls");

    titulo();

    cout << "--------------CREDITOS--------------" << endl;
    cout << "Desarrollado por:" << endl;
    cout << "\n";
    cout << "-Nicolas Torres" << endl;
    cout << "\n";
    cout << "-Sebastian Moreno" << endl;
    cout << "\n";
    cout << "-Julian Gamarra" << endl;
    cout << "\n";
    cout << "-Zaid Jaramillo" << endl;

    cout << "\n";
    system("pause");
}

void titulo()
{
    cout << "===================================" << endl;
    cout << "   TRES EN RAYA... CON CARTAS!!!" << endl;
    cout << "===================================" << endl;
    cout << "\n";
}

void tablero(char tabla[3][3])
{
    cout << "  c1  c2  c3 " << endl;
    for (int i = 0; i < 3; i++)
    {
        
        cout << "f" << i + 1 << " ";
        for (int j = 0; j < 3; j++)
        {

            cout << tabla[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << "\n";
        if (i < 2)
        {
            cout << "  ---|---|---" << endl;
        }
    }
}

void elecfilacolumna(bool bloq, bool rob, char tabla[3][3],char bloqueo[3][3],char player1, int &fila1, int &columna1)
{
    bool error = false;
    
    do
    {   
        
        /*Espacio de asignacion para que el jugador 1 ingrese tanto fila como columna con un bucle qeu solo admite los valores correctos osea del 1 al 3*/
        do{
            cout << "Elije una fila [1-3]: ";
            cin >> fila1;
            if (fila1 >= 1 and fila1 <= 3)
            {
                error = false;
            }
            else
            {   
                cout << "Numero invalido. Intente de nuevo." << endl;
                error = true;
            }
        } while (error == true);
        do{
            cout << "Elije una columna [1-3]: ";
            cin >> columna1;
            // cout <<"verificacion de error:"<< error <<endl;
            if (columna1 >= 1 and columna1 <= 3)
            {
                error = false;
            }
            else
            {
                cout << "Numero invalido. Intente de nuevo." << endl;
                error = true;
            }
        } while (error == true);
        // cout <<"verificacion de error:"<< error <<endl;
        /*Linea importante para restarle 1 a la opcion ingresada por el jugador debido a que la maquina se maneja desde el numero 0*/
        fila1--;
        columna1--;
        //cout <<"verificacion de robf:"<< rob <<endl;
        //cout <<"verificacion de blqf:"<< bloq <<endl;
        if (rob == false and bloq == false)
        {
            /*if(error == false){
                cout << "CASILLA VALIDA :)" << endl;
            }*/
            // cout <<"verificacion de error:"<< error <<endl;
            if (tabla[fila1][columna1] != '-')
            {

                cout << "CASILLA NO VALIDA :(" << endl;
                error = true;
            }
            // cout <<"verificacion de simbolo de tabla:"<< tabla[fila1][columna1] <<endl;
        }
        if (rob == true)
        {
            //cout <<"verificacion de rob:"<< rob <<endl;
            if (tabla[fila1][columna1] == '-' or tabla[fila1][columna1] == player1)
            {

                cout << "CASILLA NO VALIDA PARA ROBAR :(" << endl;
                error = true;
            } else {
                cout << "CASILLA VALIDA PARA ROBAR :)" << endl;
                error = false;
            }
            rob=false;
        }
        if (bloq == true)
        {
            //cout <<"verificacion de bloq:"<< bloq <<endl;
            if (bloqueo[fila1][columna1] == '+')
            {
                cout << "CASILLA NO VALIDA PARA BLOQUEAR :(" << endl;
                error = true;
            }
            bloq=false;
        }
    } while (error == true);
}

void ganador(char tabla[3][3], char player1, char player2, bool &ganar, bool &salida)
{
    // Ganar filas
    /*Este bucle verifica si hay tres X o O en una fila para activar la win por parte del jugador correspondiente para ello recorre cada fila
    con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la fila*/
    int enraya_player1 = 0;
    if (ganar !=true){
        for (int i = 0; i < 3; i++)
        {
            enraya_player1 = 0;
            for (int j = 0; j < 3; j++)
            {
                char aux;
                aux = tabla[i][j];
                if (aux == player1)
                {
                    enraya_player1 += 1;
                    
                }  
            }
            if (enraya_player1 == 3)
            {
                cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
                ganar = true;
                salida = true;
                break;
            }
            else
            {
                enraya_player1 = 0;
            }
        }
    }
    // Ganar Columnas
    /*Este bucle verifica si hay tres X o O en una columna para activar la win por parte del jugador correspondiente para ello recorre cada columna
    de manera similar al de las filas pero con los elementos invertidos y con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la columna*/
    if (ganar !=true){
        for (int i = 0; i < 3; i++)
        {
            enraya_player1 = 0;
            
            for (int j = 0; j < 3; j++)
            {
                char aux;
                aux = tabla[j][i];
                if (aux == player1)
                {
                    enraya_player1 += 1;
                }
                
            }
            if (enraya_player1 == 3)
            {
                cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
                ganar = true;
                salida = true;
                break;
            }
            else
            {
                enraya_player1 = 0;
            }
        }
    }
    // Ganar Diagonal
    /*Este bucle verifica si hay tres X o O en la diagonal principal para activar la win por parte del jugador correspondiente para ello recorre un bucle
    verificando las entradas con nuemero similar si poseen una X o un O  para activar la win por el jugador correspondiente*/

    /*Diagonal principal*/
    if (ganar !=true){
        for (int i = 0; i < 3; i++)
        {
            if (tabla[i][i] == player1)
            {
                enraya_player1++;
            }
        }
            
        if (enraya_player1 == 3)
        {
            cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
            ganar = true;
            salida = true;
        }
        else
        {
            /*Reinicio de contadores*/
            enraya_player1 = 0;
        }
        /*Diagonal secundaria*/
        for (int i = 0; i < 3; i++)
        {
            if (tabla[i][2 - i] == player1)
            {
                enraya_player1++;
            }
        }
    }
    // EMPATE
    /*Aqui verifica el empate lo hace mediante un bucle que recorre cada fila con un contador que suma 1 siempre que vea un "-" ya que eso indica
    que la casilla esta vacía o esta llena en caso el contador no sume aunque sea 1 esta dira que es un empate*/
    int contador_empate = 0;
    if (ganar !=true){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char aux;
                aux = tabla[i][j];
                if (aux == '-')
                {
                    contador_empate += 1;
                }
            }
        }
        if (contador_empate == 0)
        {
            cout << "EMPATE!!" << endl;
            ganar = true;
            salida = true;
        }
        else
        {
            contador_empate = 0;
        }
    }

}

void ezcudo(bool escudo_activo, char escudo[3][3], char player1, int fila1, int columna1, bool &proteccion)
{
    if (escudo_activo == true)
    {
        cout << "ESCUDO!!!!" << endl;
        cout << "Tu ultima |" << player1 << "| sera PROTEGIDA" << endl;

        escudo[fila1][columna1] = {'z'};

        /*cout << "se pone" << endl;
        for (int i = 0; i < 3; i++){
            if (i == 0)
            {
                cout << "  c1  c2  c3 " << endl;
            }
            cout << "f" << i + 1 << " ";
            for (int j = 0; j < 3; j++)
            {

                cout << escudo[i][j];
                if (j < 2)
                {
                    cout << " | ";
                }
            }
            cout << "\n";
            if (i < 2)
            {
                cout << "  ---|---|---" << endl;
            }
        
        }*/
    }
    
    else
    {
        if (escudo[fila1][columna1] == 'z')
        {
            cout << "ESCUDO GASTADO!!" << endl;
            cout << "La casilla estaba protegida por el ESCUDO!!" << endl;
            escudo[fila1][columna1] = {'-'};
            proteccion = 0;
        }
        
        /*cout << "se quita" << endl;
        for (int i = 0; i < 3; i++){
            if (i == 0)
            {
                cout << "  c1  c2  c3 " << endl;
            }
            cout << "f" << i + 1 << " ";

            for (int j = 0; j < 3; j++)
            {
                
                cout << escudo[i][j];
                if (j < 2)
                {
                    cout << " | ";
                }
            }
            cout << "\n";
            if (i < 2)
            {
                cout << "  ---|---|---" << endl;
            }
        }*/
    }
}


void buscaminas(){
    int primerMovimiento = 1;
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
        int op;
        bool salida=true;
        do{
            cout<<"Elija la medida de la matriz :)"<<endl;
            cout << "1. 8x8\n";
            cout << "2. 16X16\n";
            cout << "3. 64X64\n";
            cout << "4. Personalizado\n";
            cout << "5. Salir\n\n";

            cout << "Opcion: ";
            cin >> op;
            
            switch (op){
                case 1:
                    num=8;
                    
                    do{
                        cout<<"Elija la dificultad"<<endl;
                        cout << "1. Facil\n";
                        cout << "2. Intermedio\n";
                        cout << "3. Dificil\n\n";
                        cout<<"Opcion: ";cin>>op;
                        switch (op){
                            case 1:
                                dificultad=12;
                                salida=false;
                                break;
                            case 2:
                                dificultad=15;
                                salida=false;
                                break;
                            case 3:
                                dificultad=20;
                                salida=false;
                                break;
                            default:
                                cout<<"Opcion no valida."<<endl;
                        }
                    }while(salida);
                    break;
                case 2:
                    num=16;
                    
                    do{
                        cout<<"Elija la dificultad"<<endl;
                        cout << "1. Facil\n";
                        cout << "2. Intermedio\n";
                        cout << "3. Dificil\n\n";
                        cout<<"Opcion: ";cin>>op;
                        switch (op){
                            case 1:
                                dificultad=13;
                                salida=false;
                                break;
                            case 2:
                                dificultad=16;
                                salida=false;
                                break;
                            case 3:
                                dificultad=22;
                                salida=false;
                                break;
                            default:
                                cout<<"Opcion no valida."<<endl;
                        }
                    }while(salida);
                    break;
                case 3:
                    num=32;
                    
                    do{
                        cout<<"Elija la dificultad"<<endl;
                        cout << "1. Facil\n";
                        cout << "2. Intermedio\n";
                        cout << "3. Dificil\n\n";
                        cout<<"Opcion: ";cin>>op;
                        switch (op){
                            case 1:
                                dificultad=14;
                                salida=false;
                                break;
                            case 2:
                                dificultad=18;
                                salida=false;
                                break;
                            case 3:
                                dificultad=22;
                                salida=false;
                                break;
                            default:
                                cout<<"Opcion no valida."<<endl;
                        }
                    }while(salida);
                    break;
                case 4:
                cout<<"Ingrese medida: ";cin>>num;
                do{
                    cout<<"Ingrese dificultad (1%-75%)"<<endl;
                    cin>>dificultad;
                    if( dificultad<=0 or dificultad>75){
                        aux=0;    
                    }else{
                        aux=1;
                    }
                }while(aux==0);
                    salida=false;
                    break;
                case 5:
                    salida=false;
                    return;
                    break;
                default:
                cout<<"Ingrese una opcion valida"<<endl;
            }
            
            
        }while(salida);
        
        llenarmatriz(mapa,num,dificultad);
        llenarmatriznumeros(mapa,num);
        ctdminas=contadorminas(mapa,num);
        ctdwin=contadorminas(mapa,num);
        rellenarmapaqseve(mapaqseve,num);
        while(win == 0){
            system("cls");
            banderas(ctdminas);
            verificadorwin(mapa,mapaqseve,num,win);
            imprimirmapa(mapaqseve,num,filacu,columnacu);
            movimiento(filacu,columnacu,num,mapa,mapaqseve,win,ctdminas,primerMovimiento,dificultad);
            if(primerMovimiento==1){
                ctdminas = contadorminas(mapa,num);
                ctdwin = ctdminas;
            }
            
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

// Llena el tablero colocando minas de forma aleatoria.
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
// Calcula los numeros alrededor de cada mina.
void llenarmatriznumeros(string matriz[][100],int num){
    int x;
    string z;
    tIcono mapa1;
    for(int i=0;i<num;i++){
        for(int e=0;e<num;e++){

            if(matriz[i][e]==mapa1.mina){
                continue;
            }

            x = contarnumeros(matriz,i,e,num);
            z = to_string(x);

            if(x!=0){
                matriz[i][e]=z;
            }
        }
    }
    
}
// Cuenta cuantas minas rodean una casilla.
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
// Inicializa el tablero visible con casillas ocultas.
void rellenarmapaqseve(string mapa[][100], int num){
    tIcono2 mapa2;
    mapa[num][num];
    for(int i = 0; i<num;i++){
        for(int e = 0; e<num;e++){
            mapa[i][e]=mapa2.inc;
        }

    }   

}
// Devuelve un numero aleatorio entre 0 y num-1.
int numaleatorio(int num){
    
    return rand()%num;
}
// Imprime el tablero visible y la posicion del cursor.
void imprimirmapa(string mapa[][100], int num,int &filacu,int &columnacu){
    
    
    for(int i = 0; i<num;i++){
        for(int i =0;i<num;i++){
        cout<<"+---";
        }
        cout<<"+"<<endl;
        for(int e = 0; e<num;e++){
            if(i == filacu && e == columnacu)
            {
                cout << "| \033[35mX\033[0m ";  
            }else{
                if(mapa[i][e]=="/"){
                    cout<<"| \033[31m/\033[0m ";
                }else if(mapa[i][e]=="1"){
                    cout<<"| \033[33m1\033[0m ";
                }else if(mapa[i][e]=="2"){
                    cout<<"| \033[32m2\033[0m ";
                }else if(mapa[i][e]=="3"){
                    cout<<"| \033[36m3\033[0m ";
                }else if(mapa[i][e]=="4"){
                    cout<<"| \033[34m4\033[0m ";
                }else if(mapa[i][e]=="5"){
                    cout<<"| \033[35m5\033[0m ";
                }
                else{
                cout<<"| "<<mapa[i][e]<<" ";
                }
            }
            
        }
        cout<<"|"<<"\n";
    }
     for(int i =0;i<num;i++){
    cout<<"+---";
    }
    cout<<"+"<<endl<<endl;
    controles();   

}
// Procesa el movimiento del jugador y las acciones.
void movimiento(int &filacu, int &columnacu, int num,string mapa[][100], string mapa2[][100],int &win,int &ctdminas, int &primerMovimiento, int &dificultad)
{
    tIcono mapa1;
    tIcono2 mapave;
    char tecla = _getch();

    if((tecla == 'a' or tecla == 'A') && columnacu > 0)
    {
        columnacu--;
    }
    else if((tecla == 'd' or tecla == 'D') && columnacu < num - 1)
    {
        columnacu++;
    }
    else if((tecla == 'w' or tecla == 'W') && filacu > 0)
    {
        filacu--;
    }
    else if((tecla == 's' or tecla == 'S') && filacu < num - 1)
    {
        filacu++;
    }
    else if(tecla == 'q' or tecla == 'Q')
    {

        if(primerMovimiento == 1)
        {
            while(mapa[filacu][columnacu] != mapa1.vacio)
            {
                llenarmatriz(mapa,num,dificultad);
                llenarmatriznumeros(mapa,num);
                
            }

            primerMovimiento = 0;
        }

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
// Expande recursivamente las casillas vacias.
void expansionre(int fila,int columna,string mapa[][100],string mapa2[][100],int num){
    tIcono mapa1; 
    tIcono2 mapave;
    mapa2[fila][columna] = mapa[fila][columna];
    for (int h = -1; h <=1 ; h++)
    {
        for (int l = -1; l <=1 ; l++)
        {
            if (columna+l<0 or fila+h<0 or columna+l>num-1 or fila+h>num-1)
            {
                continue;
            }else{
                if(mapa2[fila+h][columna+l] == mapave.inc){
                    // Si la casilla es un espacio, se descubre y la expansion continua.
                    if(mapa[fila+h][columna+l] == mapa1.vacio)
                    {
                        mapa2[fila+h][columna+l] = mapa[fila+h][columna+l];
                        expansionre(fila+h, columna+l, mapa, mapa2, num);
                    }
                    // Si no es una mina, significa que es un numero.
                    // Se descubre, pero la expansion termina en esa casilla.
                    else if(mapa[fila+h][columna+l] != mapa1.mina)
                    {
                        mapa2[fila+h][columna+l] = mapa[fila+h][columna+l];
                    }
                }else{                    
                    continue;
                }                    
                
            }
            
        }
    }
    
}
// Reinicia ambas matrices.
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
// Cuenta el numero total de minas.
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
// Muestra las banderas restantes.
void banderas(int &ctd){
    tIcono2 mapa1;
    string tbanderas="";
    for (int i = 0; i < ctd; i++)
    {
        tbanderas += mapa1.bandera;
    }
    cout<<"banderas: "<<tbanderas<<endl;

}

// Verifica si el jugador ha ganado.
void verificadorwin(string matriz[][100], string matriz2[][100], int num, int &win)
{
    tIcono mapa1;
    tIcono2 mapa2;

    for (int i = 0; i < num; i++)
    {
        for (int e = 0; e < num; e++)
        {
            // Si la casilla NO es una mina...
            if (matriz[i][e] != mapa1.mina)
            {
                // ...y sigue oculta, todavia no se ha ganado.
                if (matriz2[i][e] == mapa2.inc)
                {
                    return;
                }
            }
        }
    }

    // Si llego hasta aqui, todas las casillas seguras fueron descubiertas.
    win = 2;
}
// Muestra los controles del juego.
void controles(){
    cout << "=====================================" << endl;
    cout << "             MOVIMIENTO            " << endl;
    cout << "                 W                  " << endl;
    cout << "               A S D                " << endl;
    cout << "Q:Revelar casilla     E:Poner bandera" << endl;
    cout << "=====================================" << endl;
}
