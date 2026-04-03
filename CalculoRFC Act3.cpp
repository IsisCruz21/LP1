/******************************************************************************

Programa: Cálculo de RFC
Autor: isis Cruz
Fecha: 31/marzo/2026

*******************************************************************************/
#include <iostream>
#include <vector> 
#include <string>

// Directorio de palabras NO permitidas
const std::vector<std::string> palabrasProhibidas = {
    "PENE", "VAGO", "LOCO", "PEDO", "MEON", "PUTA", "PUTO", "MOCO", "CULO", "QULO", "RATA","RUIN", "CACA","COGE","MAMO","FETO","MAMO","JOTO"
};
// Verificar y modificar palabras prohibidas del Diccionario
std::string corregirRFC(const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0,3) + "x"; //remplaza la ultima letra por una 'X'
        }
    }
    return rfc;
}
//Función para obtener la primera vocal inter de una cadena
char obtenerPrimeraVocalInterna(const std::string& str ) {
    for (size_t i = 1; i< str.length(); ++i) {
        char c= str [i];
        if (c == 'A'|| c == 'E'|| c =='I'|| c== 'O'||c =='U')
        return c;
    }
    return 'x';//Si no se encuentra ninguna vocal interna, se usa una x
}
//Función principal para calcular el RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno,const std::string& apellidoMaterno, const std::string& fechaNacimiento){    

         // Se declara la variable donde guardaremos el RFC 
         std::string rfc;
         
         //se obtienen la letra inicial y la primera vocal interna del apellido apellidoPaterno
         char letraInicial = apellidoPaterno [0];
         char primeraVocalInterna = obtenerPrimeraVocalInterna (apellidoPaterno);
         
         // Se obtiene la inicial del apellido materno o se usa una Letra 'X' si no tiene
        char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
        
        // Se obtiene la inicial del primer nombre o se usa una 'X' si no hay
        char inicialNombre = nombre[0];
        
        //Se obtiene los dos ultimos dígitos del año de fechaNacimiento
        std::string anio = fechaNacimiento.substr(2,2);
        
        // Se obtiene el mes y el dia de nacimiento
        std::string mes = fechaNacimiento.substr(5,2);
        std::string dia = fechaNacimiento.substr(8,2);
        
        // Se construye el RFC sumando el texto de la información proporcionada
        rfc = letraInicial;
        rfc += primeraVocalInterna;
        rfc += inicialApellidoMaterno;
        rfc += inicialNombre;
        
        // Aqui se ejecuta la comparación de las palabras que podrian ser no  convenientes y se realiza el cambio por la letra 'X'
        rfc = corregirRFC(rfc);
        
        // Realizaada la corrección se continua creando el RFC
        
        rfc += anio;
        rfc += mes;
        rfc +=dia;
        return rfc;
        
}

int main () {
    // Despliega en consola los pasos a seguir y se espera que los datos se introduzcan en MAYÚSCULA
    
    std::string nombre , apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout <<"Introduce tu nombre: ";
    std::getline (std::cin, nombre);
    std::cout <<"Introduce tu Apellido Paterno: ";
    std::getline (std::cin, apellidoPaterno);
    std::cout <<"Introduce tu Apellido Materno: ";
    std::getline (std::cin, apellidoMaterno);
    std::cout <<"Introduce la Fecha de Nacimiento en el formato (YYYY/MM/DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre,apellidoPaterno,apellidoMaterno,fechaNacimiento);
    std::cout <<"RFC: "<< rfc << std::endl;
    
    return 0;
    
}
