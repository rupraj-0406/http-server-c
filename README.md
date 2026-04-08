# C HTTP Server

A HTTP server built from scratch in C.

## Features

- Supports GET, POST, DELETE, PATCH, HEAD
- Static file serving
- Logging with timestamps

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
