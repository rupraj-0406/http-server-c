# C HTTP Server

A modular HTTP server built from scratch in C using sockets.

## Features

- Supports GET, POST, DELETE, PATCH, HEAD
- Static file serving
- MIME type handling
- Logging with timestamps
- Modular architecture

## Build

make

## Run

./server

## Test

curl http://localhost:8080/
curl http://localhost:8080/index.html
curl -X POST http://localhost:8080/data -d "name=test"

## Project Structure

src/        -> source files  
include/    -> header files  
www/        -> static files  

## Author

Rupraj Roy (CS2523)
