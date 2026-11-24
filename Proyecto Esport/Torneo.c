#include "Torneo.h"
#include "Usuario.h"
#include "gestionvideojuegos.h"
#include <string.h>
void sistemaTorneo()
{
    int opcion;
    int valido = 0;
    Torneo torneo;

    do
    {

        printf("\n  [1]  Cargar nuevo torneo ");
        printf("\n  [2]  Modificar torneo");
        printf("\n  [3]  Mostrar todos los torneos ");
        printf("\n  [4]  Mostrar torneos activos ");
        printf("\n  [5]  Mostrar jugadores de un torneo ");
        printf("\n  [6]  Mostrar torneos llenos ");
        printf("\n========================================");
        printf("\n              REPORTES");
        printf("\n========================================");
        printf("\n ");
        printf("\n  [7]  Reporte: Torneos por videojuego");
        printf("\n  [0]  Salir");
        printf("\n");
        printf("\n========================================");
        printf("\n  Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            system("cls");
            cargarTorneoArchivo (ARCHIVOTORNEO, ARCHIVOVIDEOJUEGO);
            break;

        case 2:
            system("cls");
            mostrarTorneosArchivo (ARCHIVOTORNEO);

            printf ("Ingrese el ID del torneo a modificar: \n");
            while (getchar () != '\n');
            leerString (torneo.idTorneo, 10);
            valido = validarIdTorneo (ARCHIVOTORNEO, torneo.idTorneo);

            if (valido != 0)
            {
                printf ("ID incorrecto o error de archivo\n");
            }
            else
            {
                modificarTorneo (ARCHIVOTORNEO, ARCHIVOVIDEOJUEGO, torneo.idTorneo);
            }

            break;

        case 3:
            system("cls");
            mostrarTorneosArchivo (ARCHIVOTORNEO);
            break;
        case 4:
            mostrarTorneosActivos(ARCHIVOTORNEO);
            break;

        case 5:

            break;

        case 6:
            mostrarTorneosLlenosArchivo (ARCHIVOTORNEO);
            break;

            case 7:
            while (getchar()!='\n');
            reporteTorneosPorJuego(ARCHIVOTORNEO, ARCHIVOVIDEOJUEGO);
            break;


        case 0:
            return;
            break;

        default:
            printf ("\n Opcion invalida");
        }
    }
    while(opcion!=0);

}

Torneo crearTorneo(const char nombreArchivoTorneo [], const char nombreArchivoVideojuego[])
{
    Torneo torneo;
    int valido = 0;
    int juegoValido = 0;
    while (getchar() != '\n');

    while (valido == 0)
    {
        printf ("Ingrese el ID del torneo: \n");                   //Bucle para no repetir ID
        leerString (torneo.idTorneo, 10);
        valido = validarIdTorneo (nombreArchivoTorneo, torneo.idTorneo);
        if (valido == 0)
        {
            printf ("Ya existe ese ID \n");
        }
    }

    printf ("Ingrese el nombre del torneo: \n");
    leerString (torneo.nombre, 50);

    mostrarVideojuegosArchivo(nombreArchivoVideojuego);
    while (juegoValido != 1)
    {
        printf("Escriba el ID del videojuego a agregar: \n");
        leerString (torneo.juego.idJuego, 10);
        //Validar ID videojuego
        juegoValido = buscarVideojuegoPorId(nombreArchivoVideojuego, torneo.juego.idJuego, &torneo.juego);

        if (juegoValido == 0)
        {
            printf("Ese ID de videojuego no existe. Elija uno de la lista.\n");
        }
        else if (juegoValido == -1)
        {
            break;
        }
    }

    printf ("Ingrese la fecha: \n");
    printf ("  Dia: ");
    scanf ("%d", &torneo.fechaInicio.dia);
    printf ("  Mes:  ");
    scanf ("%d", &torneo.fechaInicio.mes);
    printf ("  Anio:  ");
    scanf ("%d",&torneo.fechaInicio.anio);

    printf ("\nIngrese la capacidad maxima: \n");
    scanf ("%d", &torneo.capacidadMaxima);
    printf ("Ingrese cantidad de cupos disponibles: \n");
    scanf ("%d", &torneo.cuposDisponibles);
    printf ("Ingrese el premio: \n");
    scanf ("%f", &torneo.premioTotal);
    while (getchar() != '\n');
    printf ("Estado del torneo: (Abierto, En Curso, Finalizado)\n");
    leerString (torneo.estado, 15);

    return torneo;
}

