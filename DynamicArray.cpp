#include <iostream>
#include "DynamicArray.h"
DynamicArray::DynamicArray()
{
    size = 0;
    arr = new Point[0];
}

DynamicArray::DynamicArray(const Point arr[], int size)
{
    this->size = size;
    this->arr = new Point[size];

    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

DynamicArray::DynamicArray(const DynamicArray &o)
{
    this->size = o.size;
    this->arr = new Point[o.size];

    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

void DynamicArray::push_back(Point elem) {
    Point *tmp = new Point[size+1];
    for(int i = 0; i < size; i++)
        tmp[i] = arr[i];

    tmp[size] = elem;

    delete []arr;
    size += 1;
    arr = tmp;
}
//Tarea
//utilizaremos un metodo auxiliar para llenar el arreglo ,esto para hacer mas notorio el cambio en los metodos de remove e insert
void DynamicArray::LLenarArray(){
    int x,y;//usaremos dos variable auxiliares que nos ayudara a cambiar los atributos de los objetos Point 
    for(int i=0;i<size;i++){
        std::cout<<"Ingrese la coordenada x: ";
        std::cin>>x;//el dato ingresado se almacenara en la variable auxiliar x
        std::cout<<"Ingrese la coordenada y: ";
        std::cin>>y;//el dato ingresado se almacenara en la variable auxiliar y
        arr[i].setX(x);//usamos los metodos set para hacer el cambio del atributo de la coordenada x e y del objeto punto que por defecto estaba en (0,0)
        arr[i].setY(y);
    }
}
//Mostraremos la lista en pantalla para poder evidenciar el cambio
void DynamicArray::ImprimirArray(){
    for(int i=0;i<size;i++){//hacemos un recorrido por la lista ya llenada a traves del anterior metodo
        std::cout<<"Posicion "<<i<<": "<<" ("<<arr[i].getX()<<" , "<<arr[i].getY()<<")"<<std::endl;
    }
}
void DynamicArray::insert(Point elem, int pos){//metodo insert
    Point *tmp = new Point[size+1];//creamos el arreglo temporal o auxiliar
    int count=0;//usaremos un contador para hacer el intercambio siendo este aparte de la variable iteradora
    for(int i=0;i<size+1;i++){
        if(i!=pos){//si la variable iteradora es diferente a la posicion entonces se almacenara el objeto en la lista auxiliar 
            tmp[i]=arr[count];//se efectua la asignacion
            count+=1;//el contador se incrementa ya que entra en la condicion
        }
        else{
            tmp[i]=elem;//realizamos los intercambios mediante los metodos set respectivos
        }

    }
    delete[]arr;//liberamos el bloque de bytes reservado con anterioridad
    size+=1;//aumentamos el tamaño en 1 para que este sea nuestro nuevo arreglo agregando el objeto que decidimos insertar
    arr=tmp;//igualamos los arreglos haciendo que los atributos de cada objeto almacenado en el arreglo principal se igualen al auxiliar que usamos  
}
void DynamicArray::remove(int pos){//para el metodo de remove usaremos un arreglo dinamico auxiliar para que posteriormente este reemplace al arreglo en cuestion
    Point *tmp = new Point[size-1];//creamos el arreglo temporal o auxiliar
    int count=0;//usaremos un contador para hacer el intercambio siendo este aparte de la variable iteradora
    for(int i=0;i<size;i++){
        if(i!=pos){//si la variable iteradora es diferente a la posicion entonces se almacenara el objeto en la lista auxiliar 
            tmp[count]=arr[i];//se efectua la asignacion
            count+=1;//el contador se incrementa ya que entra en la condicion
        }

    }
    delete[]arr;//liberamos el bloque de bytes reservado con anterioridad
    size-=1;//disminuimos el tamaño en 1 para que este sea nuestro nuevo arreglo eliminando el objeto que decidimos remover
    arr=tmp;//igualamos los arreglos haciendo que los atributos de cada objeto almacenado en el arreglo principal se igualen al auxiliar que usamos
}
DynamicArray::~DynamicArray()
{
    delete []arr;
}
