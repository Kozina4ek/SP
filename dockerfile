FROM debian
RUN apt-get update 
RUN apt-get install -y g++
RUN apt-get install -y vim
RUN apt-get install -y gdb
WORKDIR /lab3
COPY ./main.cpp .
RUN g++ ./main.cpp

