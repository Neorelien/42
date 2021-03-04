#!/bin/bash

# start services
service nginx start

service php7.3-fpm start

service mysql start

rm -rf /etc/nginx/sites-available/default

# mysql initialisation
chmod 100 mysql_secure_ab.exp

/mysql_secure_ab.exp

rm -rf mysql_secure_ab.exp

chmod 100 mysql_splugin_ab.exp

/mysql_splugin_ab.exp

rm /mysql_splugin_ab.exp

/wordpress_database.exp

rm -rf wordpress_database.exp

# autoindex initialisation
rm /var/www/html/index*

autoindex_on
