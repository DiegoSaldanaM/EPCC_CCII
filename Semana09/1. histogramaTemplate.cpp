/*Escriba una clase usando templates que tome una colección de elementos
como parámetro. La clase debe tener un método que devuelva el histograma
de los elementos de la colección. El método histograma debe aceptar un
parámetro que indique en cuantos intervalos agrupar a los elementos de la
colección. La clase debe tener además un método para imprimir el
histograma. Ejemplo: Dada la colección de enteros {10, 2, 9, 7, 5, 6, 1, 8, 8, 4}
y con el número de intervalos igual a 5, el histograma debe retornar 2 1 2 2 3*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class histograma{
private:
    vector<T> coleccion_elem;
    T intervalo;
public:
    histograma(vector<T> n,T);
    ~histograma(){};
    void imprimir();
    void distrib();
};

template<class T>
histograma<T>::histograma(vector<T> n,T _intervalo){
	intervalo=_intervalo;
	for (int i=0; i<n.size(); i++){
        coleccion_elem.push_back(n[i]);
    }
    	
}

template<class T>
void histograma<T>::imprimir(){
	sort(coleccion_elem.begin(),coleccion_elem.end());
	for(int i = 0; i < coleccion_elem.size(); i++){
        cout << coleccion_elem.at(i) << ",";
    }
        
}

template<class T>
void histograma<T>::distrib(){
	vector<int> res;
	int c=0,v=0;
	sort(coleccion_elem.begin(),coleccion_elem.end());
	T inicial=coleccion_elem[0];
	T siguiente=inicial+intervalo;
	for(int k= 0; k< coleccion_elem.size(); k++){
		v=0;
		for(int i=0; i< coleccion_elem.size(); i++){

			if(inicial<=coleccion_elem[i] && coleccion_elem[i]<siguiente){
				c++;
			}
			v++;
		}
		if(c!=0){res.push_back(c);}
		c=0;
		inicial=siguiente;
		siguiente=inicial+intervalo;
	}
	for(int i = 0; i < res.size(); i++){
        cout << res.at(i) << " ";
    }
       
}

int main(){

    vector<int> lista1={2,4,6,3,8,1,9,5,7};
	histograma<int> l1(lista1,2);

	cout<<"Imprimiendo lista predeterminada: "<<endl;
    for(int i = 0; i < lista1.size(); i++){
        cout << lista1.at(i) << ",";
    }
    cout<<endl;

    cout<<"Imprimiendo lista ordenada: "<<endl;
    l1.imprimir();
    cout<<endl;
    cout<<"Imprimiendo histograma: "<<endl;
    l1.distrib();

	return 0;
}