/*
 Integrantes:
 Juan Diego Lozada Gonzalez
 Alejandro Mora
 Nicolas Romero
 Fecha: 14/12/2022
 EMPAREJAMIENTO DE RECURSOS HUMANOS
 */
#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream> //lIBRERIA PARA LOS FICHEROS (CONTIENE LAS FUNCIONES ofstream, ifstream, fstream)
#define USERD "BUSCOEMPLEO"
#define CLAVED "12345"
#define USERE "ADMIN"
#define CLAVE "09876"

using namespace std;

typedef struct
{
    char nombreUsuario[30];
    char contrasenaUsuario[30];
    char nombre[20];
    char primerApellido[20];
    char segundoApellido[20];
    int edad;
    char educacion[20];
    char areadetrabajo[20];
    char experiencia[150]; // aqui que ponga la descripci�n

} demandante;

typedef struct
{
    char nombreUsuario[30];
    char contrasenaUsuario[30];
    char nombreEmpresa[20];
    char sector[20];
    char ubicacion[20];
    int cantidadEmpleados;
    char localizacion[20];
  
} empleador;

typedef struct
{
    char puesto[30];
    char empresa[30];
    char ubicacionPuesto[30];
    char correoContacto[30];
    char descripcionEmpleo[160];
} empleo;

/*funciones del archivo*/

void menu(void);
void login(void);
void registro(void);
void menuEmpleadores(void);
void menuDemandante(void);
void registrarPerfilDemandante(void);
void registrarPerfilEmpleador(void);
void crearEmpleo(void);
void borrarOferta(void);
void listaEmpleosComoDemandante(void);
void listaEmpleosComoEmpleador(void);
void encontrarVacantes(void);
// funciones para login
void loginDemandantes(void);
void loginEmpleadores(void);


int main()
{	
	setlocale(LC_ALL, "spanish");
    // Esta orden permite los caracteres especiales
    cout << "\t\t***BIENVENIDO***\nEste programa hace el emparejamiento de Recursos Humanos" << endl;
    _getch();
    system("cls"); // limpia la terminal

    menu(); // Abre opciones de registro acceso y salida
}

// FUNCIONES

void menu(void)
{
    system("cls");
    int tipo;
    cout << "Bienvenido al menu principal, seleccione una opcion para proseguir:\n1) Registrarse\n2) Acceder\n3) Salir" << endl;
    cout << "\nEsperando opcion: ";
    cin >> tipo;
    while (tipo < 1 || tipo > 3) // Se valida la opcion
    {
        cout << "Porfavor digite una opcion valida: " << endl;
        cin >> tipo;
    }
    switch (tipo)
    {
    case 1:
        system("cls");
        registro(); // LLama a la funcion registro donde se despliegan las opciones de registro como demandante o empleador
        break;
    case 2:
        system("cls");
        login(); // llama a la funcion login que tiene las opciones de acceder como demandante o empleador
        break;
    case 3:
        cout << "Gracias por usar nuestro servicio" << endl;
        getch();
        exit(0);
        break;
    }
}

void registro(void)
{
    int tipo;
    system("cls");
    cout << "�Como desea registrarse?: \n1) Demandante\n2) Empleador\n3) Volver" << endl;
    cin >> tipo;
    cin.ignore();
    while (tipo < 1 || tipo > 3) // Se valida la opcion
    {
        cout << "Porfavor digite una opcion valida:" << endl;
        cin >> tipo;
    }
    switch (tipo)
    {
    case 1:
        registrarPerfilDemandante();
        break;
    case 2:
        registrarPerfilEmpleador();
        break;
    case 3:
        menu();
        break;
    }
}

void registrarPerfilDemandante(void)
{
    ofstream fichUsuariosDemandantes; // Creacion de fichero para almacenar usuarios y contrasenas
    demandante datos;
    fichUsuariosDemandantes.open("usuariosDemandantes.dat", ios::app | ios ::binary); // Abrir fichero que se usara para almacenar los usuarios y contrasenas
    if (fichUsuariosDemandantes.fail())
    {
        cout << "A ocurrido un error\n";
        exit(EXIT_FAILURE);
    }
    else
    {

        // Datos del demandante
        fflush(stdin);
        system("cls");
        cout << "\tBienvenido al registro para demandantes de empleo." << endl;
        cout << "\tA continuacion rellene los siguientes campos." << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Escriba su nombre: ";
        cin.getline(datos.nombre, 20);
        cout << "Escriba su primer apellido: ";
        cin.getline(datos.primerApellido, 20);
        cout << "Escriba su segundo apellido: ";
        cin.getline(datos.segundoApellido, 20);
        cout << "Escriba su edad: ";
        cin >> datos.edad;
        cin.ignore();
        cout << "Escriba su nivel de educación: ";
        cin.getline(datos.educacion, 20);
        cout << "¿En cu�l �rea de trabajo se desempeña? ";
        cin.getline(datos.areadetrabajo, 20);
        fflush(stdin);
        cout << "Describase en 20 palabras: ";
        cin.getline(datos.experiencia, 150);
        fichUsuariosDemandantes.write((char *)&datos, sizeof(demandante)); // Almacenamos el usuario y su contraseña
        fichUsuariosDemandantes.close();
    }
    cout << "\t\nEl usuario se ha registrado existosamente\nSera redirigido al menu principal, para continuar presione enter:" << endl;
    _getch();
    system("cls");
    menu();
}

