#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:
  int8_t count = WiFi.scanNetworks();
  printf("Found %d networks\n", count);
  for (uint8_t i = 0; i < count; i++) {
    String ssid;
    uint8_t encryptionType;
    int32_t RSSI;
    uint8_t *BSSID;
    int32_t channel;
    WiFi.getNetworkInfo(i, ssid, encryptionType, RSSI, BSSID, channel);
    printf("ssid=%s\n", ssid.c_str());
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
