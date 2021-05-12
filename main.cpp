#include <iostream>
#include <conio.h>
#include "DynamicArray.cpp"

using namespace std;

int main() {
    int position,insertX,insertY,positionRemove;
    Point arr[4];//usaremos un arreglo de objetos Point para usarlo como parametro en nuestro objeto DynamicArray
    int tam = sizeof(arr) / sizeof(arr[0]);//sacamos el arreglo manualmente por codigo
    DynamicArray q(arr, tam);//creamos nuestro objeto DynamicArray
    q.LLenarArray();
    q.ImprimirArray();
    cout<<"Ingrese la posicion del arreglo en la que insertara el objeto punto ";
    cin>>position;
    cout<<endl;
    cout<<"Ingrese la coordena x: ";
    cin>>insertX;
    cout<<endl;
    cout<<"Ingrese la coordena y: ";
    cin>>insertY;
    Point element;
    element.setX(insertX);
    element.setY(insertY);
    q.insert(element,position);
    q.ImprimirArray();
    cout<<endl;
    cout<<"A continuacion se eliminara un objeto de la lista mencione la posicion de la cual se borrara dicho elemento: ";
    cin>>positionRemove;
    q.remove(positionRemove);
    q.ImprimirArray();
    getch();
    system("pause");
    return 0;

}