void registrarPerfilEmpleador()
{
    ofstream fichUsuariosEmpleadores; // Creacion de fichero para almacenar usuarios y contrasenas (Empleadores)
    empleador datos;
    fichUsuariosEmpleadores.open("usuariosEmpleadores.dat", ios::app | ios ::binary); // Abrir fichero que se usara para almacenar los usuarios y contrasenas
    if (fichUsuariosEmpleadores.fail())
    {
        cout << "A ocurrido un error\n";
        exit(EXIT_FAILURE);
    }
    else
    {

        // Datos del empleador
        fflush(stdin);
        system("cls");
        cout << "\tBienvenido al sistema de registro de empleadores." << endl;
        cout << "\tA continuacion rellene los siguientes campos." << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Nombre de Nombre de la empresa: ";
        cin.getline(datos.nombreEmpresa, 20);
        cin.ignore();
        cout << "Escriba el sector: ";
        cin.getline(datos.sector, 20);
        cout << "Donde se ubica la empresa: ";
        cin.getline(datos.ubicacion, 20);
        cout << "Cantidad de empleados actualmente en la empresa : ";
        cin >> datos.cantidadEmpleados;
        cin.ignore();
        while (datos.cantidadEmpleados < 0)
        {
            cout << "Digite un valor positivo\nCuantos empleados tiene actualmente la empresa : ";
            cin >> datos.cantidadEmpleados;
        }
        cout << "Escriba la dirección donde se ubica:";
        cin.getline(datos.localizacion, 20);

        fichUsuariosEmpleadores.write((char *)&datos, sizeof(empleador)); // Almacenamos el usuario y su contraseña
        fichUsuariosEmpleadores.close();
    }
    cout << "\t\nEl usuario se ha registrado existosamente\nSera redirigido al menu principal, para continuar presione enter:" << endl;
    _getch();
    system("cls");
    menu();
}

void login(void)
{
    system("cls");
    int acceso;
    cout << "\tBienvenido al modo de acceso, porfavor tenga en cuenta la siguiente informacion:\n\n1)Acceder como demandante\n2)Acceder como empleador\n3)Volver" << endl;
    cout << "\n\nEsperando opcion: ";
    cin >> acceso;
    while (acceso < 1 || acceso > 3)
    {
        cout << "Porfavor digite una opcion valida:" << endl;
        cin >> acceso;
    }
    switch (acceso)
    {
    case 1:
        system("cls");
        loginDemandantes();
        break;
    case 2:
        system("cls");
        loginEmpleadores();
        break;
    case 3:
        system("cls");
        menu();
        break;
    }
}

void loginDemandantes(void)
{

    string usuario, password;
    int k;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t   LOGIN DE USUARIO PARA DEMANDANTES DE EMPLEO" << endl;
        cout << "\t-------------------------------------------------" << endl;
        cout << "Usuario: ";
        cin >> usuario; // Pide usuario (USER)

        cout << "Contraseña: ";
        char caracter; // Pide clave (CLAVE)
        caracter = _getch();

        password = "";

        while (caracter != 13)
        {
            password.push_back(caracter);
            cout << "*";
            caracter = _getch();
        }

        if (usuario == USERD && password == CLAVED)
        { // valida que sean correctos el usuario y la clave
            ingresa = true;
            system("cls");
            cout << "\tBIENVENIDO AL SISTEMA" << endl; // si el condicional es valido
            cout <<"\nPresione enter para continuar: ";
            getch();
            menuDemandante();
        }
        else
        {
            cout << "\nDatos incorrectos" << endl;                                    // si el condicional NO es valido
            cout << "¿Desea volver a intentarlo? (1 si, otro número volver a intentar)" << endl; // retorno
            cin >> k;
            if (k != 1)
            {
                system("cls");
                login();
            }
        }

    } while (ingresa == false);

    cin.get();
}

