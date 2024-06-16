FROM debian:buster

RUN apt update && apt upgrade -y && apt install -y \
	php7.3 \
	php-fpm \
	php-cli \
	wget \
	php-mbstring \
	php-xml \
	sendmail \
	php-mysqli \
	curl \
	vim \
	mariadb-client

RUN mkdir -p /run/php

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/.
COPY ./tools/wp-init.sh .

RUN chmod +x wp-init.sh

ENTRYPOINT [ "./wp-init.sh" ]

CMD [ "php-fpm7.3", "-F" ]
