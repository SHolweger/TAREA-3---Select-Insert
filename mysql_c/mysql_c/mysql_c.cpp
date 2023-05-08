#include <mysql.h>
#include <iostream>

using namespace std;
int q_estado;
MYSQL_ROW fila;
MYSQL_RES* resultado;

int main(){
	MYSQL* conectar;
	conectar = mysql_init(0) ;
	conectar = mysql_real_connect(conectar,"localhost", "root","Umg$2023","db_empresa",3306,NULL,0 );

	if (conectar){
		cout << "CONEXION EXITOSA" << endl;
        system("pause");
        system("cls");
        /*string puesto;
		cout << "Ingrese un Puesto: ";
		cin >> puesto;	
		string insert = "insert into puestos(puesto) values('" + puesto + "') ";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            system("cls");
            cout << "Ingreso exitoso!" << endl;
        }
        else {
            system("cls");
            cout << "xxxx ERROR AL INGRESAR xxxx";
        }*/

        string consulta = "SELECT *FROM puestos";
        const char* x = consulta.c_str();
        q_estado = mysql_query(conectar, x);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << "id_puesto: " << fila[0] << endl;
                cout << "puesto: " << fila[1] << endl;
            }
        }
    }
    else {
        cout << "Error en la conexion" << endl;
    }
    return 0;
}
