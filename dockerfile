FROM alpine
MAINTAINER Ivanova Alina
RUN apk update && apk upgrade && apk add vim && apk add bash
WORKDIR /lab1
COPY ../ .
