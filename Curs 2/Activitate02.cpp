#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Fruct {
private:
	const int idFruct;
	static int numarFructe;
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:
	void setGreutate(float greutate) {
		if (greutate > 0) {
			(*this).greutate = greutate;//-> inseamna dereferentiere+accesare
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getNume() {
		// if(this->nume != nullptr)
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}

	float getGreutateSamanta(int pozitie) {
		if (pozitie >= 0 && pozitie < nrSeminte) {
			return this->greutatiSeminte[pozitie];
		}
		//throw exception();
		throw "poz in afara wc";
	}

	int getIdFruct() {
		return this->idFruct;
	}

	static int getNumarFructe() {
		return numarFructe;
	}

	void setNumarFructe(int nrFructe) {
		numarFructe = nrFructe;
	}

	//
	int getLunaMaturitate(){
		return this->lunaMaturitate;
	}

	int getNumarSeminte(){
		return this->nrSeminte;
	}

	string getCuloare(){
		return this->culoare;
	}
	

	//

	Fruct() :idFruct(++numarFructe) {
		//this->idFruct = ; asa NU! const se initilizeaza altfel
		this->culoare = "Rosu";
		this->greutate = 0.6;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
		// numarFructe++;
	}

	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) :idFruct(++numarFructe){
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	Fruct(const Fruct& copie) :idFruct(++numarFructe){
		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;

		if(copie.greutatiSeminte != nullptr){
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else this->greutatiSeminte = nullptr;

		if(copie.nume != nullptr){
		this->nume = new char[strlen(copie.nume) + 1];
		strcpy(this->nume, copie.nume);}
		else this->nume = nullptr;
	}

	void operator+=(float valDeAdunatLaGreutate){
		this->greutate += valDeAdunatLaGreutate;
	}

	// comparatie intre 2 obiecte dupa un atribut

	bool operator<(const Fruct& f){
		return this->greutate < f.greutate;
	}

	//operator neagtie, 

	int operator!(){
		return this->lunaMaturitate;
	}

	//operator functie
	
	float operator()(int poz){
		return this->getGreutateSamanta(poz);
	}

	void operator=(const Fruct& copie) { //:idFruct(++numarFructe) constantele nu se pot modifica, idul ramane neschimbat
		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;
		if (this->greutatiSeminte != nullptr){
			delete[] this->greutatiSeminte;
			this->greutatiSeminte = nullptr;
		}


		if(copie.greutatiSeminte != nullptr){
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else this->greutatiSeminte = nullptr;

		if (this->nume != nullptr){
			delete[] this->nume;
			this->nume =nullptr;
		}
		if(copie.nume != nullptr){
		this->nume = new char[strlen(copie.nume) + 1];
		strcpy(this->nume, copie.nume);}
		else this->nume = nullptr;

		// return *this;
	}

	void afisareFruct(){  // ca tema de implementat in afara functiei 

		// float greutate;
		// int lunaMaturitate;
		// int nrSeminte;
		// float* greutatiSeminte;

		cout << this->getIdFruct() << ". Fructul ";
		cout << " are culaorea " << this->getCuloare() <<
		", de greutate " << this->getGreutate() << " kg, " <<  " cu coarece in luna a " << this->getLunaMaturitate() << ". Contine " <<
		this->getNumarSeminte() << " cu urmatoarele greutati; ";
		for(int i = 0; i < this->getNumarSeminte()-1; i++){
			cout << this->getGreutateSamanta(i) << " ,";
		}
		cout << this->getGreutateSamanta(this->getNumarSeminte()-1) << "." << endl;

	}

	~Fruct() {
		if(this->greutatiSeminte != nullptr){
			delete[] this->greutatiSeminte;
		}
		if(this->nume != nullptr){
			delete[] this->nume;
		}
	}

};

int Fruct::numarFructe = 0;

// void afisareFruct(Fruct f){  // ca tema de implementat in afara functiei 

// 	// float greutate;
// 	// int lunaMaturitate;
// 	// int nrSeminte;
// 	// float* greutatiSeminte;

// 	cout << f.getIdFruct() << ". Fructul " << f.getNume() << " are culaorea " << f.getCuloare() <<
// 	", de greutate " << f.getGreutate() << " kg, " <<  " cu coarece in luna a " << f.getLunaMaturitate() << ". Contine " <<
// 	f.getNumarSeminte() << " cu urmatoarele greutati; ";
// 	for(int i = 0; i < f.getNumarSeminte()-1; i++){
// 		cout << f.getGreutateSamanta(i) << " ,";
// 	}
// 	cout << f.getGreutateSamanta(f.getNumarSeminte()-1) << "." << endl;

// }

int main() {

	float* vector = new float[3] {0.1, 0.2, 0.3};
	Fruct mar("Mar", "Galben", 0.4, 8, 3, vector);
	Fruct fruct1;
	try{
		cout << endl << mar.getGreutateSamanta(4);
	}

	catch (const char* mesaj){
		cout << endl << mesaj;
	}

	catch (...) {     // catch(...) printe toate exceptiile
		cout << endl << "pozitia este in afara intervalului";
	}

	
	// cout << endl << fruct1.getIdFruct() << endl;
	// cout << endl << "am initializat " << Fruct::getNumarFructe() << " obiecte!" << endl;
	cout << endl << mar.getGreutateSamanta(2) << endl;
	Fruct fruct2 = mar;
	Fruct fruct3 = fruct1;
	mar += 0.1;
	if(mar < fruct2)
	cout << endl << "real, f1 < f2";
	else cout << endl << "ireal, f2 e mai mic";

	// constantele se initializeaza o singura data , de preferat la constructor
	// constatele le pot accesca cu get dar cu set nu; logic sunt constante nu se schimba
	//CONCEPT 1 ENCAPSULARE
	//CONCEPT 2 POLYMORPHISM - medota pe care o putem folosi in mai multe scenarii
	Fruct fructDefault;

	fructDefault = mar;
	cout << endl << "am initializat " << Fruct::getNumarFructe() << " obiecte!" << endl;
	// afisareFruct(mar);
	// afisareFruct(fructDefault);
	// afisareFruct(fruct2);
	// afisareFruct(fruct1);
	mar.afisareFruct();
	// fruct1.afisareFruct();
	// fruct3.afisareFruct();
	fructDefault.afisareFruct();

	cout << endl << fructDefault.getIdFruct() << endl;
	//discutie despre atribute constante
	//atribute statice
	//constructor de copiere

	//afisare 


	// destructor
	//operator =(de atribuire)
	//alti operatori
	return 0;
}


