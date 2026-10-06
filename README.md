# posix-threads-lab

Car race simulation in C with POSIX threads. Each of the 8 cars is a thread that starts, "races" for a random time (0–9 s, using the re-entrant `rand_r()`) and reaches the finish line. A mutex serialises console output and a second mutex protects the shared final ranking, which the main thread prints after joining every car.

Lab 3 of the *Sistemas Operativos* (Operating Systems) course at the University of Alcalá (UAH), 2024–25 academic year: POSIX services for thread management on Linux (`pthread_create`, `pthread_join`, `pthread_exit`, `pthread_self`, `pthread_mutex_lock` / `unlock`).

## Build and run

Requires Linux (or any POSIX system) with `gcc` and `make`:

```bash
cd p3
make
./simula_car
```

Example output (order changes on every run):

```
SALIDA DE COCHES
Salida de Coche_0 0
...
Llegada de Coche_3 3
...
Todos los coches han LLEGADO A LA META

CLASIFICACION FINAL
Posicion 1: Coche_3
...
```

## Structure

```
p3/
├── simula_car.c          # threads, mutexes and ranking
├── simula_car.h          # car type, shared data and prototypes
├── makefile
└── archivos_apoyo_pract3/ejecutarincompleto2.c   # support file used during the lab
```

## Authors

- Adrián Morales Rodríguez ([@crest4s](https://github.com/crest4s))
- [@Hugoserrano2005](https://github.com/Hugoserrano2005)
