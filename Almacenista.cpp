#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
//#include "Producto.cpp" //inclusion de la implementacion de la clase Producto
#include "Inventario.cpp"
#include "TransaccionH.cpp"

class Almacenista {
public:
  // Constructores
  Almacenista(string sNombre);

  // Metodos
  // crear inventario
  void CrearInventario();
  // crear Transaccion
  void CrearTransaccion();
  // Busca un producto en el invantario
  void BuscarProducto(int iIdInventario);
  // matching entre inventario y Transaccion
  void CompararInvenTrans(int iIdInventario);
  // cargar producto manualmente
  void CargaManual(int iIdInventario);
  // cargar archivo en inventario
  void CargarArchivoInventario(int iIdInventario);
  // cargar archivo de Transaccion
  void CargarArchivoTransaccion();
  // contabilizar ventas
  void ContabilizarVentas();
  // contabilizartransacciones actualizadas
  void ContabilizarTransacciones();
  // actualiza el stock de un producto
  bool UpdateCantidadProducto(int iIdInventario);
  // mostrar inventario en uso
  void MostrarInventario(int iIdInventario);
  // mostrar archimo transacciones();
  void MostrarTransaccion();
  // imprimir inventario actualizado
  void ImprimirInventario(int iIdInventario);
  // imprimir inventario viejo
  void ImprimirInventarioOld(int iIdInventario);
  // imprimir transacciones
  void ImprimirTransacciones();
  // obtiene la cantidad en existencia de un producto
  void ObtenerExistenciaProducto(int iIdInventario);
  // obtiene la cantidad de transaccion de un producto
  void ObtenerTransaccionProducto();
  // vaia un inventario
  void VaciarInventario();
  // mustra una lista de los inventarios que contiene el sistema
  void MostrarListaInventarios();
  //imprime una orden de compra para productos que estan por debajo del stock minimo
  void OrdenCompra(int iIdInventario);
  //  dvuelve la cantidad de inventarios que pertenecen al almacenista
  int CantInventarios();

private:
  string sNombreAlmacenista;
  vector<Inventario> aInventarios;
  vector<Transaccion> aTransacciones;
  // Inventario miInventario("h");
  // Transaccion miTransaccion();

}; // fin class Almacenista

// metodo constructor
//******************************************************************************
Almacenista::Almacenista(string sNombre) {
  sNombreAlmacenista = sNombre;

} // Almacenista
//******************************************************************************

// metodo para crear inventario
void Almacenista::CrearInventario() {
  string sNombreInventario;
  static int iIdInventario = 0;
  cout << endl;
  cout << "Ingrese el nombre del inventario que desea crear: ";
  cin >> sNombreInventario;
  Inventario inventario(sNombreInventario, iIdInventario);
  aInventarios.push_back(inventario);

  // cout << iIdInventario << endl;
  cout << "Se ha creado con exito el inventario " << endl
       << "id: " << aInventarios[iIdInventario].GetId()
       << " nombre: " << sNombreInventario << endl;

  iIdInventario++;
  // Inventario miInventario("inventario");
} // CrearInventario
//******************************************************************************

// metodo para crear Transaccion
//******************************************************************************
void Almacenista::CrearTransaccion() {
  string sNombreTransaccion = "transacciones";
  // cout << "Ingrese el nombre de la operacion transacciones que desea crear:
  // ";
  // cin >> sNombreTransaccion;
  Transaccion transaccion(sNombreTransaccion);
  aTransacciones.push_back(transaccion);
} // CrearTransaccion
//******************************************************************************

// metodo para crear Transaccion
//******************************************************************************
void Almacenista::BuscarProducto(int iIdInventario) {
  int iId;
  cout << "Indique el id del producto que desea buscar: ";
  cin >> iId;
  cout << aInventarios[iIdInventario].FindProduct(iId);
  // aInventarios[0].MostrarProducto(iId);
} // CrearTransaccion
//******************************************************************************