void loginEmpleadores(void)
{

    string usuario, password;
    int k;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t   LOGIN DE USUARIO PARA EMPLEADORES" << endl;
        cout << "\t---------------------------------------" << endl;
        cout << "Usuario: ";
        cin >> usuario; // Pide usuario (USER)

        cout << "Contraseña: ";
        char caracter; // Pide clave (CLAVE)
        caracter = _getch();

        password = "";

        while (caracter != 13)
        {
            password.push_back(caracter);
            cout << "*";
            caracter = _getch();
        }

        if (usuario == USERE && password == CLAVE)
        { // valida que sean correctos el usuario y la clave
            ingresa = true;
            system("cls");
            cout << "\tBIENVENIDO AL SISTEMA" << endl; // si el condicional es valido
            cout << "Presione enter para continuar: ";
            getch();
            menuEmpleadores();
        }
        else
        {
            cout << "\nDatos incorrectos" << endl;                                    // si el condicional NO es valido
            cout << "¿Desea volver a intentarlo? (1 si, otro número volver a intentar)" << endl; // retorno
            cin >> k;
            if (k != 1)
            {
                system("cls");
                login();
            }
        }

    } while (ingresa == false);

    cin.get();
}

void crearEmpleo(void)
{
    ofstream vacanteEmpleo; // creaci�n del fichero para guardar las vacantes
    empleo vacante;
    vacanteEmpleo.open("vacantes.dat", ios::app | ios::binary); // Abre el fichero donde se guardan las vacantes
    if (vacanteEmpleo.fail())
    {
        cout << "A ocurrido un error\n";
        getch();
        exit(EXIT_FAILURE);
    }
    else
    {
        fflush(stdin);
        cin.ignore();
        system("cls");
        cout << "\t Bienvenido al registro de vacantes" << endl;
        cout << "\tA continuacion rellene los siguientes campos." << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Nombre del puesto: ";
        cin.getline(vacante.puesto, 30);
        cout << "Nombre de la empresa: ";
        cin.getline(vacante.empresa, 30);
        cout << "Ubicacion de la empresa: ";
        cin.getline(vacante.ubicacionPuesto, 30);
        cout<<  "Correo de contacto: ";
        cin.getline(vacante.correoContacto,30);
        cout << "Descripcion del empleo (Maximo 160 caracteres)):" << endl;
        cin.getline(vacante.descripcionEmpleo, 160);
        vacanteEmpleo.write((char *)&vacante, sizeof(empleo)); // Almacena los datos
    }
    vacanteEmpleo.close();
}

void borrarOferta()
{
    FILE *fp, *fd;
    empleo aux;
    int encontrado = 0;
    char puesto[30];

    cout<<"Introduce el nombre de la vacante a borrar: ";
    cin.ignore();
    cin.getline(puesto, 30);

    fp = fopen("vacantes.dat", "rb");
    if (!(fp)){
        cout<<"\n A ocurrido un error\n";
        getch();
    }
        
    else
    {
        fd = fopen("backUp.$$$", "wb");
        if (!(fd))
        {
            cout<<"\n A ocurrido un error\n";
            getch();
        }
        else
        {
            while ((fread(&aux, sizeof(aux), 1, fp)) != 0)
                if (stricmp(aux.puesto, puesto) != 0)
                    fwrite(&aux, sizeof(aux), 1, fd);
                else
                    encontrado = 1;
            fclose(fd);
        }
        fclose(fp);
        if (encontrado)
        {
            system("del vacantes.dat");
            system("ren backUp.$$$ vacantes.dat");
            printf("\n La vacante se ha borrado con exito\n");
        }
        else
        {
            system("del backUp.$$$");
            printf("\n Vacante inexistente");
        }
    }
}

void menuEmpleadores(void)
{
    int opcion;
    do
    {
        system("cls");
        cout << "\tBienvenido actualemente su cuenta es de tipo empleador, tenga en cuenta la siguiente información:\n\n1) Añadir vacante de empleo\n2) Borrar vacantes\n3) Ver vacantes\n4) Volver al menu de acceso"<<endl;
        cout << "\nEsperando opcion: ";
        cin >> opcion;
        while (opcion < 1 || opcion > 6)
        { // Validador de opciones
            cout << "Porfavor digite una opcion valida:" << endl;
            cin >> opcion;
        }
        switch (opcion)
        {

        case 1:
            // agregar
            crearEmpleo();
            break;

        case 2:
            // eliminar
            borrarOferta();
            break;

        case 3:
            // ver
            listaEmpleosComoEmpleador();
            break;
        case 4:
            login();
            break;
        }
        if (opcion < 6)
        {
            cout << "\n\nPresiona Cualquier Tecla para Regresar al Menu";
            getch();
        }
    } while (opcion != 6);
}

