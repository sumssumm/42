FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y \
	php \
	php-fpm \
	php-cli \
	wget \
	php-mbstring \
	php-xml \
	php-mysqli \
	curl \
	mariadb-client

RUN mkdir -p /run/php

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/.
COPY ./tools/wp-init.sh .

RUN chmod +x wp-init.sh

EXPOSE 9000

ENTRYPOINT [ "./wp-init.sh" ]

CMD [ "php-fpm7.4", "-F" ]
