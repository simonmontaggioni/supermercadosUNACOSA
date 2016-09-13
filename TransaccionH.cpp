// clase Transaccion, que hereda sus metodos y ATRIBUTOS
// de la clase Transaccion, con la diferencia de que algunos metodos son
// modificados para que los productos cargados no puedan ser manipulados

// #include "Producto.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Transaccion {
public:
  // Constructores
  Transaccion(string sNombre);
  // // Getters
  // // Obtiene el nombre del Transaccion
  string GetName();
  // // Obtiene la la cantidad de Transaccion del productos
  int GetCantidadTransaccion(int iNumTransacion);
  // obtiene el id del producto del numero de Transaccion seleccionada
  int GetIdProdTransaccion(int iNumTransacion);
  // int Size();
  // // Devuelve el ultimo producto presente en el Transaccion
  // string GetLastProduct();
  // // Devuelve el primer producto del Transaccion
  // string GetFirstProduct();
  // // Devuelve el producto que se desea buscar segun el id
  Producto FindProduct(int iIdProducto);
  //
  // // Setters
  // // Metodos de manipulacion de los productos
  // // metodo agregar Producto
  void addProduct(int iId, string sNombreProducto, float fPrecioProducto,
                  int iCantidadProducto, bool bStatus);
  // // metodo para cambiar estado de un producto
  // void SetStatusProduct(int iIdProducto, bool bStatusProducto);
  // metodo para buscar un producto por su id
  string GetProductName(int iIdProducto);
  // // metodo para mostrar producto
  void MostrarProducto(int iIdProducto);
  // // metodo que despliega una lista de todos los productos del inventario
  void MostrarTransaccion();
  // metodo cargar inventario desde archivo
  void File2Transaccion(string sArchivo);
  // metodo para imprimir el inventario en un archivo
  void Transaccion2File(string sArchivo);
  // devuelve el total de transacciones
  int GetTotalTransacciones();

private:
  vector<Producto> aProductos;
  // vector<string> idsList;
  string sNombreTransaccion;

}; // Class Transaccion

Transaccion::Transaccion(string sNombre) {
  this->sNombreTransaccion = sNombre;
  // Transaccion::addProduct("vacio", 0, 0, 0);
} // constructor Transaccion
//******************************************************************************

// Metodo que obtiene el nombre del archivo de transacciones
//******************************************************************************
string Transaccion::GetName() { return sNombreTransaccion; } // GetName
//******************************************************************************

// Devuelve el producto deseado segun su id
//******************************************************************************
Producto Transaccion::FindProduct(int iIdProducto) {
  cout << "\nSu producto es :\n";
  return aProductos[iIdProducto - 1];
} // GetLastProduct
//******************************************************************************

// Metodo para agregar un producto al Transaccion
//******************************************************************************
void Transaccion::addProduct(int iId, string sNombreProducto,
                             float fPrecioProducto, int iCantidadProducto,
                             bool bStatus) {
  // static int iId = 1;
  Producto producto1(iId, sNombreProducto, fPrecioProducto, iCantidadProducto,
                     bStatus);
  aProductos.push_back(producto1);
  iId++;
  cout << " agregado: " << producto1;
  // cout << iId << endl; // linea para probar el valor del id
} // addProduct
//******************************************************************************

// imprime un producto en pantalla
//******************************************************************************
void Transaccion::MostrarProducto(int iIdProducto) {
  cout << aProductos[iIdProducto - 1];
} // MostrarProducto
//******************************************************************************

// muestra todos los productos dentro del Transaccion
//******************************************************************************
void Transaccion::MostrarTransaccion() {
  int tamano = aProductos.size();
  // int tamano = Transaccion::Size();
  // std::cout << tamano << "\n";
  for (int i = 1; i <= tamano; i++) {
    Transaccion::MostrarProducto(i);
  } // end for

} // MostrarTransaccion
//******************************************************************************

// carga los productos del fichero .txt dentro del Transaccion
//******************************************************************************
void Transaccion::File2Transaccion(string sArchivo) {
  const int ATTPROD = 10;
  int iId;
  string sNombre;
  float fPrecio;
  int iCantidad;
  bool bStatus;
  string sLine;
  vector<string> sProductoLeido(ATTPROD);
  string sValor;

  aProductos.clear();

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
    iId = stoi(sProductoLeido[1]);
    sNombre = sProductoLeido[3];
    fPrecio = stof(sProductoLeido[5]);
    iCantidad = stoi(sProductoLeido[7]);
    bStatus = stoi(sProductoLeido[9]);

    // cout << sNombre << "\n"; // cout << fPrecio << "\n";
    // cout << iCantidad << "\n";// cout << bStatus << "\n";
    // cout << "-----------------" << endl;

    Transaccion::addProduct(iId, sNombre, fPrecio, iCantidad, bStatus);
    system("clear");
  } // while
  cout << "\nSe ha cargado el archivo \"" << GetName()
       << "\" con el contenido del archivo: " << sArchivo << endl;
}
//******************************************************************************

// imprime todos los productos del inventario en un archivo .txt
//******************************************************************************
void Transaccion::Transaccion2File(string sArchivo) {
  ofstream OutArchivo(sArchivo);
  int iTamano = aProductos.size();
  // std::cout << tamano << "\n";
  for (int i = 0; i < iTamano; i++) {
    // Transaccion::MostrarProducto(i);
    OutArchivo << aProductos[i];
  } // end for

  cout << "\nTransaccion impreso en archivo " << sArchivo << endl;

} // Transaccion2File

//******************************************************************************

// devuelve la cantidad de transacion realizada sobre un producto
//******************************************************************************
int Transaccion::GetCantidadTransaccion(int iNumTransacion) {
  return aProductos[iNumTransacion - 1].GetCantidad();
} // GetCantidadTransaccion
//******************************************************************************

// devuelve la cantidad de transacion realizada sobre un producto
//******************************************************************************
int Transaccion::GetIdProdTransaccion(int iNumTransacion) {
  return aProductos[iNumTransacion - 1].GetCodigo();
} // GetIdProdTransaccion
//******************************************************************************

// devuelve la cantidad de transacion realizada sobre un producto
//******************************************************************************
int Transaccion::GetTotalTransacciones() {
  return aProductos.size();
} // GetIdProdTransaccion
//******************************************************************************
