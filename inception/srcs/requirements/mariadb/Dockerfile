FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y \
	mariadb-server \
	gettext

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY ./tools/db-init-template.sql .
COPY ./tools/db-install.sh .

RUN mkdir /run/mysqld && chmod +x db-install.sh

EXPOSE 3306

ENTRYPOINT [ "./db-install.sh" ]

CMD [ "mysqld_safe" ]
