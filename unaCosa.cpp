#include "Almacenista.cpp"
#include <iostream>
// #include <ncurses.h>
#include <string>
#include <vector>

void Mensaje(string sMensaje);
void pausa();
void Bienvenida();
int SolicitudIdInvent(int iCantInventarios);


int main() {

  // Mensaje("B I E N V E N I D O");
  Bienvenida();
  pausa();
  Almacenista almacenista("simon");
  almacenista.CrearTransaccion();

  // almacenista.CrearInventario();
  // almacenista.CargarArchivoInventario();
  // almacenista.CargaManual();
  // almacenista.MostrarInventario();
  // almacenista.ImprimirInventario();
  // almacenista.CargarArchivoTransaccion();
  // almacenista.MostrarTransaccion();
  // almacenista.ImprimirTransacciones();
  // almacenista.BuscarProducto();
  // almacenista.ObtenerExistenciaProducto();
  // almacenista.UpdateCantidadProducto();
  // almacenista.ObtenerExistenciaProducto();
  // almacenista.ObtenerTransaccionProducto();
  // almacenista.CompararInvenTrans();
  // almacenista.MostrarInventario();
  // almacenista.CompararInvenTrans();
  // almacenista.ActualizaInventario();
  // almacenista.SetStatusProducto();
  enum opciones {
    CREARINVENTARIO = 1,
    LISTAINVENTARIOS,
    CARGARARCHIVOINVENTARIO,
    MOSTRARINVENTARIO,
    IMPRIMIRINVENTARIO,
    VACIARINVENTARIO,
    CARGARARCHIVOTRANSACCION,
    MOSTRARTRANSACCION,
    IMPRIMIRTRANSACCIONES,
    COMPARARINVENTRANS,
    IMPRIMIRORDENCOMPRAS,
    SALIR
  };
  int iIdInventario = 0;
  int sChoice;
  bool bInProgram = true;

  while (bInProgram) {
    system("clear");

    cout << endl;
    cout << "************************************************" << endl;
    cout << "************************************************" << endl;
    cout << "**                                            **" << endl;
    cout << "**  Indique la acción que desea realizar:     **\n";
    cout << "**                                            **\n";
    cout << "**  Presione:                                 **\n";
    cout << "**                                            **\n";
    cout << "**  (1)....Crear Inventario.                  **\n";
    cout << "**  (2)....Mostrar lista de Inventarios.      **\n";
    cout << "**  (3)....Cargar Archivo de Inventario.      **\n";
    cout << "**  (4)....Mostrar Inventario.                **\n";
    cout << "**  (5)....Imprimir Inventario.               **\n";
    cout << "**  (6)....Vaciar Inventario.                 **\n";
    cout << "**  (7)....Cargar Archivo de Transacciones.   **\n";
    cout << "**  (8)....Mostrar Transacciones.             **\n";
    cout << "**  (9)....Imprimir Transacciones.            **\n";
    cout << "**  (10)...Actualizar Inventario.             **\n";
    cout << "**  (11)...Imprimir Orden de Compra.          **\n";
    cout << "**  (12)...Salir.                             **\n";
    cout << "**                                            **" << endl;
    cout << "************************************************" << endl;
    cout << "************************************************" << endl;
    cout << endl << ">>> ";
    cin >> sChoice;
    system("clear");

    switch (sChoice) {
    case CREARINVENTARIO:
      almacenista.CrearInventario();
      pausa();
      break;
    case CARGARARCHIVOINVENTARIO:
      // cout <<endl << "Indique el id del inventario: ";
      // cin >> iIdInventario;
      iIdInventario = SolicitudIdInvent( almacenista.CantInventarios());
      if ( iIdInventario != -1 ){
        almacenista.CargarArchivoInventario(iIdInventario);
        pausa();
      }
      break;
    case LISTAINVENTARIOS:
      almacenista.MostrarListaInventarios();
      pausa();
      break;
    case MOSTRARINVENTARIO:
      iIdInventario = SolicitudIdInvent( almacenista.CantInventarios());
      if ( iIdInventario != -1 ){
        almacenista.MostrarInventario(iIdInventario);
        pausa();
      }
      break;
    case IMPRIMIRINVENTARIO:
      iIdInventario = SolicitudIdInvent( almacenista.CantInventarios());
      if ( iIdInventario != -1 ){
        almacenista.ImprimirInventario(iIdInventario);
        pausa();
      }
      break;
    case VACIARINVENTARIO:
      almacenista.VaciarInventario();
      pausa();
      break;
    case CARGARARCHIVOTRANSACCION:
      almacenista.CargarArchivoTransaccion();
      pausa();
      break;
    case MOSTRARTRANSACCION:
      almacenista.MostrarTransaccion();
      pausa();
      break;
    case IMPRIMIRTRANSACCIONES:
      almacenista.ImprimirTransacciones();
      pausa();
      break;
    case COMPARARINVENTRANS:
      iIdInventario = SolicitudIdInvent( almacenista.CantInventarios());
      if ( iIdInventario != -1 ){
        almacenista.CompararInvenTrans(iIdInventario);
        pausa();
      }
      break;
      case IMPRIMIRORDENCOMPRAS:
        iIdInventario = SolicitudIdInvent( almacenista.CantInventarios());
        if ( iIdInventario != -1 ){
          system("clear");
          almacenista.OrdenCompra(iIdInventario);
          pausa();
        }
        break;
    case SALIR:
      bInProgram = false;
      Mensaje("H A S T A  P R O N T O");
      break;
    default:
      Mensaje("Opcion invalida, intente de nuevo");
      //   pausa();
      break;
    } // switch
  }   // while
  // endwin();
  return 0;
} // main
//******************************************************************************


