#!/bin/sh

envsubst '\$DB_NAME \$DB_USER \$DB_PASSWORD \$DB_ROOT_PASSWORD' \
		< db-init-template.sql \
		> /etc/mysql/init.sql

sleep 2

mysql_install_db

exec "$@"