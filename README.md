# os181-1

Repository ini berisi panduan, tips dan trik mengerjakan demo, dan tutorial menjalankan demo pada Ubuntu container dan WSL.

## Collaborators:
IIT (Ketua)

AII (Wakil Ketua 1)

NSP (Wakil Ketua 2)

RM (Wakil Ketua 3)

MIM (Wakil Ketua 4) - mahenbal

ZA (Wakil Ketua 5)

SA (Wakil Ketua 6)

TA (Wakil Ketua 7)

MGW (Wakil Ketua 8)

MIK (Wakil Ketua 9)

BA (Wakil Ketua 10)

SMS (Wakil Ketua 11)

MHP (Wakil Ketua 12) - hanifalc

MA (Wakil Ketua 13)

ISF (Wakil Ketua 15)

RL (Wakil Ketua 16)

RPS (Wakil Ketua 14)

## Demo Descriptions and Related OS Materials

#### Demo W00
**Demo Description**: Try running makefile on Badak server
(Makefile consists of commands to compile the C program, and remove the executable file (clean))

**Related OS Material**: A little introduction to C language and scripting

#### Demo W01
notes by RL: di wsl, jika program tidak berjalan karena command "\r", ada 3 opsi solusi untuk memecahkan permasalahan ini: (pilih salah satu saja)

**opsi 1: dos2unix**

a. masukkan command "sudo apt-get install dos2unix"

b. masukkan command "dos2unix [file]" untuk setiap [file]

c. jalankan seperti biasa, yaitu "bash [file]"

**opsi 2: mengganti semua error dari "\r"**

masukkan command "sed -i.bak 's/\r$//' [file]

**opsi 3: git essential**

masukan perintah sudo apt-get update, lalu sudo apt-get install build-essential, lalu sudo apt-get install git-core, lalu sudo apt upgrade.

jika masih tidak berjalan, coba restart untuk update** (bisa berkali-kali restart)
#### Demo W02
#### Demo W03
#### Demo W04
#### Demo W05
#### Demo W06
#### Demo W07
#### Demo W08
#### Demo W09
#### Demo W10