void cargarTorneoArchivo (const char nombreArchivoTorneo [], const char nombreArchivoVideojuego[])
{
    char letra = 's';
    Torneo torneo;

    while(letra == 's' || letra == 'S')
    {
        torneo = crearTorneo(nombreArchivoTorneo, nombreArchivoVideojuego);              //Creo torneo y valido ID

        FILE* archivo = fopen (nombreArchivoTorneo, "ab");
        if(archivo==NULL)
        {
            printf("\nEl archivo no abrio");                   //Abro archivo, guardo y cierro
            return;
        }
        fwrite(&torneo, sizeof(Torneo), 1, archivo);
        fclose(archivo);

        printf("\nDesea agregar mas torneos s/n? ");
        scanf(" %c", &letra);
    }
}

void mostrarTorneo (Torneo torneo)
{
    printf("\n========================================");
    printf ("\n ID: %s", torneo.idTorneo);
    printf ("\n Nombre: %s", torneo.nombre);
    printf ("\n Videojuego: %s (ID: %s)", torneo.juego.nombre, torneo.juego.idJuego);
    printf ("\n Fecha: %d|%d|%d ", torneo.fechaInicio.dia, torneo.fechaInicio.mes, torneo.fechaInicio.anio);
    printf ("\n Capacidad maxima del torneo: %d", torneo.capacidadMaxima);
    printf ("\n Cupos disponibles: %d", torneo.cuposDisponibles);
    printf ("\n Premio: $%.2f", torneo.premioTotal);
    printf ("\n Estado: %s", torneo.estado);
    printf("\n========================================");
}

void mostrarTorneosArchivo (const char nombreArchivoTorneo [])
{
    Torneo torneo;

    FILE* archivo = fopen (nombreArchivoTorneo, "rb");

    if (archivo == NULL)
    {
        printf ("Error al intentar abrir el archivo\n");
        return;
    }

    while (fread (&torneo, sizeof (Torneo), 1, archivo) == 1)
    {
        mostrarTorneo (torneo);
    }

    fclose (archivo);
}

int validarIdTorneo (const char nombreArchivoTorneo [], char idNuevoTorneo [] )
{
    Torneo torneo;

    FILE* archivo = fopen (nombreArchivoTorneo, "rb");

    if (archivo == NULL)
    {
        printf ("Error al intentar abrir el archivo\n");
        return 1;
    }

    while (fread (&torneo, sizeof (Torneo), 1, archivo) == 1)
    {
        if (strcmp (torneo.idTorneo, idNuevoTorneo) == 0)
        {
            fclose (archivo);
            return 0;
        }
    }

    fclose (archivo);
    return 1;
}

int buscarVideojuegoPorId(const char nombreArchivoVideojuego[], char idVideojuego[], Videojuego *juegoDestino)
{
    FILE* archivo = fopen(nombreArchivoVideojuego, "rb");

    if (archivo == NULL)
    {
        printf("Error al intentar abrir el archivo de videojuegos.\n");
        return -1;
    }

    Videojuego aux;
    while (fread(&aux, sizeof(Videojuego), 1, archivo) == 1)
    {
        if (strcmp(aux.idJuego, idVideojuego) == 0)
        {
            *juegoDestino = aux;
            fclose(archivo);
            return 1;
        }
    }

    fclose(archivo);

    return 0;
}

