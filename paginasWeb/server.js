var app = require('http').createServer(handler),
 io = require('socket.io').listen(app),
 fs = require('fs'),
 sys = require('util'),
  exec = require('child_process').exec,
  child;
//Escuchando en el puerto 8000
app.listen(8000);
//Si todo funciona, al abrir el navegador cargaremos el archivo index.html, de lo contrario un error
function handler(req, res) {
fs.readFile(__dirname+'/guia1.html', function(err, data) {
if (err) {
      //Si hay error, mandaremos un mensaje de error 500
console.log(err);
res.writeHead(500);
return res.end('Error cargando index.html');
}
res.writeHead(200);
res.end(data);
});
}
 
//Cuando abramos el navegador estableceremos una conexión con socket.io.
//Cada 2 segundos mandaremos a la gráfica un nuevo valor.
io.sockets.on('connection', function(socket) {
  setInterval(function(){

//Ejecutando el programa

    child = exec("/var/www/readTermo", function (error, stdout, stderr) {
    if (error !== null) {
      console.log('Error en medias : ' + error);
    } else {
      //Es necesario mandar el tiempo (eje X) y un valor de temperatura (eje Y).
      var date = new Date().getTime();
      var temp = parseFloat(stdout);
      socket.emit('temperatureUpdate', date, temp);
    }
  });}, 2000);
});


// leyendo el archivo de error
io.sockets.on('connection', function(socket) {
  setInterval(function(){
    child = exec("cat /var/www/error", function (error, stdout, stderr) {
    if (error !== null) {
      console.log('Error en lectura de error: ' + error);
    } else {
      var error = parseFloat(stdout);
      socket.emit('errorMedicion', error);
    }
  }

);}, 2000);
});


