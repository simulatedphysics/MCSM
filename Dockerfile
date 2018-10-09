FROM ubuntu:18.10
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y g++ git cmake
COPY . /usr/local
WORKDIR /usr/local/cmake-build-debug
