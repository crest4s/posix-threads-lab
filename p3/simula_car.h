#ifndef SIMULAR_CAR_H
#define SIMULAR_CAR_H

#include <pthread.h>
#define N_COCHES 8

// Tipo de datos que representa un coche
typedef struct
{
	int id;
	char *cadena;
} coche_t;

//Variables globales
extern coche_t Coches[N_COCHES];
extern volatile int clasificacionFinal[N_COCHES];
extern volatile int finalCarrera;

// Mutex para controlar el acceso a la clasificación
extern pthread_mutex_t mutexClasificacion;

// Prototipos de funciones 
void *funcion_coche(coche_t *pcoche);

#endif // CARRERA_COCHES_H
