// implementacion de la clase inventarrio, esta clase es la que se encarga de
// manipular la cantidad de objetos de la tienda, anadirlos, removerlos, etc

#include "Producto.cpp"
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Inventario {
public:
  // Constructores
  Inventario(string sNombre, int iId);
  // Getters
  // Obtiene el nombre del Inventario
  string GetName();
  // obtiene el id del inventario
  int GetId();
  // Reinicia el id de los productos del Inventario
  void ReseetIdProductos();
  // Obtiene la cantidad de productos del Inventario
  int Size();
  // Devuelve el ultimo producto presente en el Inventario
  string GetLastProduct();
  // Devuelve el primer producto del Inventario
  string GetFirstProduct();
  // Devuelve la cantidad en existencia de un producto del Inventario
  int GetCantidadProduct(int iIdProducto);
  // Devuelve el producto que se desea buscar segun el id
  Producto FindProduct(int iIdProducto);

  // Setters
  // Metodos de manipulacion de los productos
  // metodo agregar Producto
  void addProduct(string sNombreProducto, float fPrecioProducto,
                  int iCantidadProducto, bool bStatus);
  // metodo para cambiar estado de un producto
  void SetStatusProduct(int iIdProducto, bool bStatusProducto);
  // metodo para buscar un producto por su id
  string GetProductName(int iIdProducto);
  // metodo para mostrar producto
  void MostrarProducto(int iIdProducto);
  // asigna la cantidad en existencia de un producto en el inventario
  bool SetCantidadProducto(int iIdProducto, char cAddOrRest, int cCantidad);
  // metodo que despliega una lista de todos los productos del inventario
  void MostrarInventario();
  // metodo cargar inventario desde archivo
  void File2Inventario(string sArchivo);
  // metodo para imprimir el inventario en un archivo
  void Inventario2File(string sArchivo);
  // establece el nombre del archivo con que fue cargado el inventario
  void SetArchivo(string sArchivo);
  // obtiene el nombre del archivo con que fue cargado el inventario
  string GetArchivo();
  // vacia el inventario, borra los productos cargados y el archivo cargado
  int VaciarInventario();

private:
  vector<Producto> aProductos;
  // vector<string> idsList;
  string sNombreInventario;
  int iIdInventario;
  bool bInventCargado;
  string sArchivoCargado;
  int iIdProducto = 1;

}; // Class Inventario

// Metodo constructor de la clase Inventario
//******************************************************************************
Inventario::Inventario(string sNombre, int id) {
  sNombreInventario = sNombre;
  iIdInventario = id;
  bInventCargado = false;
  // Inventario::addProduct("vacio", 0, 0, 0);
} // constructor Inventario

//******************************************************************************

// Metodo que obtiene el nombre del Inventario
//******************************************************************************
string Inventario::GetName() { return sNombreInventario; } // GetName
//******************************************************************************

// Metodo que obtiene el id del Inventario
//******************************************************************************
int Inventario::GetId() { return iIdInventario; } // GetName
//******************************************************************************

// Metodo que obtiene el nombre del archivo cargado en el Inventario
//******************************************************************************
string Inventario::GetArchivo() { return sArchivoCargado; } // GetArchivo
//******************************************************************************

// Metodo que obtiene el nombre del archivo cargado en el Inventario
//******************************************************************************
void Inventario::SetArchivo(string sArchivo) {
  sArchivoCargado = sArchivo;
  bInventCargado = true;
} // GetArchivo
//******************************************************************************

// Reinicia el id de los productos del inventario
//******************************************************************************
void Inventario::ReseetIdProductos(){
  iIdProducto = 1;
}// ReseetIdProductos
//******************************************************************************

// devuelve la cantidad en existencia de un producto en el inventario
//******************************************************************************
int Inventario::GetCantidadProduct(int iIdProducto) {
  return aProductos[iIdProducto - 1].GetCantidad();
} // GetCantidadProduct
//******************************************************************************

// devuelve la cantidad en existencia de un producto en el inventario
//******************************************************************************
int Inventario::VaciarInventario() {
  aProductos.clear();
  bInventCargado = false;
  return 0;
} // VaciarInventario
//******************************************************************************

// asigna la cantidad en existencia de un producto en el inventario
//******************************************************************************
bool Inventario::SetCantidadProducto(int iIdProducto, char cAddOrRest,
                                     int cCantidad) {
  bool exito; // retorna 1 si fue exitosa la actualizacion caso contrario 0
  int cCantidadActual = aProductos[iIdProducto - 1].GetCantidad();
  if (cAddOrRest == '+') {
    cCantidadActual = cCantidadActual + cCantidad;
    exito = true;
  } else if (cAddOrRest == '-') {
    if (cCantidadActual >= cCantidad) {
      cCantidadActual = cCantidadActual - cCantidad;
      exito = true;
    } else {
      exito = false;
    }
  }

  aProductos[iIdProducto - 1].SetCantidad(cCantidadActual);

  if (cCantidadActual == 0) {
    SetStatusProduct(iIdProducto, false);
  }

  return exito;
} // SetCantidadProducto
//******************************************************************************

// Consulta la cantidad de productos en el Inventario
//******************************************************************************
int Inventario::Size() { return aProductos.size(); } // GetCantProduct
//******************************************************************************

// Devuelve el nombre ultimo producto del Inventario
//******************************************************************************
string Inventario::GetLastProduct() {
  // nombre =
  // return
} // GetLastProduct
//******************************************************************************

// Devuelve el producto deseado segun su id
//******************************************************************************
Producto Inventario::FindProduct(int iIdProducto) {
  // cout << "\nSu producto es :\n";
  return aProductos[iIdProducto - 1];
} // GetLastProduct
//******************************************************************************

