#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cinquillo.h"
#include "minimax.h"
int main()
{
    int jugador, primero,ganador;
    tJugada jugada;
    srand(time(NULL));
    //tNodo *juego=nodoInicial();
    tNodo *juego=repartir(); // reparte todas las cartas entre los 2 jugadores
    dispNodo(juego,MIN);
    dispNodo(juego,MESA);
    dispNodo(juego,MAX);
    
    getchar(); // una pausa
    
    // Inicio del juego después de repartir las cartas
    if (juego->nMax==N*P/2){  // si la mesa está vacía se empieza por el que tenga el 5 de oros
        jugada.palo=0;  //oros
        jugada.num=4; //  5 de oros
        jugador=juego->cartas[jugada.palo*N+jugada.num];
        if (jugador==MAX)
            printf("\n.... Tengo el 5 de oros es mi turno ... ");
        else
            printf(" \n.... Es tu turno, ahí está tu 5 de oros ...\n");
        
        // El 5 de oros se coloca en la mesa
        juego=aplicaJugada(juego,jugador,jugada);
        printf("\n Ups Tienes que implementar la función aplicaJugada \n");
        dispNodo(juego,MESA);
        jugador=opuesto(jugador);
    }
    else {
            printf("\n Elige el turno 1 Primero  2 Segundo .... ");
            scanf("%d",&primero); printf("\n");
            if (primero==1)
                jugador=MIN;
            else
                jugador=MAX;
    }
    // Comienza el juego
    printf("\n UPs Te falta la función terminal\n");
    ganador=terminal(juego);
    ganador=0;
    while(ganador==0){
       if (jugador==MAX)
          juego=(tNodo *) PSEUDOminimax(juego);
       else
          juego=(tNodo *)jugadaAdversario(juego);
       dispNodo(juego,MESA);
        getchar();
       ganador=terminal(juego);
         printf("\n Ups Te falta la función terminal \n");
       jugador=opuesto(jugador);// siguiente jugador
    }

    switch(ganador){
     case 100:
          printf("\n HE GANADOOOO\n"); break;
     case 0:
           printf("\n EMPATE\n"); break;
     case -100:
          printf("\n Increible pero has ganado tu\n\n"); break;
     default: printf("\n algo ha salido mal en el juego ..\n");
     }
    return 0;
}
