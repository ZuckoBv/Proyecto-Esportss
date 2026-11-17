#include "Login.h"
#include "Usuario.h"
#include "gestionvideojuegos.h"
#include "Torneo.h"
int main()
{
    cargarHardcodeadosAlArchivo();
    int validosLogin=login ();
     sistemaUsuario();
    sistemaTorneo();
    return 0;
}
