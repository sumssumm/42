#!/bin/sh

cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
./wp-cli.phar core download --allow-root || echo "already downloads wordpress!"

for i in {30..0}; do
	if timeout 10s mysqladmin ping -h "${WP_HOST}" --silent; then
		break
	fi
	sleep 1
done

if [ "$i" = 0 ]; then
	echo >&2 'Failed'
	exit 1
fi

./wp-cli.phar config create --dbname=${DB_NAME} \
							--dbuser=${DB_USER} \
							--dbpass=${DB_PASSWORD} \
							--dbhost=${WP_HOST} \
							--allow-root || echo "wordpress already exists!"

./wp-cli.phar core install --url=${WP_URL} \
							--title=${WP_TITLE} \
							--admin_user=${WP_ADMIN_USER} \
							--admin_password=${WP_ADMIN_PASSWORD} \
							--admin_email=${WP_ADMIN_EMAIL} \
							--skip-email \
							--allow-root || echo "wordpress already installs!"

./wp-cli.phar user create	${WP_USER} \
							${WP_USER_EMAIL} \
							--user_pass="${WP_USER_PASSWORD}" \
							--role=author \
							--allow-root || echo "wordpress user already exists!"

exec "$@"
