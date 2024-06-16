FROM debian:buster

RUN apt update && apt upgrade -y && apt install -y \
	mariadb-server \
	vim \
	gettext

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY ./tools/db-init-template .
COPY ./tools/db-install.sh .
COPY ./conf/my.cnf /etc/my.cnf

RUN mkdir /run/mysqld && chmod +x db-install.sh

ENTRYPOINT [ "./db-install.sh" ]

CMD [ "mysqld_safe" ]
