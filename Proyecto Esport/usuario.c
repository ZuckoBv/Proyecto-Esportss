#include "usuario.h"


void sistemaUsuario()
{
    int num=-1;
    char nombreArchivoUsuario[]="usuario.bin";
    while(num!=0)
    {
        printf("\n========================================");
        printf("\n          SISTEMA DE USUARIOS");
        printf("\n========================================");
        printf("\n");
        printf("\n  [1]  Cargar nuevo usuario");
        printf("\n  [2]  Mostrar usuarios");
        printf("\n");
        printf("\n  [0]  Salir");
        printf("\n");
        printf("\n========================================");
        printf("\n  Seleccione una opcion: ");
        scanf("%d", &num);

        switch(num)
        {
        case 1:
            cargarUsuarioArchivo(nombreArchivoUsuario);
            break;
        case 2:
            mostrarUsuarioArchivo(nombreArchivoUsuario);
            break;
        }

    }
}

void leerString(char arreglo[],int dim)
{
    fgets(arreglo,dim,stdin);
    arreglo[strcspn(arreglo,"\n")]='\0';
}

Persona cargarPersona()
{
    Persona a;
    printf("\nIngrese el DNI: ");
    while (getchar() != '\n');
    leerString(a.dni,15);
    printf("\nIngrese el Nombre: ");
    leerString(a.nombre,50);
    printf("\nIngrese el Telefono: ");
    leerString(a.telefono,20);
    printf("\nIngrese la Direccion: ");
    leerString(a.direccion,30);
    printf("\nIngrese el Rol: ");
    leerString(a.rol,15);
    return a;
}

Usuario cargarUsaurio()
{
    Usuario u;
    u.persona=cargarPersona();
    printf("\nIngrese un nombre de usuario: ");
    leerString(u.usuario,20);
    printf("\nIngrese una contrasenia: ");
    leerString(u.contrasenia,20);
    return u;
}

void cargarUsuarioArchivo(char nombreArchivo[])
{
    char letra='s';
    Usuario a;
    FILE * buffer=fopen(nombreArchivo,"ab");
    if(buffer==NULL)
    {
        printf("\nEl archivo no abrio");
        return;
    }
    //trabajo
    while(letra=='s')
    {
        a=cargarUsaurio();
        fwrite(&a,sizeof(Usuario),1,buffer);
        printf("\nDesea seguir cargando usuarios s/n? ");
        scanf(" %c", &letra);
        system("pause");
        system ("cls");
    }

    //fin
    fclose(buffer);
}

void mostrarUsuario(Usuario a)
{
    printf("\n");
    printf("  +------------------------------------------+\n");
    printf("  |              DATOS DEL USUARIO           |\n");
    printf("  +------------------------------------------+\n");
    printf("  |                                          |\n");
    printf("  |  > Usuario:   %s\n", a.usuario);
    printf("  |  > Nombre:    %s\n", a.persona.nombre);
    printf("  |  > DNI:       %s\n", a.persona.dni);
    printf("  |  > Telefono:  %s\n", a.persona.telefono);
    printf("  |  > Direccion: %s\n", a.persona.direccion);
    printf("  |  > Rol:       %s\n", a.persona.rol);
    printf("  |                                          |\n");
    printf("  +------------------------------------------+\n");
}


void mostrarUsuarioArchivo(char nombreArchivo[])
{
    Usuario a;
    FILE *buffer = fopen(nombreArchivo, "rb");
    if(buffer == NULL)
    {
        printf("\nEl archivo no abrio correctamente");
        return;
    }
    //trabajo
    while(fread(&a,sizeof(Usuario),1,buffer)==1)
    {
        mostrarUsuario(a);

    }
    system("pause");
    system("cls");
    //fin
    fclose(buffer);
}
