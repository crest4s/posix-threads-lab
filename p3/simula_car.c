#include "simula_car.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Array de datos de tipo coche_t
coche_t Coches[N_COCHES];
volatile int clasificacionFinal[N_COCHES];
volatile int finalCarrera = 0;

// Mutex para controlar el acceso a la clasificacion
pthread_mutex_t mutexClasificacion = PTHREAD_MUTEX_INITIALIZER;

// Funcion ejecutada por los hilos
void *funcion_coche(coche_t *pcoche)
{
    int aleatorio;
    unsigned int semilla = (pcoche->id) + pthread_self(); // semilla generacion num. aleatorios

    printf("Salida de %s %d\n", pcoche->cadena, pcoche->id);
    
    fflush (stdout);

    // generar numero aleatorios con funcion re-entrante rand_r()    
    aleatorio = rand_r(&semilla) % 10;

    sleep(aleatorio);
 
    printf("Llegada de %s %d\n", pcoche->cadena, pcoche->id);

    /* CODIGO 4 */

    pthread_mutex_lock(&mutexClasificacion);
    clasificacionFinal[finalCarrera++] = pcoche->id;
    pthread_mutex_unlock(&mutexClasificacion);

    /* CODIGO 2 */
    pthread_exit(NULL);
}


int main(void)
{
    pthread_t hilosCoches[N_COCHES]; // tabla con los identificadores de los hilos
    int i;
    
    printf("Se inicia proceso de creacion de hilos...\n\n");
    printf("SALIDA DE COCHES\n");
    
    for (i=0; i<N_COCHES; i++)
    {
        
        /* CODIGO 1 */
        Coches[i].id = i;
        Coches[i].cadena = (char *)malloc(20* sizeof(char));
        snprintf(Coches[i].cadena, 20, "Coche_%d", i);

        if (pthread_create(&hilosCoches[i], NULL, (void*(*)(void *))funcion_coche, (void *)&Coches[i]) != 0)
       	{
            perror("Error al crear el hilo");
            exit(EXIT_FAILURE);
        }
    }

    printf("Proceso de creacion de hilos terminado\n\n");
     
    
    for (i=0; i<N_COCHES; i++)
    {
        
        /* CODIGO 3 */
        if (pthread_join(hilosCoches[i], NULL) != 0)
       	{
            perror("Error al esperar el hilo");
            exit(EXIT_FAILURE);
        } 
    }
   
    printf("Todos los coches han LLEGADO A LA META \n");
    
    /* CODIGO 5 */        
    
    printf("\nCLASIFICACION FINAL\n");
    for (i = 0; i < N_COCHES; i++) 
    {
        printf("Posicion %d: Coche_%d\n", i + 1, clasificacionFinal[i]);
    }

    // Liberar memoria asignada
    for (i = 0; i < N_COCHES; i++)
    {
        free(Coches[i].cadena);
    }

    return 0;
}


