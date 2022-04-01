#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombre_archivo  = "archivo.dat";
const char *archivo_temporal  = "temporal.dat";

struct Estudiante{
	int codigo;
	char nombre[50],p_nombre;
	char apellido[50],p_apellido;
	char direccion[50],p_direccion;
	int telefono,p_telefono;
};
void menu();
 void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
 void buscar_codigo();
 void eliminar_estudiante();
int main (){
	menu();
 	return 0;	
}
void menu(){
	int op;
	do{
		cout<<"__________________Menu__________________"<<endl;
		cout<<"1. Ingresar un estudiante"<<endl;
		cout<<"2. Mostrar los datos de un estudiante"<<endl;
		cout<<"3. Modificar los datos de un estudiante"<<endl;
		cout<<"4. Eliminar los datos de un estudiante"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		
		switch (op){
			case 1: ingresar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 2: abrir_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 3: modificar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 4: eliminar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
		}
		system("cls");
	}while(op!=5);
}


void buscar_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Direccion: "<<estudiante.direccion<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}

void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
		cout <<"Direccion: "<<estudiante.direccion<<endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"_______________________________________________________________________________________________________"<<endl;
	cout <<"| "<< "id" <<" | "<< "CODIGO" <<" | "<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"DIRECCION"<<" | "<<"TELEFONO"<<" | "<<endl;	
		do{
		cout<<"____________________________________________________________________________________________________"<<endl;
		cout <<"| "<< registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre <<" | "<< estudiante.apellido <<" | "<< estudiante.direccion <<" | "<< estudiante.telefono<<" | "<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab");
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 

		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
				
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}

void eliminar_estudiante() {

		FILE *archivo, *archivo_temp; 
	archivo_temp=fopen(archivo_temporal,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	int codigo; 
	Estudiante estudiante; 

	                      				                
	cout<<"INGRESE CODIGO DEL ESTUDIANTE A ELIMINAR: "<<endl; 
		cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			
			if (codigo != estudiante.codigo) {
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
			else{
			}
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	
	remove("Archivo.dat");
	rename("temporal.dat", "Archivo.dat");
	
	}