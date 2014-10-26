/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 01a - Calculo de media das notas de avaliacoes */

#include <stdio.h>
#include <math.h>

int main () {
    double p1, p2, p3, l, p, ma, mh, mg;

    scanf("%lf %lf %lf %lf", &p1, &p2, &p3, &l);

    p = (3 * p1 + 3 * p2 + 4 * p3)/10;
    ma = (p + l)/2;
    mh = (2 * p * l)/(p + l);
    mg = sqrt(p * l);

    printf("Media aritmetica: %.1f\n", ma);
    printf("Media harmonica: %.1f\n", mh);
    printf("Media geometrica: %.1f\n", mg);

    return 0;
}