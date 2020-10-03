#include <iostream>
using namespace std;

struct alumno{
    int calificacion;
    string nombre;
    int matricula;
    alumno *sig;
};

alumno *crear(alumno *);

alumno *insertar(alumno *);

alumno *borrar(alumno *, string );

void buscar(alumno *, string );

void imprimir(alumno *);

int main(){
    alumno *lista = NULL;
    string nombre;
    char letra;

    do{
         system("cls");
        //Aquí muestro las opciones del menú
        cout<<"Digite la opcion a realizar: \n";
        cout<<"a) Insertar un elemento\n";
        cout<<"b) Borrar un estudiante\n";
        cout<<"c) Encontrar a un estudiante\n";
        cout<<"d) Mostrar a todos los estudiantes\n";
        cout<<"e) Salir\n";
        cout<<"----------------------Digite su opcion: ";
        cin>>letra;
        cout<<endl;

        switch(letra){
            case 'a':
                lista = insertar(lista);
            break;

            case 'b':
                cout<<"Digite el nombre a eliminar: ";
                cin>>nombre;
                lista = borrar(lista, nombre);
            break;

            case 'c':
                cout<<"Digite el nombre a buscar: ";
                cin>>nombre;
                buscar(lista, nombre);
            break;

            case 'd':
               imprimir(lista);
            break;

            default:
                cout<<"Usted a presionado una tecla erronea o a decidido salir"<<endl;
                letra = 'e';
            break;
        }
        cout<<endl;
        system("pause");

    }while(letra != 'e');

    return 0;
}

alumno *crear(alumno *lista){
    lista = new alumno;
    cout<<"Digite el nombre: ";
    cin>>lista->nombre;
    cout<<"Digite su matricula: ";
    cin>>lista->matricula;
    cout<<"Digite su calificacion: ";
    cin>>lista->calificacion;

    lista->sig = NULL;
    return lista;
}

alumno *insertar(alumno *lista){
    if(lista == NULL){
        lista = crear(lista);
        return lista;
    }
    alumno *aux = lista;
    alumno *nuevo = crear(nuevo);
    while(aux->sig != NULL && aux->sig->matricula <= nuevo->matricula) aux = aux->sig;
    //Caso 1
    if(aux == lista){
        if(nuevo->matricula < aux->matricula){
            nuevo->sig = lista;
            lista = nuevo;
            return lista;
        }
    }
    //Caso
    if(!aux->sig){
        aux->sig = nuevo;
    }
    else{
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
   return lista;
}

alumno *borrar(alumno *lista, string nombre){
    alumno *aux = lista;
    if(lista->nombre == nombre){
        lista = lista->sig;
        delete aux;
        return lista;
    }
    while( aux->sig && aux->sig->nombre != nombre)aux = aux->sig;
    bool checar = 1;
    if(!aux->sig) checar = 0;
    if(checar ){
        alumno *aux2 = aux->sig;
        aux->sig = aux2->sig;
        delete aux2;
    }
    else{
        cout<<"El elemento no existia en la lista\n";
    }

    return lista;
}


void buscar(alumno *lista, string nombre){
    alumno *aux = lista;
    while(aux && aux->nombre != nombre)  aux = aux->sig;
    cout<<"\n\nEl alumno es: "<<aux->nombre<<endl;
    cout<<"Su matricula es: "<<aux->matricula<<endl;
    cout<<"Su calificacion es: "<<aux->calificacion<<endl;
}

void imprimir(alumno *lista){
    alumno *aux = lista;
    while(aux){
        cout<<"\nEl alumno es: "<<aux->nombre<<endl;
        cout<<"Su matricula es: "<<aux->matricula<<endl;
        cout<<"Su calificacion es: "<<aux->calificacion<<endl;
        aux = aux->sig;
    }
}
