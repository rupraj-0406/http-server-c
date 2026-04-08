# HTTP Server in C

An HTTP server built in C using socket programming.
This project demonstrates how HTTP servers work internally by implementing request parsing, routing, static file serving, and a simple file-based backend system.

---

## Features

* Supports HTTP methods: GET, POST, PATCH, DELETE, HEAD
* Custom routing system
* Logging with timestamps
* File-based CRUD system (data.txt)
* Makefile for build automation

---

## Project Structure

```
c-http-server/
│
├── src/            # Source files
├── include/        # Header files
├── www/            # Static files
├── tests/          # Test scripts
│
├── Makefile
├── README.md
└── data.txt
```

---

## Build

```
make
```

---

## Run

```
./server
```

---

## Testing

Start server in one terminal:

```
./server
```

Run tests in another terminal:

```
./tests/test_requests.sh
```

Or test manually:

```
curl http://localhost:8080/
curl http://localhost:8080/index.html
curl -X POST http://localhost:8080/data -d "name=rupraj"
curl http://localhost:8080/data
curl -X PATCH http://localhost:8080/data -d "name=updated"
curl -X DELETE http://localhost:8080/data
```

---

## API Endpoints

GET / → Serve index.html
GET /hello → Test route
GET /data → Fetch stored data

POST /data → Store data
PATCH /data → Update data
DELETE /data → Delete data
HEAD / → Return headers only

---

## How It Works

Client → Socket → Parser → Router → Handler → Response

* Socket: Handles TCP connection
* Parser: Extracts method, path, body
* Router: Routes request
* File Handler: Serves static files
* Logger: Logs requests

---

## Author

Rupraj Roy(CS2523)
