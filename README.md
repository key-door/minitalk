# Minitalk

Minitalk is a program that facilitates communication between a client and a server.

## Usage

Prepare two terminals.

1. In one terminal, execute:
```./server```
2. The server will output a PID (Process ID). Use this PID to send a string from the client side.
3. To send a message, use the following format in the other terminal: 
```./client {PID} {string}```

Replace `{PID}` with the outputted Process ID and `{string}` with the message you wish to send.
