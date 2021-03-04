FROM debian:buster

# global tools
RUN apt update -y && apt upgrade -y
RUN apt install wget -y
RUN apt install expect -y
RUN apt install vim -y
RUN apt install gpg -y
RUN apt install git -y

# port listening
EXPOSE 80/tcp
EXPOSE 80/udp

# ngix installation
RUN apt install nginx -y
ADD ./src/nginx_conf_on /var/
ADD ./src/nginx_conf_off /var/
ADD ./src/autoindex_off /bin/
ADD ./src/autoindex_on /bin/

# php installation
RUN apt install php -y
RUN apt install php-fpm -y
RUN apt install -y php-mysql php-json php-mbstring php-xml php-gd php-curl php-bcmath php-ldap \
php-cli  php-intl

# mysql installation (mariadb)
RUN apt install default-mysql-server -y
ADD ./src/mysql_secure_ab.exp /
ADD ./src/mysql_splugin_ab.exp /

# phpmyadmin installation
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
RUN tar xvf phpMyAdmin-5.1.0-all-languages.tar.gz
RUN mv phpMyAdmin-5.1.0-all-languages /usr/share/phpmyadmin
RUN rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz
RUN ln -s /usr/share/phpmyadmin /var/www/html/
ADD ./src/config.inc.php /usr/share/phpmyadmin/

# Wordpress installation
RUN wget -O /var/www/latest-fr_FR.tar.gz http://fr.wordpress.org/latest-fr_FR.tar.gz 
RUN tar -xzvf /var/www/latest-fr_FR.tar.gz
RUN mv /wordpress /var/www/html/
RUN rm -rf /var/www/latest-fr_FR.tar.gz
ADD ./src/wordpress_database.exp /
ADD ./src/wp-config.php /var/www/html/wordpress

# SSL configuration
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=FR/ST=75/L=Paris/CN=awer' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

# service management
ADD ./src/global_loader.sh /
CMD ./global_loader.sh && rm -rf global_loader.sh && /bin/bash
