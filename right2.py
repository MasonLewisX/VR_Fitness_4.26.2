#!/usr/bin/env python

# python 3.8

import socket

# arduino
RECEIVE_HOST = "0.0.0.0"
RECEIVE_PORT = 4005
BUFFER_SIZE = 1024
RECEIVE_SERVER = (RECEIVE_HOST, RECEIVE_PORT)

# unreal
SEND_HOST = '127.0.0.1'
SEND_PORT = 3005
SERVER = (SEND_HOST, SEND_PORT)

message = None
address = None

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:

    s.bind(RECEIVE_SERVER)
    print('UDP server listening to Right2')

    u = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    while True:

        message, address = s.recvfrom(BUFFER_SIZE)
        print(message)

        u.sendto(message, SERVER)
