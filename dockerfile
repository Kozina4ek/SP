FROM ubuntu
MAINTAINER iaa_738
COPY ../ .
RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y binutils
RUN apt-get update
RUN apt-get install -y gcc-multilib
WORKDIR /Lab2
