FROM debian:bullseye

ARG TLS_KEY_DIR
ARG TLS_KEY
ARG TLS_CRT
ARG TLS_SUBJ

RUN apt update && apt upgrade -y && apt install -y \
	nginx \
	openssl \
	gettext

RUN mkdir -p ${TLS_KEY_DIR}

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
			-keyout ${TLS_KEY} \
			-out ${TLS_CRT} \
			-subj "$TLS_SUBJ"

COPY ./conf/default .
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/nginx_init.sh .

RUN chmod +x nginx_init.sh

EXPOSE 443

ENTRYPOINT [ "./nginx_init.sh" ]

CMD [ "nginx", "-g", "daemon off;" ]
