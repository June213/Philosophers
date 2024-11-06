# Philosophers

**Philosophers** es un proyecto en C que simula un problema de sincronización clásico: la "filosofía de los comedores". El objetivo es modelar la interacción de varios filósofos que piensan, comen y esperan, utilizando semáforos o mutexes para evitar conflictos de acceso a recursos compartidos.

## Uso

Compila y ejecuta el programa:  
make  
./philosophers <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<num_meals>] 


**num_philosophers:** Número de filósofos.

**time_to_die:** Tiempo que un filósofo puede estar sin comer antes de morir.

**time_to_eat:** Tiempo que un filósofo pasa comiendo.

**time_to_sleep:** Tiempo que un filósofo pasa durmiendo.

**num_meals (opcional):** Número de comidas que cada filósofo debe realizar.
