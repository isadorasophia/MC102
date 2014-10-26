/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 01b - Notas do vestibular*/

#include <stdio.h>
#include <math.h>
int main () {
    int A, NMO;
    double PCG, PIN, PPO, PMA, PCH, PCN, NCG, MCG, DPCG, NP, NIN, MIN, DPIN,
NPO, MPO, DPPO, NMA, MMA, DPMA, NCH, MCH, DPCH, NCN, MCN, DPCN, NPIN, NPPO,
NPMA, NPCH, NPCN, NF;

    scanf("%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf", &A, &NMO, &PCG, &PIN,
&PPO, &PMA, &PCH, &PCN, &NCG, &MCG, &DPCG);

    NP = (NCG - MCG) * 100/DPCG + 500;
   
    if (NP < 550)
    printf("Primeira Fase: %.1f\n", NP);
    
    if (NP >= 550) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &NIN, &MIN, &DPIN, &NPO, &MPO, &DPPO, &NMA, &MMA, &DPMA, &NCH, &MCH, &DPCH, &NCN, &MCN, &DPCN);
        
        NPIN = (NIN - MIN) * 100/DPIN + 500;
        NPPO = (NPO - MPO) * 100/DPPO + 500;
        NPMA = (NMA - MMA) * 100/DPMA + 500;
        NPCH = (NCH - MCH) * 100/DPCH + 500;
        NPCN = (NCN - MCN) * 100/DPCN + 500;
        
        NF = (PCG*NP + PIN*NPIN + PPO*NPPO + PMA*NPMA + PCH*NPCH +
PCN*NPCN)/(PCG + PIN + PPO + PMA + PCH + PCN);
       
        printf("Primeira Fase: %.1f\nSegunda Fase: %.1f\n", NP, NF);
        
        switch (A) {
            case 1:
                if ((NPMA >= NMO) && (NPCN >= NMO)) {
                    printf("Grupo 1\n");
                } else {
                    printf("Grupo 2\n");
                }
                break;
            case 2:
                if ((NPPO >= NMO) && (NPCH >= NMO)) {
                    printf("Grupo 1\n");
                } else {
                    printf("Grupo 2\n");
                }
                break;
            case 3:
                if (NPCN >= NMO) {
                    printf("Grupo 1\n");
                } else {
                    printf("Grupo 2\n");
                }
        } 
    }
        
    return 0;
    
}