// Metodo para agregar un producto al Inventario
//******************************************************************************
void Inventario::addProduct(string sNombreProducto, float fPrecioProducto,
                            int iCantidadProducto, bool bStatus) {
  // static int iId = 1;
  int iId = iIdProducto;
  Producto producto1(iId, sNombreProducto, fPrecioProducto, iCantidadProducto,
                     bStatus);
  aProductos.push_back(producto1);
  iId++;
  cout << " agregado: " << producto1;
  iIdProducto++;
  // cout << iId << endl; // linea para probar el valor del id
} // addProduct
//******************************************************************************

// cambia el status de un producto dentro del Inventario
//******************************************************************************
void Inventario::SetStatusProduct(int iIdProducto, bool bStatusProducto) {
  aProductos[iIdProducto - 1].SetStatus(bStatusProducto);
} // SetStatusProduct
//******************************************************************************

// imprime un producto en pantalla
//******************************************************************************
void Inventario::MostrarProducto(int iIdProducto) {
  cout << aProductos[iIdProducto - 1];
} // MostrarProducto
//******************************************************************************

// muestra todos los productos dentro del Inventario
//******************************************************************************
void Inventario::MostrarInventario() {
  // int tamano = aProductos.size();
  int tamano = Inventario::Size();
  // std::cout << tamano << "\n";
  cout << flush;
  cout << right << setfill('-') << setw(52) << "-" << endl
       << setfill(' ') << "|" << setw(5) << "id" << setw(14) << "nombre"
       << setw(12) << "precio" << setw(10) << "cant." << setw(9) << "status"
       << "|" << endl
       << setfill('-') << setw(52) << "-" << endl;
  for (int i = 1; i <= tamano; i++) {
    int id = aProductos[i - 1].GetCodigo();
    string nombre = aProductos[i - 1].GetNombre();
    float precio = aProductos[i - 1].GetPrecio();
    int cantidad = aProductos[i - 1].GetCantidad();
    bool status = aProductos[i - 1].GetStatus();

    cout << setfill(' ') << "| " << setw(5) << id << " "
         << "| " << setw(12) << nombre << " "
         << "| " << setw(8) << precio << " "
         << "| " << setw(7) << cantidad << " "
         << "| " << setw(3) << status << "  |" << endl;
    // Inventario::MostrarProducto(i);
  } // end for
  cout << setfill('-') << setw(52) << "-" << endl;
} // MostrarInventario
//******************************************************************************

// carga los productos del fichero .txt dentro del Inventario
//******************************************************************************
void Inventario::File2Inventario(string sArchivo) {
  bool bErrorEnLectura = false;
  // int iCodigo;
  const int ATTPROD = 10;
  string sNombre;
  float fPrecio;
  int iCantidad;
  bool bStatus;
  string sLine;
  vector<string> sProductoLeido(ATTPROD);
  string sValor;
  if (!bInventCargado) {
    ifstream InArchivo(sArchivo); // se crea el buffer para el archivo
    while (getline(InArchivo, sLine)) {
      istringstream sSplitLine(sLine);
      int i = 0;
      while (i < ATTPROD) {
        sSplitLine >> sValor;
        sProductoLeido[i] = sValor;
        i++;
        //   cout << sLine << endl; //   cout << sValor << endl;
      } // while
      sNombre = sProductoLeido[3];
      //   iCantidad = stoi(sProductoLeido[7]);

      //*********************************************************************
      try {
        // throw(stoi(sProductoLeido[7]));
        if (!stoi(sProductoLeido[7]))
          throw iCantidad = stoi(sProductoLeido[7]);
        iCantidad = stoi(sProductoLeido[7]);

        if (!stof(sProductoLeido[5]))
          throw fPrecio = stof(sProductoLeido[5]);
        fPrecio = stof(sProductoLeido[5]);

        if (!stoi(sProductoLeido[9]))
          throw bStatus = stoi(sProductoLeido[9]);
        bStatus = stoi(sProductoLeido[9]);

      } catch (...) {
        bErrorEnLectura = true;
      }
      //*********************************************************************

      // cout << sNombre << "\n"; // cout << fPrecio << "\n";
      // cout << iCantidad << "\n";// cout << bStatus << "\n";
      // cout << "-----------------" << endl;

      Inventario::addProduct(sNombre, fPrecio, iCantidad, bStatus);

    } // while
    if (!bErrorEnLectura) {
      SetArchivo(sArchivo);
      system("clear");
      cout << "\nSe ha cargado el Inventario \"" << GetName()
           << "\" con el contenido del archivo: " << GetArchivo() << endl;
    } // if error lectura
    else {
      system("clear");

      cout << "error en lectura de archivo" << endl;
      VaciarInventario();
      bErrorEnLectura = false;
    }
  } // if archivo cargado
  else {
    cout << "\nEl Inventario \"" << GetName()
         << "\" ya ha sido cargado con el archivo: " << GetArchivo() << endl;
  }
}
//******************************************************************************

// imprime todos los productos del inventario en un archivo .txt
//******************************************************************************
void Inventario::Inventario2File(string sArchivo) {
  ofstream OutArchivo(sArchivo);
  int iTamano = aProductos.size();
  // std::cout << tamano << "\n";
  for (int i = 0; i < iTamano; i++) {
    // Inventario::MostrarProducto(i);
    OutArchivo << aProductos[i];
  } // end for

  cout << "\nInventario impreso en archivo " << sArchivo << endl;

} // Inventario2File

//******************************************************************************
