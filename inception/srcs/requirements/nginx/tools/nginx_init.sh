#!/bin/sh

envsubst '\$TLS_KEY \$TLS_CRT \$DOMAIN_NAME' \
		< default \
		> /etc/nginx/sites-available/default

exec "$@"