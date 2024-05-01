FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=dev
ARG MYUID=1001
ARG MYGID=1001

RUN groupadd --gid $MYGID $USERNAME && useradd --uid $MYUID --gid $MYGID -m -s /bin/bash $USERNAME
RUN adduser $USERNAME sudo
RUN echo "$USERNAME:$USERNAME" | chpasswd

# Here you can install elementary tools that are used across backend, frontend, etc..
RUN \
        apt-get update; \
        apt-get -y install --fix-missing \
        chrpath \
        gawk \
        curl \
        git \
        bash-completion \
        vim \
        iputils-ping \
        sudo \
        plantuml
RUN \
    apt-get update; \
    apt-get -y install --fix-missing \ 
    cmake \
    clang-14 \
    libyaml-cpp-dev \
    libclang-dev \
    libclang-cpp-dev \
    libstdc++-10-dev 

RUN \
    apt-get update; \
    apt-get -y install --fix-missing \ 
    build-essential