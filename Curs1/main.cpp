#include <iostream>
#include<cstring>
using namespace std;

struct Carte
{
    char* autor; // * adresa primului element in memorie
    int nrPagini;
};

void afisareCarte(Carte c)
{
    cout<<endl<<"Cartea scrisa de "<<c.autor<<" are "<<c.nrPagini<<" pagini.";
}

void afisareVector(int* vector, int dim){
    for(int i =0; i<dim; i++)
    {
        cout<<endl<<"vectorul: "<<i<<" este "<<vector[i]<<endl;
         
    }
}

void stergereMaximDePePozitie(int** vector, int* dim, int pozitie){
    int* vectorAux = new int[*dim-1]; //tre sa deferentiem
    int j = 0;
    for(int i=0;i<*dim-1;i++){
        if(i!=pozitie){
            vectorAux[j]=(*vector)[i];
            j++;
        }
    }
    delete[] (*vector);
    (*dim)--;
    *vector = vectorAux;
}

int pozitieMaxVector(int* vector, int dim){
    int pozMax = 0;
    for(int i=1; i<dim; i++){
        if(vector[pozMax]<vector[i]){
            pozMax = i;
        };
    }

    return pozMax;
}

int suma()
{
    int suma=0;
    int dimensiune=4;
    int vector[]={17,29,45,78};
    for(int i=0;i<dimensiune;i++)
    {
        suma=suma+vector[i];
    }
    return suma;
}



int main() {
    cout << "buna" << endl;
    Carte carte;
    carte.nrPagini=240;
    //la pointeri avem mai multe operatii alocare-new, dezalocare-delete
    carte.autor=new char[strlen("Popescu")+1];
    strcpy(carte.autor, "Popescu"); //secured
    afisareCarte(carte);
    //pierderi de memorie daca nu dezalocam memoria, de cate ori pun new de atatea ori pun delete
    delete[] carte.autor;

    int sumaCalculata = suma();
    cout<<endl<<"Suma calculata este:"<<sumaCalculata;

    // char* adresa;
    // char buffer[50];
    // cout<<endl<<"adresa este: ";
    // //cin>>buffer;2
    // cin.getline(buffer, 50);
    // adresa= new char[strlen(buffer)+1];
    // strcpy(adresa, buffer);
    // cout<<endl<<"adresa citita este: "<<adresa;
    // delete[] adresa;

    int* vector;
    int dim=3;
    vector = new int[dim];
    for(int i =0; i<dim; i++)
    {
        cout<<endl<<"vector["<<i<<"]: ";
        cin>>vector[i];  
    }
    afisareVector(vector, dim);
    cout<<endl<<"maximu e la: " <<pozitieMaxVector(vector, dim)<<endl;
    stergereMaximDePePozitie(&vector, &dim, 2);
    afisareVector(vector, dim);
    return 0;
}

// TEMA DE CASA
// Sterge max de pe poz, transmitere prin referinta, nu prin pointer