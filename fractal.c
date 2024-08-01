#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vector{
    double x;
    double y;
};

struct vector IsInRect();
int NewPoint(struct vector *P_1, struct vector *P_2);

int main() {

    srand48(time(NULL));

    struct vector P_1 = IsInRect();

    struct vector P_2;

    int choice;

    for (int i = 0; i < N; i++) {

        choice = NewPoint(&P_1, &P_2);
        
        if (i % 10 == 0){
            printf("It. n. %d vertice n. %d v(n) = (%.3lf,%.3lf) v(n+1) = (%.3lf,%.3lf)\n", i, choice, P_1.x, P_1.y, P_2.x, P_2.y);
        }

        P_1.x = P_2.x;
        P_1.y = P_2.y;

    }

    return 0;
}

struct vector IsInRect() {

    struct vector P;

    do{
    printf("Inserire coordinate v(..,..):\n");
    scanf("%lf,%lf", &P.x, &P.y);
    } while ( (P.x < - 3 || P.x > 3) || ( P.y < 0 || P.y > 5));

    return P;
}

int NewPoint(struct vector *P_1, struct vector *P_2) {

    struct vector V_1 = {-3, 0};
    struct vector V_2 = { 3, 0};
    struct vector V_3 = { 0, 5};

    int rand = lrand48() % 3 + 1;

    if (rand == 1) {
        (*P_2).x = 0.5 * ((*P_1).x + V_1.x);
        (*P_2).y = 0.5 * ((*P_1).y + V_1.y);
    }
    else if (rand == 2) {
        (*P_2).x = 0.5 * ((*P_1).x + V_2.x);
        (*P_2).y = 0.5 * ((*P_1).y + V_2.y);
    }
    else {
        (*P_2).x = 0.5 * ((*P_1).x + V_3.x);
        (*P_2).y = 0.5 * ((*P_1).y + V_3.y);
    }

    FILE *output = fopen("fractal.dat", "a");

    fprintf(output, "%lf %lf\n", (*P_2).x, (*P_2).y);

    fclose(output);

    return rand;

}