void menuDemandante(void)
{
    int opcion;
    do
    {
        system("cls");
        cout << "\tBienvenido actualemente su cuenta es de tipo demandante de empleo, tenga en cuenta la siguiente información\n\n1) Ver vacantes\n2) Buscar vacantes\n3) Volver al menu de acceso"<<endl;
        cout << "\nEsperando opcion: ";
        cin >> opcion;
        while (opcion < 1 || opcion > 3)
        { // Validador de opciones
            cout << "Porfavor digite una opcion valida: " << endl;
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            // ver vacantes
            listaEmpleosComoDemandante();
            break;
        case 2:
            // Buscar vacante segun el interes
            encontrarVacantes();
            break;
        case 3:
            login();
            break;
        }

    } while (opcion != 3);
}

void listaEmpleosComoDemandante(void)
{
    FILE *fp;
    int i = 1;
    empleo aux;
    fp = fopen("vacantes.dat", "rb");
    if (!(fp))
    {
        cout << "A ocurrido un error";
        getch();
        exit(1);
    }
    else
    {
        system("cls");
        printf("\n\t E M P L E O S  D I S P O N I B L E S\n");
        printf("-------------------------------------------------------------------------\n");
        while ((fread(&aux, sizeof(aux), 1, fp)) != 0)
        {
            cout << "\nVacante necesitada: " << aux.puesto << "\n\nEmpresa: " << aux.empresa << "\n\nUbicacion: " << aux.ubicacionPuesto << "\n\nCorreo de contacto: "<<aux.correoContacto<< endl;
            cout << "\n\n\t\tDESCRIPCION" << endl
                 << aux.descripcionEmpleo << endl;
            i++;
            printf("\n-------------------------------------------------------------------------\n");
        }
        cout << "Presione una tecla para volver: ";
        getch();
        fclose(fp);
        menuDemandante();
    }
}
void listaEmpleosComoEmpleador(void)
{
    FILE *fp;
    int i = 1;
    empleo aux;
    fp = fopen("vacantes.dat", "rb");
    if (!(fp))
    {
        cout << "A ocurrido un error";
        getch();
        exit(1);
    }
    else
    {
        system("cls");
        printf("\n\t E M P L E O S  D I S P O N I B L E S\n");
        printf("-------------------------------------------------------------------------\n");
        while ((fread(&aux, sizeof(aux), 1, fp)) != 0)
        {
            cout << "\nVacante necesitada: " << aux.puesto << "\n\nEmpresa: " << aux.empresa << "\n\nUbicacion: " << aux.ubicacionPuesto << "\n\nCorreo de contacto: " << aux.correoContacto << endl;
            cout << "\n\n\t\tDESCRIPCION" << endl
                 << aux.descripcionEmpleo << endl;
            i++;
            printf("\n-------------------------------------------------------------------------\n");
        }
        cout << "Presione una tecla para volver: ";
        getch();
        fclose(fp);
        menuEmpleadores();
    }
}
void encontrarVacantes(void)
{
    system("cls");
    FILE *fp;
    empleo aux;
    int n;
    char puesto[30];

    cout<<"\tBIENVENIDO A NUESTRO SISTEMA DE BUSQUEDA\n\nPorfavor digite el nombre de la vacante que deseas buscar"<<endl;
    cout<<"\nVacante: ";
    cin.ignore();
    cin.getline(puesto, 30);

    fp = fopen("vacantes.dat", "rb");
    if (!(fp)){
        cout<<"\n A ocurrido un error\n";
        getch();
    }
        
    else
    {
        while ((n = fread(&aux, sizeof(aux), 1, fp)) != 0 && stricmp(aux.puesto, puesto) != 0)
            ;
        if (n == 0){
            cout << "\nLamentablemente no hay vacantes con el puesto que busca :(";
            getch();
        }    
        else
        {
            cout<<"\n\tV A C A N T E  E N C O N T R A D A";
            cout<<"\n-------------------------------------------------------------------------\n";
            cout << "\nVacante necesitada: " << aux.puesto << "\n\nEmpresa: " << aux.empresa << "\n\nUbicacion: " << aux.ubicacionPuesto << "\n\nCorreo de contacto: " << aux.correoContacto << endl;
            cout << "\n\t\tDESCRIPCION" << endl
                 << aux.descripcionEmpleo << endl;
            cout << "\n-------------------------------------------------------------------------\n";
            cout << "Presione una tecla para volver: ";
            getch();
        }
    }
}
// FIN DE LAS FUNCIONES

// Ejecutar programa: Ctrl + F5 o menÃƒÆ’Ã‚Âº Depurar > Iniciar sin depurar
// Depurar programa: F5 o menÃƒÆ’Ã‚Âº Depurar > Iniciar depuracón

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de cÃƒÆ’Ã‚Â³digo fuente
//   3. Use la ventana de salida para ver la salida de compilacón y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de cÃƒÆ’Ã‚Â³digo, o a Proyecto > Agregar elemento existente para agregar archivos de cÃƒÆ’Ã‚Â³digo existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
