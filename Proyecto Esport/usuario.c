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
        printf("\n  [3]  Modificar usuario");
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
        case 3:
            mostrarNombreUsuario(nombreArchivoUsuario);
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
    return a;
}

Usuario cargarUsaurio()
{
    Usuario u;
    u.persona=cargarPersona();
    printf("\nIngrese el ID del Usuario: ");
    leerString(u.idUsuario,15);
    printf("\nIngrese un nombre de usuario: ");
    leerString(u.usuario,20);
    printf("\nIngrese una contrasenia: ");
    leerString(u.contrasenia,20);
    return u;
}

void cargarUsuarioArchivo(char nombreArchivo[])
{
    int flag;
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
        flag=verificarId(nombreArchivo,a.idUsuario);
        while(flag==0)
        {
            printf("\nEl ID ya existe, ingrese uno nuevo: ");
            leerString(a.idUsuario,15);
            flag=verificarId(nombreArchivo,a.idUsuario);
        }
        fwrite(&a,sizeof(Usuario),1,buffer);
        printf("\nDesea seguir cargando usuarios s/n? ");
        scanf(" %c", &letra);

    }

    //fin
    fclose(buffer);
}

int verificarId(char nombreArchivo[],char idUsario[])
{
    Usuario a;
    FILE * buffer=fopen(nombreArchivo,"rb");
    if(buffer==NULL)
    {
        printf("\nError en el archivo");
        return 1;
    }
    //trabajo

    while(fread(&a,sizeof(Usuario),1,buffer)==1 )
    {
        if(strcmp(a.idUsuario,idUsario)==0)
        {
            fclose(buffer);
            return 0;
        }

    }
    //fin
    fclose(buffer);
    return 1;
}

void mostrarUsuario(Usuario a)
{
    printf("\n");
    printf("  +------------------------------------------+\n");
    printf("  |              DATOS DEL USUARIO           |\n");
    printf("  +------------------------------------------+\n");
    printf("  |                                          |\n");
    printf("  |  > ID Usuario:   %s\n", a.idUsuario);
    printf("  |  > Usuario:   %s\n", a.usuario);
    printf("  |  > Nombre:    %s\n", a.persona.nombre);
    printf("  |  > DNI:       %s\n", a.persona.dni);
    printf("  |  > Telefono:  %s\n", a.persona.telefono);
    printf("  |  > Direccion: %s\n", a.persona.direccion);
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


void mostrarNombreUsuario(char nombreArchivo[])
{
    Usuario a;
    int flag=0;
    char nickname[30];
    FILE * buffer=fopen(nombreArchivo,"r+b");
    if(buffer==NULL)
    {
        printf("\nEl archivo no abrio correctamente");
        return;
    }
    printf("\nTodo los usuarios son: ");
    while(fread(&a,sizeof(Usuario),1,buffer)>0)
    {
        printf("\n %s [%s]", a.usuario, a.idUsuario);
    }
    printf("\nElige el ID del usuario que desea modifica: ");
    while (getchar() != '\n');
    leerString(nickname,30);
    rewind(buffer);
    while(fread(&a,sizeof(Usuario),1,buffer)==1 && flag==0)
    {
        if(strcmp(nickname,a.idUsuario)==0)
        {
            fseek(buffer,sizeof(Usuario)*-1,1);
            a=cargarUsaurio();
            fwrite(&a,sizeof(Usuario),1,buffer);
            flag = 1;
        }

    }
    fclose(buffer);
}
