FROM nginx:latest

USER root

COPY ./nginx/nginx.conf /etc/nginx/

RUN apt-get update && apt-get install -y \
    gcc \
    libfcgi-dev \
    spawn-fcgi && rm -rf /var/lib/apt/lists
WORKDIR /home/