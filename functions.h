bool istxt(string ruta)
{
	bool bandera = false;
	string extension = "";
	int lag = ruta.size(); 
	for(int i=0; i < lag;i++)
	{
		if(bandera)
			extension += ruta[i];
		if(ruta[i] == '.')
			bandera = true;
	}
	if(extension != "txt")
		return false;
	qDebug() << "Es archivo txt";
	return true;
}
//Lee los datos de un archivo y los pone en la matriz global aux
void getFilter(string ruta)
{
	int i = 0;
	string aux;
	ifstream fin (ruta);
    fin >> dimension;   
    //Lee datos de filtro
	for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++){
            fin >> filtro[i][j];
        }
    }
	qDebug() <<  "Titulo y descrip";
	//Titulo y descripción del filtro
	fin >> title;
	qDebug() << title.c_str();
	do
	{
		fin >> aux;
		if(aux == "$")	//Fin de cadena
			break;
		description += aux;
		i++;
		if((i % 6) == 0)
			description += "\n";
		else
			description += " ";
	}while(1);
}
//Aplicar filtro a la IMAGEN BLANCO Y NEGRO
Mat addFilter(Mat imgOri)
{
	int tam = dimension;
	int sumaK = 0;
    int nCanales = imgOri.channels();
	int nR = imgOri.rows;
	int nC = imgOri.cols * nCanales;
    for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){
			sumaK+=filtro[i][j]; 
		}	
		
	}
	if(sumaK==0){
		sumaK=1;
	}
	Mat img_fil=imgOri.clone();
	int suma,k,l;

	for (int j = 0; j < nR-2; j++)
	{
		uchar* renNue = img_fil.ptr<uchar>(j+(tam/2));
		for (int i = 0; i < nC-2; i += nCanales) {
			suma = 0;
			for( k=0; k<tam; k++)
			{
                for( l=0; l<tam;l++){
                	uchar* renOri = imgOri.ptr<uchar>(j+l);
                    suma+=*(renOri+k+i)*filtro[k][l];    
                }
            }
            suma = suma/sumaK;
            if(suma>=0 && suma<=255){
            	*(renNue+(i+1))=suma;
            }else if(suma<0){
            	*(renNue+(i+1))=0;
            }else{
            	*(renNue+(i+1))=255;
            }
		}
	}
	return img_fil;
}
Mat addFilterRGB(Mat imgOri) 
{
	int nR;
	int nC;
	int nCanales;
	int tam = dimension;
	int sumaK = 0;
	nCanales = imgOri.channels();
	nR = imgOri.rows;
	nC = imgOri.cols * nCanales;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++){
			sumaK+=filtro[i][j];
		}	
		
	}
	if(sumaK==0){
		sumaK=1;
	}
	Mat img_fil=imgOri.clone();
	int sumaR,sumaG,sumaB,k,l,inc;
	for (int j = 0; j < nR-2; j++) {
		uchar* renNue = img_fil.ptr<uchar>(j+(tam/2));//enmedio
		for (int i = 0; i < nC-2; i += nCanales) {
			sumaR = 0,sumaB=0,sumaG=0;
			
			for(k=0; k<tam; k++){
				inc=0;
				uchar* renOri = imgOri.ptr<uchar>(j+k);
				for(l=0; l<tam; l++){
					sumaB+=*(renOri+inc+i+0)*filtro[k][l];  
                    sumaG+=*(renOri+inc+i+1)*filtro[k][l]; 
                    sumaR+=*(renOri+inc+i+2)*filtro[k][l]; 
					inc+=3;
				}
				
			}
			sumaB = sumaB/sumaK;
            sumaG = sumaG/sumaK;
            sumaR = sumaR/sumaK;
            if(sumaB>=0 && sumaB<=255){
            	*(renNue+(i+nCanales)+0)=sumaB;
            }else if(sumaB<0){
            	*(renNue+(i+nCanales)+0)=0;
            }else{
            	*(renNue+(i+nCanales)+0)=255;
            }
            if(sumaG>=0 && sumaG<=255){
            	*(renNue+(i+nCanales)+1)=sumaG;
            }else if(sumaG<0){
            	*(renNue+(i+nCanales)+1)=0;
            }else{
            	*(renNue+(i+nCanales)+1)=255;
            }
            if(sumaR>=0 && sumaR<=255){
            	*(renNue+(i+nCanales)+2)=sumaR;
            }else if(sumaR<0){
            	*(renNue+(i+nCanales)+2)=0;
            }else{
            	*(renNue+(i+nCanales)+2)=255;
            }
		}
	}
	return img_fil;
}