// carga el inventario con un archivo de texto
//******************************************************************************
void Almacenista::CargarArchivoInventario(int iIdInventario) {
  string sMiArchivo;
  char cOpcion;
  cout << " Digite el nombre del archivo de inventario que desea cargar: ";
  cin >> sMiArchivo;

  cout << "Va a cargar el inventario \"" << aInventarios[iIdInventario].GetName()
       << "\" con el archivo \"" << sMiArchivo << "\"" << endl << endl;
  cout << "presione (y) para continuar o cualquier tecla para cancelar"<< endl
       << ">>> ";
  cin >> cOpcion;

  if (cOpcion == 'y'){
    aInventarios[iIdInventario].File2Inventario(sMiArchivo);
  } else {
    cout << endl << "Carga cancelada";
  }


} // CargarArchivoInventario
//******************************************************************************

// carga el archivo de transacciones
//******************************************************************************
void Almacenista::CargarArchivoTransaccion() {
  string sMiArchivo;
  cout << " Digite el nombre del archivo de transacciones que desea cargar: ";
  cin >> sMiArchivo;

  aTransacciones[0].File2Transaccion(sMiArchivo);
} // CargarArchivoTransaccion
//******************************************************************************

// cargar producto manualmente
//******************************************************************************
void Almacenista::CargaManual(int iIdInventario) {
  char salir = 'n';
  string sNombreProducto;
  float fPrecioProducto;
  int iCantidadProducto;
  bool bExistencia;
  char cRespuesta;

  cout << "Cargar producto manualmente?: (y/n) ";
  cin >> salir;
  if (salir == 'y') {
    while (salir != 'n') { // carga de productos manualmente
      cout << "Ingrese nombre de producto: ";
      cin >> sNombreProducto;
      cout << "Ingrese precio del producto: ";
      cin >> fPrecioProducto;
      cout << "Ingrese cantidad de unidades del producto: ";
      cin >> iCantidadProducto;
      cout << "Producto en existencia? (y/n) ";
      cin >> cRespuesta;

      if (cRespuesta == 'y') {
        bExistencia = true;
      } else {
        bExistencia = false;
      } // endif

      aInventarios[iIdInventario].addProduct(sNombreProducto, fPrecioProducto,
                                             iCantidadProducto, bExistencia);

      cout << " Continuar carga manual? (y/n) ";
      cin >> salir;
    } // end while
  }   // if
}
//******************************************************************************

// contabiliza las ventas realizadas
//******************************************************************************
void Almacenista::ContabilizarVentas() {
  // mucho codigo aqui
} // ContabilizarVentas
//******************************************************************************

// contabilizartransacciones actualizadas
//******************************************************************************
void Almacenista::ContabilizarTransacciones() {
  // mucho codigo aqui
} // contabilizartransacciones
//******************************************************************************

// moatrar inventario en uso
//******************************************************************************
void Almacenista::MostrarInventario(int iIdInventario) {
  cout << "El inventario es: " << aInventarios[iIdInventario].GetName() << endl
       << "con Id: " << aInventarios[iIdInventario].GetId() << endl
       << "Los productos inventariados son: \n";
  aInventarios[iIdInventario].MostrarInventario();
} // MostrarInventario
//******************************************************************************

// moatrar inventario en uso
//******************************************************************************
void Almacenista::MostrarTransaccion() {
  cout << "El archivo de transaccion en uso es: " << aTransacciones[0].GetName()
       << endl;
  cout << "Las transacciones sol las siguientes: \n\n ";
  aTransacciones[0].MostrarTransaccion();

  cout << endl
       << " Cantidad de transacciones realizadas: "
       << aTransacciones[0].GetTotalTransacciones() << endl;
} // MostrarTransaccion
//******************************************************************************

// imprimir inventario actualizado
//******************************************************************************
void Almacenista::ImprimirInventario(int iIdInventario) {
  string miArchivo;
  cout << "Elija archivo a guardar: ";
  cin >> miArchivo;
  aInventarios[iIdInventario].Inventario2File(miArchivo);
} // ImprimirInventario
//******************************************************************************

// imprimir inventario viejo
//******************************************************************************
void Almacenista::ImprimirInventarioOld(int iIdInventario) {
  string miArchivo;
  cout << "Elija archivo a guardar: ";
  cin >> miArchivo;
  aInventarios[iIdInventario].Inventario2File(miArchivo);
} // ImprimirInventarioOld
//******************************************************************************

