/*Haz una agenda usando un Arbol de búsqueda. Utiliza como estructura una
con los campos telefono y nombre por ejemplo y acuerdate de sobrecargar
los operandos de comparación de la estructura.*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"
#include "abb.h"

struct nodo{
	char nombre[30];
	char telefono[10];
	nodo(char nom[30], char tel[30]): 
	strcpy(nombre,nom),strcpy(telefono,tel){}
}

