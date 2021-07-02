#!/usr/bin/env python

# python 3.8

import socket
import json

# arduino
RECEIVE_HOST = "0.0.0.0"
RECEIVE_PORT = 4003
BUFFER_SIZE = 1024
RECEIVE_SERVER = (RECEIVE_HOST, RECEIVE_PORT)

# unreal
SEND_HOST = '127.0.0.1'
SEND_PORT = 3003
SERVER = (SEND_HOST, SEND_PORT)

rot_status = False
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:

    s.bind(RECEIVE_SERVER)

    u = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    while True:
        msg, add = s.recvfrom(BUFFER_SIZE)
        u.sendto(msg, SERVER)

        msg_dict = json.loads(msg.decode())
        x = msg_dict['x']
        y = msg_dict['y']
        z = msg_dict['z']
        qx = msg_dict['qx']
        qy = msg_dict['qy']
        qz = msg_dict['qz']
        qw = msg_dict['qw']
        system = msg_dict['sys']
        gyro = msg_dict['gyro']
        accel = msg_dict['accel']
        mag = msg_dict['mag']

        if not rot_status:
            if system + gyro + accel + mag == 12:
                rot_status = True

        if not rot_status:
            print(f'sys={system}, gyro={gyro}, accel={accel}, mag={mag}')

        if rot_status:
            print('')
            print(f'x={x}, y={y}, z={z}')
            print(f'qx={qx}, qy={qy}, qz={qz}, qw={qw}')

            r = R.from_quat([qx, qy, qz, qw])
            rot_z, rot_y, rot_x = r.as_euler('zyx', degrees=True)
            print(f'{rot_x}, {rot_y}, {rot_z}')