// imprimir transacciones
//******************************************************************************
void Almacenista::ImprimirTransacciones() {
  string miArchivo;
  cout << "Elija archivo a guardar: ";
  cin >> miArchivo;
  aTransacciones[0].Transaccion2File(miArchivo);
} // ImprimirTransacciones
//******************************************************************************

// asigna la cantidad en existencia de un producto en el inventario
//******************************************************************************
bool Almacenista::UpdateCantidadProducto(int iIdInventario) {
  int iIdProducto;
  int cCantidad;
  bool exito;
  char cAddOrRest;

  cout << "indique el id del producto a actualizar el stock: ";
  cin >> iIdProducto;
  cout << "(+) agregar, (-) restar: ";
  cin >> cAddOrRest;
  cout << "indique la cantidad: ";
  cin >> cCantidad;
  // cAddOrRest = (cCantidad >= 0) ? '+' : '-'; // operador ternario
  exito = aInventarios[iIdInventario].SetCantidadProducto(
      iIdProducto, cAddOrRest, cCantidad);
  if (!exito) {
    cout << "No se puede disminuir el stock en esa cantidad.";
  } else {
    cout << "Se ha actualizado el stock del producto.";
  }
  return exito;
}
//******************************************************************************

// matching entre inventario y Transaccion
//******************************************************************************
void Almacenista::CompararInvenTrans(int iIdInventario) {
  int iContadorActualizaciones = 0;
  int iCantTrans = aTransacciones[0].GetTotalTransacciones();
  for (int i = 1; i < iCantTrans; i++) { // matching entre los archivos
    int cCantidad = aTransacciones[0].GetCantidadTransaccion(i);
    int iIdProducto = aTransacciones[0].GetIdProdTransaccion(i);
    char cAddOrRest = '-';

    if (aInventarios[iIdInventario].SetCantidadProducto(iIdProducto, cAddOrRest,
                                                        cCantidad)) {
      iContadorActualizaciones++;
      cout << "El producto: "
           << aInventarios[iIdInventario].FindProduct(iIdProducto)
           << " se ha actualizado!!!" << endl;
    } // endif
  }   // endfor
  cout << "\nSe realizaron " << iContadorActualizaciones
       << " actualizaciones.\n";
}
//******************************************************************************

// obtener existencia de producto
//******************************************************************************
void Almacenista::ObtenerExistenciaProducto(int iIdInventario) {
  int iIdProducto;
  cout << "Indique el id del producto del que desea conocer su existencia: ";
  cin >> iIdProducto;

  cout << aInventarios[iIdInventario].GetCantidadProduct(iIdProducto) << endl;
}
//******************************************************************************

// obtener la cantidad de transaccion  de producto
//******************************************************************************
void Almacenista::ObtenerTransaccionProducto() {
  int iNumTransacion;
  cout << "Indique el numero de transaccion para conocer cantidad: ";
  cin >> iNumTransacion;

  cout << aTransacciones[0].GetCantidadTransaccion(iNumTransacion) << endl;
  cout << aTransacciones[0].GetIdProdTransaccion(iNumTransacion) << endl;
}
//******************************************************************************

// obtener la cantidad de transaccion  de producto
//******************************************************************************
void Almacenista::VaciarInventario() {
  int iIdInventario;
  char opcion;
  cout << "Indique el id del inventario que desea vaciar: ";
  cin >> iIdInventario;

  try {
    if (cin.fail())
      throw iIdInventario;

    if (iIdInventario > aInventarios.size())
      throw iIdInventario;
    if (iIdInventario < 0)
      throw iIdInventario;

    cout << "esta seguro que desea vaciar el inventario  id: "
         << aInventarios[iIdInventario].GetId()
         << " nombre: " << aInventarios[iIdInventario].GetName() << " (y/n) ";
    cin >> opcion;

    if ('y' == opcion) {
      aInventarios[iIdInventario].VaciarInventario();
      aInventarios[iIdInventario].ReseetIdProductos();
      cout << "Se ha vaciado el inventario "
           << aInventarios[iIdInventario].GetId()
           << " nombre: " << aInventarios[iIdInventario].GetName();
    } else {
      cout << "operacion cancelada,";
    }
  } // try
  catch (...) {
    cout << endl << "Error en el id del inventario." << endl;
  } // catch
} // VaciarInventario
//******************************************************************************

