FROM debian:buster

RUN apt update && apt upgrade -y && apt install -y \
	nginx \
	openssl

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
			-keyout /etc/nginx/ssl/nginx.key \
			-out /etc/nginx/ssl/nginx.crt \
			-subj "/CN=suminpar.42.fr"

COPY ./conf/default /etc/nginx/sites-available/.

CMD [ "nginx", "-g", "daemon off;" ]

