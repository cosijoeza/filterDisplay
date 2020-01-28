//Lee los datos de un archivo y los pone en la matriz global aux
void getFilter(string ruta)
{
    ifstream fin (ruta);
    fin >> dimension;
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++){
            fin >> filtro[i][j];
        }
    }
}
