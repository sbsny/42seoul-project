sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" /etc/php8/php-fpm.d/www.conf

if [ ! -f wp-config.php &>/dev/null ]; then
	wp config create --dbhost=$DB_HOST \
					 --dbname=$DB_NAME \
					 --dbuser=$DB_USER \
					 --dbpass=$DB_PASS
fi

if ! wp core is-installed &>/dev/null; then
	wp core install --url=$WP_URL \
					--title=$WP_TITLE \
					--admin_user=$WP_ADMIN_NAME \
					--admin_password=$WP_ADMIN_PASS \
					--admin_email=$WP_ADMIN_EMAIL \
					--skip-email
fi

if ! wp user get $WP_USER_NAME &>/dev/null; then
	wp user create $WP_USER_NAME $WP_USER_EMAIL \
					--user_pass=$WP_USER_PASS \
					--role=$WP_USER_ROLE
fi

php-fpm8 --nodaemonize
