#include <stdio.h>      // 20.9
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

        // Aproximarea unei integrale folosind metoda trapezelor        // 2.2


    // Functia integralei       // 2.2

double f(double x)      // 8.1, 8.10
{
    return(1/(x+1));
}


    // Functie de verificare input      // 2.2

double Validare(const char *prompt)     // 8.1, 8.10
{
    double var;
    char input[100];
    bool esteValid = false;

    do
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%lf", &var) == 1)
        {
            esteValid = true;
            break;
        }
        else
        {
            printf("Input invalid. Te rog sa introduci un numar.\n\n");
            break;  // 14.6
        }
    } while (!esteValid);
    printf("\n");
    return var;
}


int main()      // 16.5
{
    // Input        // 2.2

    double a, b, e;
    a = Validare("Introduceti limita inferioara a intervalului: ");
    b = Validare("Introduceti limita superioara a intervalului: ");
    e = Validare("Introduceti precizia: ");

    // Initializare     // 2.2
    double n = 1;

    // Aproximare initiala - 1 interval     // 2.2
    double II, IO, h, s, i;
    II = ((f(a)+f(b)) * (b-a))/2 ;      // 12.1

    // Rafinare aproximare      // 2.2
    do
    {
        n  = 2*n;
        h = (b-a)/n ;
        IO = II;
        s = 0;
        for(i=1; i<=n-1; i++)       // 13.4
        {
            s = s + f(a+i*h);       // 12.1
        }
        II = ( f(a) + 2*s + f(b) ) * h/2 ;      // 12.1
    }while( fabs(II-IO) > e );

    // Output       // 2.2
    printf("Valoarea integralei, obtinuta cu precizia %f este %f", e, II);
}       // 16.8



/* 
    Reguli MISRA nerespectate

    2.2 (r) - Comentarii doar cu / * ... * /
        Liniile 6, 9, 17, 46, 53, 56, 60, 74
    6.3 (a) - "Typedef" predefinite in locul tipurilor numerice de baza (ex.: float64_t in loc de double)
        Toate variabilele
    8.1 (r) - Functiile trebuie sa aiba declaratii prototip inainte de definire
        Liniile 11 (f), 19(Validare)
    8.10 (r) - Functiile apelate strict intern trebuie declarate ca "static"
        Liniile 11 (f), 19(Validare)
    12.1 (a) - Parantezele ar trebui folosite pentru ordinea efectuarii operatiilor 
        Liniile 58, 69, 71
    13.4 (r) - Variabilele float nu se folosesc in cicluri "for"
        Linia 67
          14.6 (r) - Orice loop "for" poate avea maxim un break
                Linia 38
    16.5 (r) - Functiile fara parametrii trebuie declarate si definite cu "void"
        Linia 44 (main)
    16.8 (r) - Toate functiile non-void trebuie sa aiba un "return" specificat
        Linia 76 (main)
    20.9 (r) - Libraria <stdio.h> nu trebuie folosita in cod productie
        Linia 1
*/