void modificarTorneo (const char nombreArchivoTorneo [], const char nombreArchivoVideojuego [], char idTorneo [])
{
    Torneo torneo;
    FILE* archivo = fopen (nombreArchivoTorneo, "r+b");
    int flag = 0;

    if (archivo==NULL)
    {
        printf("\nEl archivo no abrio");
        return;
    }

    while (fread (&torneo, sizeof(Torneo), 1, archivo) == 1 && flag == 0)
    {
        if (strcmp (idTorneo, torneo.idTorneo) == 0)
        {
            fseek (archivo, sizeof (Torneo)*-1,1);
            torneo = crearTorneo (nombreArchivoTorneo, nombreArchivoVideojuego);
            fwrite (&torneo, sizeof (Torneo), 1, archivo);
            flag = 1;
        }
    }

    fclose(archivo);
}


void mostrarTorneosActivos(const char nombreArchivoTorneo[])
{
    Torneo a;
    FILE * buffer=fopen(nombreArchivoTorneo,"rb");
    if (buffer==NULL)
    {
        printf("\nEl archivo no abrio");
        return;
    }
     while (fread (&a, sizeof (Torneo), 1, buffer) == 1)
    {
        if( strcmpi(a.estado, "Abierto") == 0 && a.cuposDisponibles>0)
        {
            mostrarTorneo(a);
        }

    }


    fclose(buffer);
}

void mostrarTorneosLlenosArchivo (const char nombreArchivoTorneo [])
{
    Torneo torneo;
    int encontrados = 0;

    FILE* archivo = fopen (nombreArchivoTorneo, "rb");

    if (archivo == NULL)
    {
        printf ("Error al intentar abrir el archivo\n");
        return;
    }

    while (fread (&torneo, sizeof (Torneo), 1, archivo) == 1)
    {
        if (torneo.cuposDisponibles == 0 && (strcmpi (torneo.estado, "Abierto") == 0 ||
                                                strcmpi (torneo.estado, "En curso") == 0))
        {
        mostrarTorneo (torneo);
        encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\nNo hay torneos llenos (abiertos o en curso).\n");
    }
    fclose (archivo);
}

int contarTorneosPorJuego(const char archivoTorneos[], const char archivoJuegos[], char idJuego[])
{
    int contador = 0;
    Videojuego juegoEncontrado;

    int existe = buscarVideojuegoPorId(archivoJuegos, idJuego, &juegoEncontrado);

    if (existe <= 0)
    {
        if (existe == 0)
        {
            printf("\nEl videojuego con ID '%s' no existe en el catalogo.\n", idJuego);
        }
        return -1;
    }

    FILE* archivo = fopen(archivoTorneos, "rb");
    if (!archivo)
    {
        printf("\nNo se pudo abrir el archivo de torneos.\n");
        return -1;
    }

    Torneo temp;

    while (fread(&temp, sizeof(Torneo), 1, archivo))
    {
        if (strcmp(temp.juego.idJuego, idJuego) == 0)
        {
            contador++;
        }
    }

    fclose(archivo);

    return contador;
}

void reporteTorneosPorJuego(const char archivoTorneos[], const char archivoJuegos[])
{
    char idJuego[10];
    Videojuego juego;

    printf("\n=== REPORTE DE ACTIVIDAD POR VIDEOJUEGO ===\n");
    printf("Ingrese el ID del videojuego (ej. LOL, CS2): ");
    fgets(idJuego, 10, stdin);
    idJuego[strcspn(idJuego, "\n")] = 0;

    int cantidad = contarTorneosPorJuego(archivoTorneos, archivoJuegos, idJuego);

    if (cantidad != -1)
    {
        buscarVideojuegoPorId(archivoJuegos, idJuego, &juego);
        printf("\nEl videojuego '%s' (%s) estuvo presente en %d torneo(s).\n",
               juego.nombre, idJuego, cantidad);
    }

}
