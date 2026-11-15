#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "modelos.h"

void cargarAdministrador(char nombreArchivo[]);
int autenticarAdmin(char nombreArchivo[]);
Administrador cargarAdministrador();
void guardarAdministrador(Administrador a, char nombreArchivo[]);
int autenticarAdmin(char nombreArchivo[]);

#endif // ADMIN_H_INCLUDED
