#!/bin/sh

envsubst '\$DB_NAME \$DB_USER \$DB_PASSWORD \$DB_ROOT_PASSWORD' \
		< db-init-template \
		> /etc/mysql/init.sql

cat /etc/mysql/init.sql
echo "???"
sleep 2

mysql_install_db

exec "$@"