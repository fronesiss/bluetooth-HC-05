

/*
 * 
vcc --- 3.3v o 5v (arduino)
gnd --- gnd  (arduino)
tx --- pin 10
rx --- pin 11

 // 1=1200 , 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
*/



#include <SoftwareSerial.h>

// Crear un nuevo objeto SoftwareSerial
//             Establece otro cuerpo de comunicación serial: nuevos pines RX  y TX 
SoftwareSerial BT1(10, 11); // RX | TX

void setup(){
  
    Serial.begin(38400); // Siempre tiene que estar configurado a esta velocidad
    BT1.begin(38400);
    Serial.println("Esperando comandos AT:");

  }
 
void loop()
  {  
     if (BT1.available())
        Serial.write(BT1.read());
        
     if (Serial.available())
        BT1.write(Serial.read());   
  }

  /*AT
   * 
Test de comunicación
PONER EL MONITOR SERIAL A 38400 BAUDIOS

Lo primero es comprobar si nuestro bluetooth responde a los comandos AT

Enviar: AT

Recibe: OK

Si recibimos como respuesta un OK entonces podemos continuar, sino verificar las conexiones o los pasos anteriores.

 

Cambiar nombre de nuestro módulo HC-05
Por defecto nuestro bluetooth se llama “HC-05” esto se puede cambiar con el siguiente comando AT

Enviar: AT+NAME=<Nombre>   Ejm: AT+NAME=Robot

Respuesta: OK     

 

Cambiar Código de Vinculación
Por defecto viene con el código de vinculación (Pin) “1234”, para cambiarlo hay que enviar el siguiente comando AT

Enviar: AT+PSWD=<Pin>   Ejm: AT+PSWD=2560

Respuesta: OK

Se puede saber cuál es el pin actual de nuestro modulo, para eso hay que enviar el siguiente comando: AT+ PSWD?   

 

Configurar la velocidad de comunicación:
La velocidad por defecto es de 9600 baudios, con Stop bit =0 (1 bit de parada), y sin Paridad, para cambiar estos parámetros, se hace uso del siguiente comando AT:

Enviar: AT+UART=<Baud>,< StopBit>,< Parity>

Respuesta: OK

Donde :

< Baud > equivale a una velocidad, los valores pueden ser: 4800, 9600, 19200, 38400, 57600, 115200, 23400, 460800, 921600 o 1382400.

< StopBit> es el Bit de parada, puede ser 0 o 1, para 1 bit o 2 bits de parada respectivamente, Para aplicaciones comunes se trabaja con 1 bit por lo que este parámetro normalmente se lo deja en 0.

< Parity> Es la paridad, puede ser 0 (Sin Paridad), 1 (Paridad impar) o 2 (Paridad par). Para aplicaciones comunes no se usa paridad, por lo que se recomienda dejar este parámetro en 0.


Ejemplo:

 Enviar:         AT+UART=9600,0,0

 Respuesta: OK

Se puede saber cuál es la configuración actual, para eso hay que enviar el siguiente comando: AT+UART?

 

Configurar el Role: para que trabaje como Maestro o Esclavo
Por defecto nuestro HC-05 viene como esclavo, el Siguiente comando nos permite cambiar esto:

Enviar: AT+ROLE=<Role> Ejm: AT+ROLE=0

Respuesta: OK    

Donde:<Role> 

0 -> Esclavo

1 -> Maestro

Para saber cuál es la configuración actual, enviar el siguiente comando: AT+ ROLE?

 

Configurar el modo de conexión (cuando se trabaja como maestro)
Esta configuración aplica para cuando el modulo está trabajando como maestro, el modulo necesita saber si se va a conectar con un dispositivo en particular o con cualquiera que esté disponible.

Enviar: AT+CMODE=<Mode>  Ejm: AT+CMODE=1

Respuesta: OK    

Donde: < Mode > 

0 -> Conectarse a un dispositivo con la dirección especificada(Se utiliza otro comando AT para especificar esta dirección).

1 -> conectar el módulo a cualquier dirección disponible(aleatorio).

Enviar el siguiente comando para averiguar el modo actual de conexión: AT+ CMODE?

 

Especificar la dirección del dispositivo al cual nos vamos a conectar
Esta configuración aplica cunado nuestro modulo está configurado como maestro, y a la vez el modo de conexión está en 0  (CMODE=0) 
el cual indica que nos vamos a conectar al dispositivo esclavo en particular. Para especificar la dirección al cual nos vamos a conectar 
se usa el siguiente comando AT

Enviar: AT+BIND=<Address>
Respuesta: OK

Donde:

< Address > Es la dirección del dispositivo al cual nos vamos a conectar, la dirección se envía de la siguiente forma: 1234,56,ABCDEF la cual equivale a la dirección 12:34:56:AB:CD:EF


Ejemplo:

Enviar: AT+BIND=E668,46,9277F2

Respuesta: OK

Para ver la dirección actual en este parámetro hay que enviar el siguiente comando: AT+ BIND?

   
Otros comandos AT de utilidad:
Obtener la versión del firmware:

Enviar: AT+VERSION?

Respuesta: +VERSION<Versión>   Resp Ej: +VERSION:2.0-20100601

Obtener la dirección de nuestro modulo bluetooth

Enviar: AT+ADDR?

Respuesta: +ADDR:<dirección>   Resp Ej: +ADDR: 98d3:31:2052e6

Resetear nuestro Modulo, después de hacer esto salimos del MODO AT

Enviar: AT+RESET

Respuesta: OK

Restablecer valores por defecto.

Enviar: AT+ORGL

Respuesta: OK

*Al hacer esto todos los parámetros del módulo se restablecen, a los valores por defecto de fábrica. En algunas versiones la velocidad cambia a 38400 baudios y en otros a 9600.

  */



