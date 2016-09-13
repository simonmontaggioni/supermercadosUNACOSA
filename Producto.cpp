//******************************************************************************
//
//  clase que describe la implementacion de un objeto producto
//  que va a formar parte de un objeto de orden superior almacen
//
//******************************************************************************
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Clsse que modela los atrubutos y funciones de un producto del inventario
class Producto {
public:
  // METODOS PUBLICOS PARA LA CLASE PRODUCTO
  //******************************************************************************
  // Constructores
  Producto(int codigo, string sNombre, float fPrecio, int iCantidad,
           bool bStatus);

  // Getters
  int GetCodigo(void);
  float GetPrecio(void);
  string GetNombre(void);
  bool GetStatus(void);
  int GetStockMin(void);
  int GetCantidad(void);
  //    void imprimir();
  // Setters
  void SetStatus(bool bStatus);
  void SetCantidad(int iCantidad);
  // Friends functions
  friend ostream &operator<<(ostream &out, const Producto &producto);
  //******************************************************************************
private:
  // ATRIBUTOS DE LA CLASE PRODUCTO
  //******************************************************************************
  string sNombreProducto;
  float fPrecioProducto;
  int iCodigoProducto;
  bool bStatusProducto;
  int iStockMinProducto;
  int iCantidadProducto;
  //******************************************************************************
}; // class Producto

// Constructor del objeto tipo producto
//******************************************************************************
Producto::Producto(int iCodigo, string sNombre, float fPrecio, int iCantidad,
                   bool bStatus) {
  iCodigoProducto = iCodigo;
  sNombreProducto = sNombre;
  fPrecioProducto = fPrecio;
  bStatusProducto = bStatus;
  iStockMinProducto = 1;
  iCantidadProducto = iCantidad;
} // constructor
//******************************************************************************

// Metodo get para obtener el codigo ID del producto
//******************************************************************************
int Producto::GetCodigo() { return iCodigoProducto; } // Getcodigo
//******************************************************************************

// Metodo get para obtener el bStatus del producto
//******************************************************************************
string Producto::GetNombre() { return sNombreProducto; } // GetNombre
//******************************************************************************

// Metodo get para obtener el precio del producto
//******************************************************************************
float Producto::GetPrecio() { return fPrecioProducto; } // GetPrecio
//******************************************************************************

// Metodo para pbtener es Status del producto
//******************************************************************************
bool Producto::GetStatus() { return bStatusProducto; } // GetStatus
//******************************************************************************

//******************************************************************************
// solicita la cantidad en existencia de un producto
int Producto::GetCantidad(void) { return iCantidadProducto; } // GetCantidad
//******************************************************************************

// Metdodo para solicitar el stock minimo de un producto
//******************************************************************************
int Producto::GetStockMin(void) { return iStockMinProducto; } // GetStockMin
//******************************************************************************

// Metdodo para asignar el estado a un producto
//******************************************************************************
void Producto::SetStatus(bool bStatus) {
  bStatusProducto = bStatus;
} // SetStatus
//******************************************************************************

//******************************************************************************
// solicita la cantidad en existencia de un producto
void Producto::SetCantidad(int iCantidad) {
  iCantidadProducto = iCantidad;
} // SetCantidad
//******************************************************************************

// Sobrecarga del operador << para la clase Producto
//******************************************************************************
std::ostream &operator<<(std::ostream &salida, const Producto &producto) {
  //    string nombre = p.GetNombre();
  //    float fPrecio = p.GetPrecio();
  salida << setfill(' ') << "id: " << left << setw(3)
         << producto.iCodigoProducto << " "
         << "nombre: " << left << setw(15) << producto.sNombreProducto << " "
         << "precio: " << left << setw(5) << producto.fPrecioProducto << " "
         << "cantidad: " << left << setw(3) << producto.iCantidadProducto << " "
         << "status: " << left << setw(2) << producto.bStatusProducto << "\n";
} // sobrecarga ostream
