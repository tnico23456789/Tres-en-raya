#include <iostream>
#include <cstdlib>
#include <ctime>
// <ctime> para que la semilla srand sea distinta dependiendo del tiempo
// <cstdlib> librería para limpiar pantalla
using namespace std;

void jugar();
void reglas();
void creditos();
void titulo();
void tablero();
void elecfilacolumna(bool bloq, bool rob);
void ganador();
void ezcudo(bool escudo_activo);
/*Definir las variables a ocupar dentro de nuestro código */
int fila1, columna1;
char tabla[3][3];
char bloqueo[3][3];
char escudo[3][3];
char player1 = 'x', player2 = 'o', aux,p3;
int ganar = 0;
bool salida = false, proteccion = 1;
// funciones fuera del main para editar el código por partes, en el caso de ser nesesario solo tocar una función y no todo el código
int main()
{

    int opcion;

    do
    {
        system("cls");

        titulo();

        cout << "1. Jugar\n";
        cout << "2. Reglas\n";
        cout << "3. Creditos\n";
        cout << "4. Salir\n\n";

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {

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

void jugar()
{
    // limpia la pantalla el symtem("cls")
    system("cls");
    // restablecer las variables
    salida = false;
    ganar = 0;
    proteccion = 1;
    bool casilla_bloqueada = false;
    srand(time(0));
    titulo();

    /*Relleno de las matrices con elementos */
    /*Matriz de Tablero*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabla[i][j] = {'-'};
        }
    }
    /*Matriz de Cartas*/

    /*Matriz para la funcion de Bloqueo*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bloqueo[i][j] = {'-'};
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            escudo[i][j] = {'-'};
        }
    }


    do
    { /*Bucle Principal de Juego para ambos jugadores*/
        // jugador1 mecanica tres en raya normal
        
        do
        { /*Bucle de Turno para el Jugador 1*/
            cout << "\n";
            cout << "----------------JUGADOR |"<< player1 <<"|----------------" << endl;
            tablero();
            cout << "\n";

            elecfilacolumna(false,false);

            // Bloque de  posicionamiento de Ficha
            /*Este bucle lee y verifica si la casilla ingresada esta bloqueada o no para pdoer colocar la respectiva X*/
            if (bloqueo[fila1][columna1] != '*')
            {
                /*Esta condicion agrega un + a la matriz de la carta bloqueo para un uso posterior de esta*/
                cout << "\n";
                cout << "La |"<< player1 <<"| fue colocada" << endl;
                tabla[fila1][columna1] = {player1};
                bloqueo[fila1][columna1] = {'+'};
                cout << "\n";
            }
            else
            {
                cout << "\n";
                cout << "CASILLA BLOQUEADA :(" << endl;
                tabla[fila1][columna1] = {'-'};
                bloqueo[fila1][columna1] = {'-'};
                cout << "\n";
                casilla_bloqueada = true;
            }

            /*Este bucle imprime el tablero actual de juego*/
            tablero();
            cout << "\n";
            ganador();
            //cout << ganar << endl;
            if (ganar != 1)
            {
                
                
                ganador();

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
                    if (casilla_bloqueada == true)
                    {
                        cout << "CASILLA BLOQUEADA :(" << endl;
                        cout << "PIERDES LA CARTA :(" << endl;
                        karta = 0;
                    }
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
                    
                    ezcudo(false);
                    if (proteccion == 1)
                    {
                        tabla[fila1][columna1] = {'-'};
                        bloqueo[fila1][columna1] = {'-'};
                    }
                    proteccion = 1;
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
                        tablero();
                        /*Aqui pregunta donde desea su respectiva*/
                        cout << "\n";
                        cout << "Elije una casilla para robar la |" << player2 << "| de tu oponente" << endl;
                        
                        elecfilacolumna(false,true);
                        
                        /*Esta linea verifica si una casilla esta protegida otra de las cartas qeu se explicara despues*/
                        
                        ezcudo(false);
                        if (proteccion == 1)
                        {
                            tabla[fila1][columna1] = player1;
                        }
                        proteccion = 1;
                        tablero();
                    }
                    else
                    {
                        cout << "MALA SUERTE!!!!" << endl;
                        cout << "Aun no hay ningun |" << player2 << "| que robar" << endl;
                        cout << "PIERDES LA CARTA :(" << endl;
                    }
                    cout << "\n";
                    ganador();
                }
                else if (karta == 3)
                {
                    // ESCUDO
                    /*Esta carta escudo permite al jugador defender su ultima X puesta o O dependiendo del jugador que este en su turno*/
                    
                    ezcudo(true);
                }
                else if (karta == 4)
                {
                    // BLOQUEO
                    /*Esta carta permite poner un bloqueo en una casilla para que el otro jugador no pueda poner su X o O respectivamente*/
                    cout << "BLOQUEO!!!!" << endl;
                    cout << "\n";
                    cout << "Elije una casilla para bloquear a tu oponente" << endl;

                    
                    elecfilacolumna(true,false);
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
                ganador();
                karta = 0;
            }

        } while (salida == false); /*Complemento del bucle Do-While de arriba el que maneja el bucle del jugador 1*/

       
        p3=player1;
        player1=player2;
        player2=p3;
        

    } while (ganar != 1);

    cout << "\n";
    system("pause");
    // es una función para no cerrar automáticamente el cpp

}

void reglas()
{

    system("cls");

    titulo();

    cout << "===================================" << endl;
    cout << "           REGLAS" << endl;
    cout << "===================================" << endl;
    cout << "\n";

    cout << "El clasico Tres en Raya..." << endl;
    cout << "normal y tranquilo..." << endl;
    cout << "HASTA QUE APARECEN LAS CARTAS!!!" << endl;
    cout << "\n";

    cout << "Despues de cada turno deberas escoger" << endl;
    cout << "una de las 9 cartas misteriosas." << endl;
    cout << "Cada una puede cambiar el destino" << endl;
    cout << "de la partida en segundos." << endl;
    cout << "\n";

    cout << "===================================" << endl;
    cout << "      CARTAS ESPECIALES" << endl;
    cout << "===================================" << endl;
    cout << "\n";

    cout << "[1] ESCUDO!!!" << endl;
    cout << "Te protege del ROBO y de las explosiones." << endl;
    cout << "\n";

    cout << "[2] BOOM!!!" << endl;
    cout << "Tu ficha EXPLOTA y desaparece del tablero." << endl;
    cout << "Pero si tienes ESCUDO... sobrevives." << endl;
    cout << "\n";

    cout << "[3] ROBO!!!" << endl;
    cout << "Puedes colocar TU ficha en lugar" << endl;
    cout << "de la del oponente." << endl;
    cout << "No funciona contra ESCUDO." << endl;
    cout << "\n";

    cout << "[4] BLOQUEO!!!" << endl;
    cout << "Bloquea una casilla e impide que" << endl;
    cout << "el oponente juegue ahi." << endl;
    cout << "\n";

    cout << "[5] DOBLE TURNO!!!" << endl;
    cout << "Obtienes un turno extra." << endl;
    cout << "Aprovechalo sabiamente." << endl;
    cout << "\n";

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

void tablero()
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "  c1  c2  c3 " << endl;
        }
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

void elecfilacolumna(bool bloq, bool rob)
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
            if(error == false){
                cout << "CASILLA VALIDA :)" << endl;
            }
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

void ganador()
{
    // Ganar filas
    /*Este bucle verifica si hay tres X o O en una fila para activar la win por parte del jugador correspondiente para ello recorre cada fila
    con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la fila*/
    int enraya_player1 = 0, enraya_player2 = 0;
    if (ganar !=1){
        for (int i = 0; i < 3; i++)
        {
            enraya_player1 = 0;
            enraya_player2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if (aux == player1)
                {
                    enraya_player1 += 1;
                    enraya_player2 = 0;
                }
                else if (aux == player2)
                {
                    enraya_player2 += 1;
                    enraya_player1 = 0;
                }
            }
            if (enraya_player1 == 3)
            {
                cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
                ganar = 1;
                salida = true;
                break;
            }
            else if (enraya_player2 == 3)
            {
                cout << "JUGADOR |" << player2 << "| GANA!!" << endl;
                ganar = 1;
                salida = true;
                break;
            }
            else
            {
                enraya_player1 = 0;
                enraya_player2 = 0;
            }
        }
    }
    // Ganar Columnas
    /*Este bucle verifica si hay tres X o O en una columna para activar la win por parte del jugador correspondiente para ello recorre cada columna
    de manera similar al de las filas pero con los elementos invertidos y con un contador el cual empieza en cero y suma mas 1 si esque detecta una X o O en la columna*/
    if (ganar !=1){
        for (int i = 0; i < 3; i++)
        {
            enraya_player1 = 0;
            enraya_player2 = 0;
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[j][i];
                if (aux == player1)
                {
                    enraya_player1 += 1;
                    enraya_player2 = 0;
                }
                else if (aux == player2)
                {
                    enraya_player2 += 1;
                    enraya_player1 = 0;
                }
            }
            if (enraya_player1 == 3)
            {
                cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
                ganar = 1;
                salida = true;
                break;
            }
            else if (enraya_player2 == 3)
            {
                cout << "JUGADOR |" << player2 << "| GANA!!" << endl;
                ganar = 1;
                salida = true;
                break;
            }
            else
            {
                enraya_player1 = 0;
                enraya_player2 = 0;
            }
        }
    }
    // Ganar Diagonal
    /*Este bucle verifica si hay tres X o O en la diagonal principal para activar la win por parte del jugador correspondiente para ello recorre un bucle
    verificando las entradas con nuemero similar si poseen una X o un O  para activar la win por el jugador correspondiente*/

    /*Diagonal principal*/
    if (ganar !=1){
        for (int i = 0; i < 3; i++)
        {
            if (tabla[i][i] == player1)
            {
                enraya_player1++;
            }

            if (tabla[i][i] == player2)
            {
                enraya_player2++;
            }
        }
            
        if (enraya_player1 == 3)
        {
            cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
            ganar = 1;
            salida = true;
        }
        else if (enraya_player2 == 3)
        {
            cout << "JUGADOR |" << player2 << "| GANA!!" << endl;
            ganar = 1;
            salida = true;

        }
        else
        {
            /*Reinicio de contadores*/
            enraya_player1 = 0;
            enraya_player2 = 0;
        }
        /*Diagonal secundaria*/
        for (int i = 0; i < 3; i++)
        {
            if (tabla[i][2 - i] == player1)
            {
                enraya_player1++;
            }

            if (tabla[i][2 - i] == player2)
            {
                enraya_player2++;
            }
        }
    }
    if (ganar !=1){
        if (enraya_player1 == 3)
        {
            cout << "JUGADOR |" << player1 << "| GANA!!" << endl;
            ganar = 1;
            salida = true;
        }
        else if (enraya_player2 == 3)
        {
            cout << "JUGADOR |" << player2 << "| GANA!!" << endl;
            ganar = 1;
            salida = true;
        }
        else
        {
            enraya_player1 = 0;
            enraya_player2 = 0;
        }
    }
    // EMPATE
    /*Aqui verifica el empate lo hace mediante un bucle que recorre cada fila con un contador que suma 1 siempre que vea un "-" ya que eso indica
    que la casilla esta vacía o esta llena en caso el contador no sume aunque sea 1 esta dira que es un empate*/
    int contador_empate = 0;
    if (ganar !=1){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                aux = tabla[i][j];
                if (aux == '-')
                {
                    contador_empate += 1;
                }
            }
        }
        if (((enraya_player1 == 0) or (enraya_player2 == 0)) and (contador_empate == 0))
        {
            cout << "EMPATE!!" << endl;
            ganar = 1;
            salida = true;
        }
        else
        {
            contador_empate = 0;
        }
    }

}

void ezcudo(bool escudo_activo)
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
