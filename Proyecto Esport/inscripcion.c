#include "inscripcion.h"
#include "torneo.h"
#include "usuario.h"
void administarInscripcion()
{
    int num = -1;
    char nombreArchivoTorneo[] = "torneo.bin";
    char nombreArchivoInscripcion[] = "inscripcion.bin";
    char nombreArchivoUsuario[]="usuario.bin";

    while(num != 0)
    {
        printf("\n========================================");
        printf("\n       SISTEMA DE INSCRIPCIONES");
        printf("\n========================================");
        printf("\n");
        printf("\n  [1]  Registrar una inscripcion");
        printf("\n  [2]  Ver inscripciones resumen");
        printf("\n");
        printf("\n  [0]  Salir");
        printf("\n");
        printf("\n========================================");
        printf("\n  Seleccione una opcion: ");
        scanf("%d", &num);

        switch(num)
        {
        case 1:
            registrarInscripcion(nombreArchivoInscripcion,nombreArchivoUsuario,nombreArchivoTorneo);
            break;
        case 2:
            mostrarInscripciones(nombreArchivoInscripcion,nombreArchivoUsuario,nombreArchivoTorneo);
            break;
        }

    }
}


void registrarInscripcion(char nombreArchivoInscripcion[],char nombreArchivoUsuario[],char nombreArchivoToreno[])
{
    Inscripcion a;
    FILE * buffer=fopen(nombreArchivoInscripcion,"ab");
    if(buffer==NULL)
    {
        printf("\nNo se abrio el archivo");
        return;
    }

    seleccionarUsuario(nombreArchivoUsuario, a.idUsuario);
    printf("%s", a.idUsuario);
    system("cls");
    printf("\n=======================================");
    printf("\n                  TORNEOS");
    printf("\n=======================================");
    seleccionarTorneo(nombreArchivoToreno, a.idTorneo);
    system("cls");
    printf("\nIngrese el ID de la inscripcion: ");
    while(getchar() != '\n');
    leerString(a.idInscripcion,10);
    fwrite(&a,sizeof(Inscripcion),1,buffer);
    fclose(buffer);
}

void seleccionarUsuario(char nombreArchivo[], char idUsuario[])
{
    char letra = 'n';
    Usuario a;
    int id;
    int encontrado = 0;
    FILE *buffer = fopen(nombreArchivo, "rb");
    if(buffer == NULL)
    {
        printf("\nNo se abrio el archivo");
        return;
    }
    while(letra == 'n')
    {
        mostrarUsuarioArchivo(nombreArchivo);
        printf("\nSeleccione un usuario por el ID: ");
        while(getchar() != '\n');
        scanf("%d", &id);
        rewind(buffer);
        encontrado = 0;
        while(fread(&a, sizeof(Usuario), 1, buffer) && encontrado == 0)
        {
            if(atoi(a.idUsuario) == id)
            {
                strcpy(idUsuario, a.idUsuario);
                encontrado = 1;
            }
        }
        if(encontrado == 1)
        {

            break;
        }
        else
        {
            printf("\nError en elegir el ID");
            printf("\nDesea salir s/n? ");
            scanf(" %c", &letra);
        }
    }

    fclose(buffer);
}

void seleccionarTorneo(char nombreArchivo[], char idTorneo[])
{
    int x;
    Torneo a;
    char letra = 'n';
    int id;
    int encontrado = 0;
    FILE *buffer = fopen(nombreArchivo, "rb");
    if(buffer == NULL)
    {
        printf("\nNo se abrio el archivo");
        return;
    }
    while(letra == 'n')
    {
        mostrarTorneosActivos(nombreArchivo);
        printf("\nSeleccione un Torneo por el ID: ");
        scanf("%d", &id);
        rewind(buffer);
        encontrado = 0;
        while(fread(&a, sizeof(Torneo), 1, buffer) && encontrado == 0)
        {
            if(atoi(a.idTorneo) == id)
            {
                strcpy(idTorneo, a.idTorneo);
                encontrado = 1;
            }
        }
        if(encontrado == 1)
        {
            x=descontarCupoTorneo(nombreArchivo,a.idTorneo);//xd
            break;
        }
        printf("\nError en elegir el ID");
        printf("\nDesea salir s/n? ");
        scanf(" %c", &letra);
    }

    fclose(buffer);
}

void mostrarInscripciones(char nombreArchivoInscripcion[],char nombreArchivoUsuario[],char nombreArchivoTorneo[])
{
    Torneo a;
    Usuario b;
    Inscripcion c;

    FILE *bufferInscripcion = fopen(nombreArchivoInscripcion, "rb");
    FILE *bufferUsuario = fopen(nombreArchivoUsuario, "rb");
    FILE *bufferTorneo = fopen(nombreArchivoTorneo, "rb");

    if(bufferInscripcion == NULL || bufferUsuario == NULL || bufferTorneo == NULL)
    {
        printf("\nNo se pudieron abrir los archivos");

        if(bufferInscripcion != NULL)
            fclose(bufferInscripcion);

        if(bufferUsuario != NULL)
            fclose(bufferUsuario);

        if(bufferTorneo != NULL)
            fclose(bufferTorneo);

        return;
    }

    while(fread(&a, sizeof(Torneo), 1, bufferTorneo)==1)
    {
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n========================================");
        printf("\n             TORNEO");
        printf("\n========================================");

        printf("\nID Torneo: %s", a.idTorneo);
        printf("\nNombre: %s", a.nombre);
        printf("\nJuego: %s", a.juego.nombre);
        printf("\nEstado: %s", a.estado);
        printf("\nPrecio Total: %.2f", a.premioTotal);

        printf("\n----------------------------------------");
        printf("\n             USUARIOS");
        printf("\n----------------------------------------");

        rewind(bufferInscripcion);

        while(fread(&c, sizeof(Inscripcion), 1, bufferInscripcion)==1)
        {

            if(strcmp(a.idTorneo, c.idTorneo) == 0)
            {
                rewind(bufferUsuario);

                while(fread(&b, sizeof(Usuario), 1, bufferUsuario)==1)
                {
                    if(strcmp(c.idUsuario, b.idUsuario) == 0)
                    {
                        printf("\nID Usuario: %s", b.idUsuario);
                        printf("\nUsuario: %s", b.usuario);
                        printf("\nID Inscripcion %s", c.idInscripcion);
                        printf("\n----------------------------------------");

                        break;
                    }
                }
            }
        }
        printf("\n");
        system("pause");
    }
    system("cls");
    fclose(bufferInscripcion);
    fclose(bufferUsuario);
    fclose(bufferTorneo);
}
