#!bin/sh

#===== openrc setup
# activation de openrc / désactivation du warning
openrc
touch /run/openrc/softlevel

#===== nginx setup
# creation d'un user pour acces ssh
# demarrage nginx
adduser -D -g 'www' www
chown -R www:www /var/lib/nginx
chown -R www:www /www
mkdir /run/nginx
chown -R nginx:nginx /run/nginx
chmod 775 /run/nginx
rc-service nginx start

#==== ssh setup
rc-service sshd start