// muestra una lista de los inventarios que existen en el sitema
//******************************************************************************
void Almacenista::MostrarListaInventarios() {

  int tamano = aInventarios.size();

  if (tamano == 0) {
    cout << endl << " No se ha creado ningun inventario. " << endl;
  } else {
    cout << endl << endl;
    cout << "----------------------------" << endl;
    cout<<"| id " << "| nombre inventario   |" << endl;
    cout << "----------------------------";
    for (int i = 0; i < tamano; i++) {
      cout << endl << setfill(' ')
      << "| "<< setw(2) << aInventarios[i].GetId() << " |"
      << setw(20) << aInventarios[i].GetName() << " |";
    } // for
    cout << endl << "----------------------------" << endl;
  }   // else
} // MostrarListaInventarios
//******************************************************************************


//imprime una orden de compra para productos que estan por debajo del stock minimo
//******************************************************************************
void Almacenista::OrdenCompra(int iIdInventario) {
  int iIdProducto;
  int iCantidadProductos = 0;
  int iExistenciaProducto = 0;
  char cOpcion;

  iCantidadProductos = aInventarios[iIdInventario].Size();

  cout << endl
       << "   Inventario: \"" <<aInventarios[iIdInventario].GetName() <<"\"" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "|      O R D E N   D E  C O M P R A S        |" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "|  Productos por adquirir:                   |"<<endl;
  cout << "----------------------------------------------" << endl;
  cout<<"| id " << "|   nombre Producto   |"<< " cant a adquirir |" << endl;
  cout << "----------------------------------------------";

  for (int iIdProducto = 1; iIdProducto <= iCantidadProductos; iIdProducto++){
    iExistenciaProducto = aInventarios[iIdInventario].GetCantidadProduct(iIdProducto);
    if (iExistenciaProducto < 6){

      cout << endl << right << setfill(' ')
      << "| "<< setw(2) << iIdProducto << " |"
      << setw(20) << aInventarios[iIdInventario].GetProductName(iIdProducto) << " |"
      << setw(16) << 10 << " |";
    }
  } // for
  cout << endl << "----------------------------------------------" << endl;
  cout << "desea imprimir? (y/n)" << endl;
  cout << ">>> ";
  cin >> cOpcion;
  if (cOpcion == 'y'){

    ofstream OutOrden("Orden de compra para inventario"+aInventarios[iIdInventario].GetName());
    OutOrden << endl
         << "   Inventario: \"" <<aInventarios[iIdInventario].GetName() <<"\"" << endl
         << "----------------------------------------------" << endl
         << "|      O R D E N   D E  C O M P R A S        |" << endl
         << "----------------------------------------------" << endl
         << "|  Productos por adquirir:                   |"<<endl
         << "----------------------------------------------" << endl
         <<"| id " << "|   nombre Producto   |"<< " cant a adquirir |" << endl
         << "----------------------------------------------";

    for (int iIdProducto = 1; iIdProducto <= iCantidadProductos; iIdProducto++){
      iExistenciaProducto = aInventarios[iIdInventario].GetCantidadProduct(iIdProducto);
      if (iExistenciaProducto < 6){

        OutOrden<< endl << right << setfill(' ')
        << "| "<< setw(2) << iIdProducto << " |"
        << setw(20) << aInventarios[iIdInventario].GetProductName(iIdProducto) << " |"
        << setw(16) << 10 << " |";
      }
    } // for
    OutOrden << endl << "----------------------------------------------" << endl;

  }//if imprimir orden

}
//******************************************************************************

// obtener la cantidad de inventarios del almacenista
//******************************************************************************
int Almacenista::CantInventarios() {
  return aInventarios.size();
}
//******************************************************************************
