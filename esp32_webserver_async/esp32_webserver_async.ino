// sumber: https://projecthub.arduino.cc/cetech11/implementing-web-server-on-esp32-5c24be
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
//const char* ssid = "ELDRADO"; // CHANGE IT
const char* ssid = "AP_NAME";
//const char* ssid = "TP-LINK_1A42";
const char* password = "AP_PASSWORD";  // CHANGE IT
AsyncWebServer server(80);
void setup() {
  Serial.begin(115200);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());
  // Define a route to serve the HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");                                    // for debugging
    request->send(200, "text/html", "<html><body><h1>Hello, ESP32!</h1></body></html>");
  });
  server.onNotFound([](AsyncWebServerRequest* request) {
    request->send(404);
  });
  // Start the server
  server.begin();
}
void loop() {}
