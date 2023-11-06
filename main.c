#include <stdio.h>  // 20.9 (r) - Libraria <stdio.h> nu trebuie folosita in cod productie
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

        // Aproximarea unei integrale folosind metoda trapezelor        //     2.2 (r) - Comentarii doar cu / * ... * /


    // Functia integralei       //     2.2 (r) - Comentarii doar cu / * ... * /

double f(double x)    //     8.10 (r) - Functiile apelate strict intern trebuie declarate ca "static"
{
    return(1/(x+1));
}


    // Functie de verificare input      //     2.2 (r) - Comentarii doar cu / * ... * /

double Validare(const char *prompt)    //     8.10 (r) - Functiile apelate strict intern trebuie declarate ca "static"
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
            // break;
        }
        else
        {
            printf("Input invalid. Te rog sa introduci un numar.\n\n");
            // break;  //         14.6 (r) - Orice loop "for" poate avea maxim un break
        }
    } while (!esteValid);
    printf("\n");
    return var;
}


int main()      //     16.5 (r) - Functiile fara parametrii trebuie declarate si definite ca "void"
{
    // Input        //     2.2 (r) - Comentarii doar cu / * ... * /

    double a, b, e;
    a = Validare("Introduceti limita inferioara a intervalului: ");
    b = Validare("Introduceti limita superioara a intervalului: ");
    e = Validare("Introduceti precizia: ");

    // Initializare     //     2.2 (r) - Comentarii doar cu / * ... * /
    double n = 1;

    // Aproximare initiala - 1 interval     //     2.2 (r) - Comentarii doar cu / * ... * /
    double II, IO, h, s, i;
    II = ((f(a)+f(b)) * (b-a))/2 ;

    // Rafinare aproximare      //     2.2 (r) - Comentarii doar cu / * ... * /
    do
    {
        n  = 2*n;
        h = (b-a)/n ;
        IO = II;
        s = 0;
        for(i=1; i<=n-1; i++)       //     13.4 (r) - Variabilele float nu se folosesc in cicluri "for"
        {
            s = s + f(a+i*h);       //     12.1 (a) - Parantezele ar trebui folosite pentru ordinea efectuarii operatiilor 
        }
        II = ( f(a) + 2*s + f(b) ) * h/2 ;      //     12.1 (a) - Parantezele ar trebui folosite pentru ordinea efectuarii operatiilor 
    }while( fabs(II-IO) > e );

    // Output       //     2.2 (r) - Comentarii doar cu / * ... * /
    printf("Valoarea integralei, obtinuta cu precizia %f este %f", e, II);

}       //     16.8 (r) - Toate functiile non-void trebuie sa aiba un "return" specificat
