FROM debian:buster

RUN apt update && apt upgrade -y && apt install -y \
	mariadb-server \
	vim

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY ./tools/db-init.sql /etc/mysql/init.sql
COPY ./tools/db-install.sh .

RUN mkdir /run/mysqld && chmod +x db-install.sh

ENTRYPOINT [ "./db-install.sh" ]

CMD [ "mysqld_safe" ]
