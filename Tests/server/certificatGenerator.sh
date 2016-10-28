#!/bin/sh

rm -rf ./cert/
mkdir cert
sudo openssl genrsa -out ./cert/server.key 2048
sudo openssl req -new -key ./cert/server.key -out ./cert/server.csr
openssl req -text -noout -in ./cert/server.csr
sudo openssl x509 -req -days 365 -in ./cert/server.csr -signkey ./cert/server.key -out ./cert/server.crt
sudo openssl x509 -req -days 365 -outform PEM -in ./cert/server.csr -signkey ./cert/server.key -out ./cert/server.pem
