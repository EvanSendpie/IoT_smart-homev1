# IoT LED Control with ESP32 & LCD I2C

Proyek ini menggunakan ESP32 untuk mengontrol beberapa LED melalui WebServer dengan endpoint HTTP. Status LED dapat dipantau sekaligus diubah melalui request GET dan POST. Informasi koneksi WiFi juga ditampilkan pada LCD 16x2 dengan modul I2C.

---

## Fitur

- Kontrol 4 LED (ON/OFF) melalui endpoint HTTP.
- Mendukung GET (cek status LED) dan POST (ubah status LED).
- LCD 16x2 I2C untuk menampilkan status koneksi WiFi dan alamat IP ESP32.
- LED indikator default untuk status koneksi WiFi.

---

## Hardware yang Dibutuhkan

- ESP32
- LCD 16x2 + Modul I2C (alamat default 0x27)
- 4 buah LED + resistor (misal 330Ω – 1kΩ)
- Breadboard & jumper wire
- Power supply ESP32 (USB atau adaptor 5V)

---

## Pinout
- Komponen	Pin ESP32
- LCD I2C SDA	GPIO 21
- LCD I2C SCL	GPIO 22
- LED Default	GPIO 2
- LED 1	GPIO 4
- LED 2	GPIO 5
- LED 3	GPIO 18
- LED 4	GPIO 19

---

## Library yang Digunakan

Pastikan sudah install library berikut di Arduino IDE:
- Wire.h
- LiquidCrystal_I2C.h
- WiFi.h (sudah bawaan ESP32 core)
- WebServer.h (sudah bawaan ESP32 core)

---

## Cara Menggunakan

1. Clone repository ini:
``` bash
git clone https://github.com/EvanSendpie/IoT_smart-homev1.git
```

2. Buka kode di Arduino IDE atau PlatformIO.

3. Ubah SSID & Password WiFi sesuai jaringanmu:
```
const char* ssid = "(SSID anda)";
const char* password = "(Password anda)";
```

4. Upload ke board ESP32.

5. Setelah terhubung, cek Serial Monitor atau LCD untuk melihat alamat IP ESP32.

6. Akses endpoint berikut:
```
GET /satu → Status LED1
POST /satu → Toggle LED1
GET /dua → Status LED2
POST /dua → Toggle LED2
GET /tiga → Status LED3
POST /tiga → Toggle LED3
GET /empat → Status LED4
POST /empat → Toggle LED4
```

7. Akses via browser
```
http://(IP anda):(port anda)/
```
