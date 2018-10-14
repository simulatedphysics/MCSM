FROM ubuntu:18.10
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y g++ git cmake nlohmann-json-dev libarmadillo-dev

COPY . /usr/local

WORKDIR /usr/local/

RUN cmake . && make

CMD ./MCSM ## docker build -t mcsm . && docker run mcsm