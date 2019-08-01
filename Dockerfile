FROM fedora:latest

RUN sudo yum install -y tesseract-devel leptonica-devel make automake gcc gcc-c++ parallel

ADD . /home/workspace/tesslinesplit
RUN cd /home/workspace/tesslinesplit && make install

VOLUME /data
WORKDIR /data