// Hace una pausa para que el usuario pueda verificar los mensajes en pantalla
// y espera a que el usuario presione la letra c
//******************************************************************************
void pausa() {
  cout << endl << "Presione \"c\" para continuar." << endl;
  cout << ">>> " << flush;
  cin.clear();
  while (cin.get() != 'c') {
    // if (!cin)
    cin.clear();
  } // while
} // pausa
//******************************************************************************


// Imprime un mensaje con un marco que lo resalta, debe recibir  un string
// con el mensaje que se quiere imprimir en la pantalla
//******************************************************************************
void Mensaje(string sMensaje) {
  system("clear");
  // se calcula el centro de la siguiente forma
  // z = tamano total
  // x = tamano del marco
  // y = tamano del area a rellenar
  // r = espacio en blanco del area a rellenar
  // sMensaje.length es el largo de la cadena a escribir
  // z = 2x + y
  // y = sMensaje.length + 2r
  //  |----------------------z------------------------|
  //  |--x---||----------------y--------------||---x--|
  //          |--r--||----mensaje-----||--r---|

  int z = 51;
  string marco = "****";
  int y = z - marco.length();
  int r = (y - sMensaje.length()) / 2;
  int r2;
  if (sMensaje.length() % 2 == 0) {
    r2 = r + 1;
  } else
    r2 = r;

  // cout << z << endl << y << endl << r << endl << sMensaje.length() << endl;
  cout << right;
  cout << setfill('*') << setw(z) << "*" << endl;
  cout << setfill(' ');
  cout << marco << setw(y) << marco << endl;
  cout << marco << setw(r) << " " << sMensaje << setw(r2) << marco << endl;
  cout << marco << setw(y) << marco << endl;
  cout << setfill('*') << setw(z) << "*" << endl;

  pausa();
  system("clear");
} // mensaje
//******************************************************************************

//Imprime una pantalla de Bienvenida o logo de sistema
//******************************************************************************
void Bienvenida(){
  system("clear");
  cout<< "***************************************************************\n";
  cout<< "***************************************************************\n";
  cout<< "***************************************************************\n";
  cout<< "****                                                       ****\n";
  cout<< "****    ****  *  **** *********** *   *     *              ****\n";
  cout<< "****    *     *  *       *   *    ** **    **              ****\n";
  cout<< "****    ****  *  ****    *   ***  * * *   * *              ****\n";
  cout<< "****       *  *     *    *   *    *   *  ****              ****\n";
  cout<< "****    ****  *  ****    *   **** *   * *   *              ****\n";
  cout<< "****                                                       ****\n";
  cout<< "****                I N V E N T A R I O                    ****\n";
  cout<< "****                                                       ****\n";
  cout<< "****                           ***** **** **** *           ****\n";
  cout<< "****                           *     *  * *    **          ****\n";
  cout<< "****          *  * **** *****  *     *  * **** * *         ****\n";
  cout<< "****          *  * *  * *   *  *     *  *    * ****        ****\n";
  cout<< "****          **** *  * ****** ***** **** **** *   *       ****\n";
  cout<< "****                                                       ****\n";
  cout<< "***************************************************************\n";
  cout<< "***************************************************************\n";
  cout<< "***************************************************************\n";
}// Bienvenida
//******************************************************************************


int SolicitudIdInvent(int iCantInventarios){
  int iIdInventario;
  int salida;
  cout << endl << "Indique el id del inventario: ";
  cin >> iIdInventario;

  if((iIdInventario < 0) || (iIdInventario > (iCantInventarios - 1))){
    Mensaje( "Error en id de inventario");
    salida = -1;
  } else {
    salida = iIdInventario;
  }
  return salida;
}
