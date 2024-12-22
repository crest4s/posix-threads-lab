#Variables
CC = gcc
CFLAGS = -Wall -pthread
TARGET = simula_car
SRC = simula_car-c
HEADERS = simula_car.h

.PHONY: all clean

#Compilacion principal
all: $(TARGET)

simula_car: simula_car.c simula_car.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

#Limpieza
clean:
	rm -f $(TARGET) *.o
