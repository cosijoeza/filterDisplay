#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int tam;
int filtro[7][7];
void funlee(string);
int main()
{
    string path = "/home/cosi/Documentos/datos.txt";
    funlee(path);
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++){  
            cout << filtro[i][j];
        }
        cout << "\n";
    }
    return 0;
    
}

void funlee(string ruta)
{
    ifstream fin (ruta);
    fin >> tam;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++){
            fin >> filtro[i][j];
        }
    }
}
