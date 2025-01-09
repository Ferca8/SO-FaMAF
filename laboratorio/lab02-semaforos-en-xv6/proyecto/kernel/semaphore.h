#ifndef SEMAPHORE_H
#define SEMAPHORE_H

/*
    Me da uint64.
*/
#include "types.h"  

/*
    Cantidad máxima de semáforos disponibles.
    Pasa 5/5 tests con MAX_SEM = 2, elegimos 123 porque sí.
*/
#define MAX_SEM              123

/*
    Optamos por tomar al valor -1 para indicar que el semáforo está cerrado.
*/
#define CLOSED_SEM_VALUE    -1

/*
    POLÍTICAS:
    
    Fue necesario especificar ciertos comportamientos de nuestra librería. 
    Es decir, definir las políticas de nuestro sistema de semáforos:
      -- No se puede decrementar o incrementar el valor de un semáforo inactivo.
      -- No se puede abrir un semáforo que ya está abierto.
      -- No se puede cerrar un semáforo que ya está cerrado.
      -- No se puede abrir un semáforo y setearlo con un valor negativo.
      -- Solo son accesibles los semáforos cuyo ID esta entre [0,MAX_SEM). 
*/
#define ERROR_CODE           0
#define SUCCESS_CODE         1

/*
    DESCRIPCIÓN: Abre el semáforo “sem” con un valor arbitrario “value”.
    Si "sem" ya estaba abierto, no modifica nada y retorna ERROR_CODE.
    
    PRECONDICIÓN: 0 <= sem <= MAX_SEM && 0 < value.

    POSTCONDICIÓN: Si rc = sem_open(sem, value) entonces:
                    Si "sem" estaba cerrado -> rc = SUCCESS_CODE y semáforo sem 
                                                    tiene valor igual a value.
                    Si "sem" estaba abierto -> rc = ERROR_CODE y no modifica nada.
*/
uint64    sem_open(int sem, int value);

/*
    DESCRIPCIÓN: Despierta los procesos pendientes del semaforo "sem". Cierra el 
                 semáforo “sem”. Si "sem" ya estaba cerrado, no modifica nada y 
                 retorna ERROR_CODE. 
      
    PRECONDICIÓN: 0 <= sem <= MAX_SEM.

    POSTCONDICIóN: Si rc = sem_close(sem) entonces:
                    Si "sem" estaba abierto -> rc = SUCCESS_CODE 
                    Si "sem" estaba cerrado -> rc = ERROR_CODE y no modifica nada.
*/
uint64    sem_close(int sem);

/*
    DESCRIPCIÓN: Incrementa el semáforo ”sem” desbloqueando los procesos cuando 
                 su valor i = 0.
      
    PRECONDICIÓN: 0 <= sem <= MAX_SEM && semáforo "sem" tiene value i.

    POSTCONDICIÓN: semáforo "sem" tiene value i+1 
                   && procesos pendientes del semáforo "sem" fueron despertados 
                      si el índice i es igual a 0.
*/
uint64    sem_up(int sem);

/* 
    DESCRIPCIÓN: Decrementa el semáforo ”sem” bloqueando los procesos cuando su 
                 valor i = 0.
      
    PRECONDICIÓN: 0 <= sem <= MAX_SEM && semaforo "sem" tiene value i.

    POSTCONDICIÓN: Semáforo "sem" tiene value i-1
                   && si i = 0 entonces el proceso se encuentra bloqueado 
                      esperando al canal "sem".
*/
uint64    sem_down(int sem);

/*
    DESCRIPCIÓN: Busca el primer semáforo inactivo en el arreglo de semáforos 
                 `sem_array`. Al hallarlo, abre ese semáforo e inicializa su 
                 valor en value.
      
    PRECONDICIÓN: 0 <= value.

    POSTCONDICIÓN: Si i = sem_find_free_channel_and_set(value) entonces
                      Si había un canal libre    => i = numero del semáforo libre 
                                                        && value = valor del semáforo
                      Si no había un canal libre => i = CLOSED_SEM_VALUE
*/
uint64    sem_find_free_channel_and_set(int value);

#endif 
