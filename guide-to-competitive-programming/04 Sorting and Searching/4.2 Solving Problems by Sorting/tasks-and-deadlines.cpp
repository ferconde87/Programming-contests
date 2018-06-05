#include <bits/stdc++.h>

using namespace std;


int main(){
    //approach greedy: conviene hacer primero las tareas más cortas y es optimo

    // Task    Duration    Deadline
    // A       4           2
    // B       3           10
    // C       2           8
    // D       4           15

    //Puntos: Deadline - tiempoFinDeTarea
    //por cada paso de tiempo cuando faltan X tareas por terminar "perdemos" X puntos
    //Cuando terminamos una tarea, ya en el siguiente tiempo "perdemos" X-1 puntos

    //hasta terminar C (tarea más corta) perdimos 2 (Duration C) * 4 (cantidad de tareas sin resolver) => -8
    //hasta terminar B (next  más corta) perdimos 3 (Duration C) * 3 (cantidad de tareas sin resolver) => -9
    //hasta terminar A (next  más corta) perdimos 4 (Duration C) * 2 (cantidad de tareas sin resolver) => -8
    //hasta terminar D (next  más corta) perdimos 4 (Duration C) * 1 (cantidad de tareas sin resolver) => -4
    // => 8 - 8 + 10 - 9 + 2 - 8 + 15 - 4 = [6]
    // o sumando deadlines - puntos perdidos
    // =>                         35 - 29 = [6]

    return 0;
}