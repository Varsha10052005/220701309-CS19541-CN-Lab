import socket
import time
def ping_server(host='127.0.0.1',port=12345):
    with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as s:
        try:
            s.settimeout(2)
            start=time.time()
            s.sendto(b'ping',(host,port))
            data,addr=s.recvfrom(1024)
            end=time.time()
            print(f"Received {data.decode()} from {addr} in {end-start:.2f} seconds")
        except socket.timeall:
            print("Request timed out");
ping_server()
            
            
