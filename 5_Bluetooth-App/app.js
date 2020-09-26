const listBT = document.getElementById("list-BT");
const deg_0 = document.getElementById("0_deg");
const deg_90 = document.getElementById("90_deg");

listBT.addEventListener('click', function (event) {
    event.preventDefault();    
    console.log("List BT clicked");
    navigator.bluetooth.requestDevice({
        filters: [{
            name: 'HC-05'
          }], optionalServices: ['battery_service']
      })
      .then(device => { /* ... */ })
      .catch(error => { console.log(error); });
    
});

deg_0.addEventListener('click', function (event) {
    event.preventDefault(); 
    console.log("0 degrees clicked");
    navigator.bluetooth.requestDevice({
        acceptAllDevices: true
    })
    .then(device => {
        console.log('> Name:             ' + device.name);
        console.log('> Id:               ' + device.id);
        console.log('> Connected:        ' + device.gatt.connected);
  })
  .catch(error => {
    console.log('Argh! ' + error);
  });
})

deg_90.addEventListener('click', function (event) {
    event.preventDefault();    
    console.log("90 degrees clicked");
})

/*
function connectBT() {
    chrome.permission.request({
        permissions: ['tabs'], origins: ['http://www.google.com/']}, function(granted) {
            if (granted) {
                navigator.bluetooth.requestDevice({ filters: [{ services: ['battery_service'] }] })
                .then(device => {
                    // Human-readable name of the device.
                    console.log(device.name);

                    // Attempts to connect to remote GATT Server.
                    return device.gatt.connect();
                })
                .then(server => { })
                .catch(error => { console.log(error); });
            } else {
                alert("Permission not granted: Sorry !!!")
            }
          
        });
} */