FROM ubuntu:18.10
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y g++ git cmake nlohmann-json-dev libarmadillo-dev libssl-dev libboost1.67-all-dev nano

RUN mkdir /deps && cd /deps && git clone https://gitlab.com/eidheim/Simple-WebSocket-Server.git && cd Simple-WebSocket-Server && cmake . && make install

COPY . /usr/local

WORKDIR /usr/local/



CMD sleep infinity ### cmake . && make && ./MCSM ## docker build -t mcsm . && docker run mcsm