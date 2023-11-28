#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void ejercicio1(float iteraciones);
void ejercicio2(int iteraciones);
void cambiarColorTexto();
void restaurarColor();

int main()
{
    int opc;
    float iteraciones;
    bool continuar = true;
    do
    {
        cout << "Seleccione el ejercicio que desea realizar:\n";
        cout << "1. Se tienen 6 numeros positivos y 8 numeros negativos. Se eligen 4 al azar y se multiplican:\na) de estas operaciones. En cuantos el producto es positivo?\nb) si por error se ha incluido el 0 entre los 6 numeros positivos. En cuantos el producto sera nulo?.\n" << endl;
        cout << "2. Lance dos dados y calcule la probabilidad P(la suma de puntos sea >= 9 | la cara 6 aparece).\n" << endl;
        cout << "3. Salir\n";
        cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:
            cout << "Digite cuantas veces desea realizar el experimento\n";
            cin >> iteraciones;
            system("cls");
            ejercicio1(iteraciones);
            break;
        case 2:
            cout << "Digite cuantas veces desea realizar el experimento\n";
            cin >> iteraciones;
            system("cls");
            ejercicio2(iteraciones);
            break;
        default:
            continuar = false;
            cout << "hasta pronto";
            break;
        }

    } while (continuar);
    
}

void cambiarColorTexto()
{
    cout << "\033[0;32m"; // Código de escape ANSI para cambiar color de texto
}

void restaurarColor()
{
    cout << "\033[0m"; // Código de escape ANSI para restablecer el color
}

void ejercicio1(float iteraciones)
{
    float productoPositivo = 0;
    float productoNulo = 0;

    // Inicializar para generar números aleatorios diferentes en cada ejecución
    srand(static_cast<unsigned int>(time(0)));

    cout << "productos finales: " << endl;
    for (int j = 0; j < iteraciones; j++)
    {
        int m = 1;
        const int positivo = 6;
        const int negativo = 8;
        int Positivos[positivo];
        int Negativos[negativo];
        int arregloCombinado[14];

        // Generar arreglos aleatorios
        for (int i = 0; i < positivo; i++)
        {
            Positivos[i] = rand() % 6;
        }

        for (int i = 0; i < negativo; ++i)
        {
            Negativos[i] = rand() % 8 + 1;
            Negativos[i] = -Negativos[i];
        }

        // Combinar arreglos en uno solo
        for (int i = 0; i < 6; ++i)
        {
            arregloCombinado[i] = Positivos[i];
        }

        for (int i = 0; i < 8; i++)
        {
            arregloCombinado[6 + i] = Negativos[i];
        }

        for (int i = 0; i < 4; i++)
        {
            int n = rand() % 13;
            m *= arregloCombinado[n];
        }

        //Imprimir el producto en cada iteración
        cout << "(" << m << ") ";

        if (m > 0)
            productoPositivo++;
        if (m == 0)
            productoNulo++;
    }

    // Imprimir resultados después de todas las iteraciones
    cout << endl << endl << "Arbol de Probabilidad:\n";
    cambiarColorTexto(); // Cambiar color para resultados
    cout << "        |-->Probabilidad P(positivo): " << productoPositivo << "/" << iteraciones << " = " << productoPositivo / iteraciones << "\n";
    cout << "    |-->a) " << productoPositivo << " productos positivos\n";
    cout << "|-->Iteraciones: " << iteraciones << "\n";
    cout << "    |-->b) " << productoNulo << " productos nulos\n";
    cout << "        |-->Probabilidad P(nulo): " << productoNulo << "/" << iteraciones << " = " << productoNulo / iteraciones << endl << endl << endl;
    restaurarColor(); // Restablecer color al final
    system("pause");
    system("cls");
}

void ejercicio2(int iteraciones)
{
    // Contadores para eventos favorables y totales
    float eventosFavorables = 0;
    float eventosTotales = 0;

    cout << "lanzamientos donde aparece la cara 6 y la suma de caras es >= a 9:\n";
    for (int j = 0; j < iteraciones; j++)
    {
        // Lanzar dos dados
        int dado1 = rand() % 6 + 1;
        int dado2 = rand() % 6 + 1;

        // Contar eventos donde la cara 6 aparece
        if (dado1 == 6 || dado2 == 6)
        {
            // Contar todos los eventos donde la cara 6 aparece
            eventosTotales++;
            // Contar eventos donde la suma de puntos es ≥ 9
            if (dado1 + dado2 >= 9)
            {
                eventosFavorables++;
                cout << "Lanzamiento " << j + 1 << ": Dado 1 = " << dado1 << " || Dado 2 = " << dado2 << endl;
            }
        }

    }

    // Calcular y mostrar la probabilidad
    // Imprimir resultados después de todas las iteraciones
    cout << endl << endl << "Arbol de Probabilidad:\n";
    cambiarColorTexto(); // Cambiar color para resultados
    cout << "|-->Lanzamientos: " << iteraciones << "\n";
    cout << "    |-->La cara 6 aparece " << eventosTotales<< " veces\n";
    cout << "        |-->Probabilidad P(la cara 6 aparece): " << eventosTotales << "/" << iteraciones << " = " << eventosTotales / iteraciones << endl;
    cout << "            |-->Probabilidad P(la suma de puntos sea >= 9 | la cara 6 aparece): " << eventosFavorables << "/" << eventosTotales << " = " << eventosFavorables / eventosTotales << endl << endl << endl;
    restaurarColor(); // Restablecer color al final
    system("pause");
    system("cls");
}

